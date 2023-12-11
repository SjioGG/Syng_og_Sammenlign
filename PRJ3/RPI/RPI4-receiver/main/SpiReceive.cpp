#include <bcm2835.h>  // Inkluderer BCM2835 biblioteket for at bruge Raspberry Pi's GPIO og SPI funktioner.
#include <iostream>   // Inkluderer standard input/output biblioteket for C++.
#include <fstream>    // Inkluderer biblioteket til filhåndtering i C++.
#include <chrono>     // Inkluderer biblioteket til at måle tid i C++.
#include <ncurses.h>  // Inkluderer ncurses biblioteket for at håndtere tastaturinput uden standard I/O buffering.

// Globale konstanter og variabler.
const std::string OUTPUT_FILENAME = "PSOC.wav";  // Definerer navnet på den output WAV-fil, der vil blive oprettet.
const int DATA_PACKET_SIZE = 4;                  // Angiver antallet af datapakker, der skal modtages i hver cyklus.
const int SPI_BUFFER_SIZE = DATA_PACKET_SIZE * 2;// Størrelsen på SPI-bufferen, baseret på antallet af datapakker.
const uint16_t HANDSHAKE_SIGNAL = 0xFFFF;        // Definerer et handshake signal, som bruges til at synkronisere kommunikationen.

// WAVHeader struktur definerer headerformatet for en WAV fil.
struct WAVHeader 
{
    // Initialiserer headerens forskellige felter.
    char riffHeader[4] = { 'R', 'I', 'F', 'F' }; // Standard 'RIFF' header for WAV filer.
    uint32_t wavSize;                            // Størrelsen på WAV filen minus 8 bytes.
    char waveHeader[4] = { 'W', 'A', 'V', 'E' }; // 'WAVE' format identifikator.
    char fmtHeader[4] = { 'f', 'm', 't', ' ' };  // 'fmt ' sub-chunk header.
    uint32_t fmtChunkSize = 16;                  // Størrelsen på 'fmt ' sub-chunk (16 for PCM).
    uint16_t audioFormat = 1;                    // Lydformat (1 for PCM).
    uint16_t numChannels = 1;                    // Antal kanaler (1 for mono).
    uint32_t sampleRate;                         // Samplingfrekvens.
    uint32_t byteRate;                           // Byte rate (SampleRate * NumChannels * BitsPerSample/8).
    uint16_t blockAlign;                         // Block align (NumChannels * BitsPerSample/8).
    uint16_t bitsPerSample;                      // Antal bits pr. sample (typisk 16 eller 24).
    char dataHeader[4] = { 'd', 'a', 't', 'a' }; // 'data' sub-chunk header.
    uint32_t dataChunkSize;                      // Størrelsen på data sub-chunk.
};

// writeWAVHeader funktionen skriver headeren til WAV filen.
void writeWAVHeader(std::ofstream& file, int sampleRate, int bitsPerSample, int numChannels, uint32_t numSamples) 
{
    // Implementering af WAV header opdatering.
    WAVHeader header;
    header.sampleRate = sampleRate;
    header.bitsPerSample = bitsPerSample;
    header.numChannels = numChannels;
    header.byteRate = header.sampleRate * header.numChannels * header.bitsPerSample / 8;
    header.blockAlign = header.numChannels * header.bitsPerSample / 8;
    header.dataChunkSize = numSamples * header.numChannels * header.bitsPerSample / 8;
    header.wavSize = 4 + (8 + header.fmtChunkSize) + (8 + header.dataChunkSize);
    
    // Skriver headeren til filen.
    file.seekp(0, std::ios::beg);
    file.write(reinterpret_cast<const char*>(&header), sizeof(header));
}

// updateWAVHeader funktionen opdaterer WAV filens header med den korrekte data størrelse.
void updateWAVHeader(std::ofstream& file, uint32_t numSamples) 
{
    // Opdaterer dataChunkSize og wavSize i WAV-headeren.
    uint32_t dataChunkSize = numSamples * sizeof(uint16_t);
    uint32_t wavSize = 4 + (8 + 16) + (8 + dataChunkSize) - 8;
    
    // Opdaterer dataChunkSize og wavSize i filen.
    file.seekp(40, std::ios::beg);
    file.write(reinterpret_cast<const char*>(&dataChunkSize), sizeof(dataChunkSize));
    
    file.seekp(4, std::ios::beg);
    file.write(reinterpret_cast<const char*>(&wavSize), sizeof(wavSize));
}

// Hovedfunktionen styrer hele optagelsesprocessen.
int main() 
{
    // Initialiserer ncurses for at håndtere tastaturinput.
    initscr(); // Starter curses mode.
    noecho();  // Slår echo af input fra.
    cbreak();  // Line buffering slået fra, passér hver input til programmet.
    timeout(0); // Non-blocking input mode.

    // Initialiserer BCM2835 biblioteket for at bruge Raspberry Pi's GPIO og SPI funktioner.
    if (!bcm2835_init()) {
        endwin();
        std::cerr << "BCM2835 init ERROR." << std::endl;
        return -1;
    }

    // Starter SPI kommunikationen.
    if (!bcm2835_spi_begin()) {
        bcm2835_close();
        endwin();
        std::cerr << "SPI init ERROR." << std::endl;
        return -1;
    }

    // Konfigurerer SPI-indstillingerne.
    bcm2835_spi_setBitOrder(BCM2835_SPI_BIT_ORDER_MSBFIRST); // MSB først for dataoverførsel.
    bcm2835_spi_setDataMode(BCM2835_SPI_MODE0);              // SPI mode 0.
    bcm2835_spi_setClockDivider(125);                        // Sætter SPI clock divider.
    bcm2835_spi_chipSelect(BCM2835_SPI_CS0);                 // Vælger SPI chip (CS0).
    bcm2835_spi_setChipSelectPolarity(BCM2835_SPI_CS0, LOW); // CS0 er aktiv ved lav signal.

    // Åbner output filen for at skrive data.
    std::ofstream outputFile(OUTPUT_FILENAME, std::ios::binary | std::ios::out | std::ios::in);
    if (!outputFile.is_open()) {
        bcm2835_spi_end();
        bcm2835_close();
        endwin();
        std::cerr << "Cannot open file." << std::endl;
        return -1;
    }

    // Skriver en initial WAV-header til filen.
    writeWAVHeader(outputFile, 44100, 16, 1, 0);
    uint32_t numSamples = 0;
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

    // Hovedløkke til indsamling af data og styring af optagelse.
    while (true) 
    {
        // Læser input fra brugeren.
        int ch = getch();
        if (ch == 's') break; // Stopper optagelsen hvis 's' trykkes.

        // Håndtering af handshake signal.
        uint8_t handshakeBuffer[2];
        bcm2835_spi_transfern((char*)handshakeBuffer, 2);
        uint16_t handshakeSignal = static_cast<uint16_t>(handshakeBuffer[0]) << 8 | handshakeBuffer[1];
        
        // Hvis handshake er korrekt, læs data og skriv til fil.
        if (handshakeSignal == HANDSHAKE_SIGNAL) {
            for (int i = 0; i < DATA_PACKET_SIZE; i++) {
                uint8_t spiBuffer[SPI_BUFFER_SIZE];
                bcm2835_spi_transfern((char*)spiBuffer, SPI_BUFFER_SIZE);
                uint16_t data = static_cast<uint16_t>(spiBuffer[0]) << 8 | spiBuffer[1];
                outputFile.write(reinterpret_cast<const char*>(&data), sizeof(data));
                numSamples++;
            }
        }

        // Opdaterer WAV-headeren regelmæssigt.
        std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
        if (std::chrono::duration_cast<std::chrono::seconds>(now - start).count() >= 1) {
            updateWAVHeader(outputFile, numSamples);
            start = now;
        }
    }

    // Efter optagelse, opdater og luk filen.
    updateWAVHeader(outputFile, numSamples);
    outputFile.close();

    // Lukker SPI og BCM2835 biblioteket.
    bcm2835_spi_end();
    bcm2835_close();

    // Afslutter ncurses mode.
    endwin();

    return 0;
}