#include <bcm2835.h>  // Inkluderer BCM2835 biblioteket for at bruge Raspberry Pi's GPIO og SPI funktioner.
#include <iostream>   // Inkluderer standard input/output biblioteket for C++.
#include <fstream>    // Inkluderer biblioteket til filhåndtering i C++.
#include <ncurses.h>  // Inkluderer ncurses biblioteket for at håndtere tastaturinput uden standard I/O buffering.
#include <vector>     // Inkluderer biblioteket til at bruge vektorer i C++.

// Globale konstanter og variabler.
const std::string OUTPUT_FILENAME = "PSOC.wav";  // Definerer navnet på den output WAV-fil, der vil blive oprettet.
const int DATA_PACKET_SIZE = 512;                // Angiver antallet af datapakker, der skal modtages i hver cyklus.
const int SPI_BUFFER_SIZE = DATA_PACKET_SIZE;    // Størrelsen på SPI-bufferen, baseret på antallet af datapakker.
const uint16_t HANDSHAKE_SIGNAL = 0xFFFF;        // Definerer et handshake signal, som bruges til at synkronisere kommunikationen.
uint32_t fileSize;                               // Definerer filstørrelsen.
std::vector<uint16_t> finalData;                 // Definerer en vector til at gemme den endelige data.

// WAVHeader struktur definerer headerformatet for en WAV fil.
typedef struct WAVHeader 
{
    // Initialiserer headerens forskellige felter.
    uint8_t riffHeader[4] = { 'R', 'I', 'F', 'F' };               // Standard 'RIFF' header for WAV filer.
    uint32_t wavSize;                                             // Størrelsen på WAV filen minus 8 bytes.
    uint8_t waveHeader[4] = { 'W', 'A', 'V', 'E' };               // 'WAVE' format identifikator.
    uint8_t fmtHeader[4] = { 'f', 'm', 't', ' ' };                // 'fmt ' sub-chunk header.
    uint32_t fmtChunkSize = 16;                                   // Størrelsen på 'fmt ' sub-chunk (16 for PCM).
    uint16_t audioFormat = 1;                                     // Lydformat (1 for PCM).
    uint16_t numChannels = 1;                                     // Antal kanaler (1 for mono).
    uint32_t sampleRate = 44100;                                  // Samplingfrekvens.
    uint32_t byteRate = sampleRate * 2;                           // Byte rate (SampleRate * NumChannels * BitsPerSample/8).
    uint16_t blockAlign = 2;                                      // Block align (NumChannels * BitsPerSample/8).
    uint16_t bitsPerSample = 16;                                  // Antal bits pr. sample 
    uint8_t dataHeader[4] = { 'd', 'a', 't', 'a' };               // 'data' sub-chunk header.
    uint32_t dataChunkSize;                                       // Størrelsen på data sub-chunk.
} wav_hdr;


// writeWAVHeader funktionen skriver headeren til WAV filen.
void writeWAVHeader(std::ofstream& file) 
{
    // Implementering af WAV header opdatering.
    
    // Opretter en WAVHeader struct.
    wav_hdr wav;
    static_assert(sizeof(wav_hdr) == 44, "");            // Sikrer at størrelsen på wav_hdr er 44 bytes.
    wav.wavSize = fileSize + sizeof(wav_hdr) - 8;        // Størrelsen på WAV filen minus 8 bytes.
    wav.dataChunkSize = fileSize + sizeof(wav_hdr) - 44; // Størrelsen på data sub-chunk.
    
    // Skriver headeren til filen.
    file.write(reinterpret_cast<const char*>(&wav), sizeof(wav));
}

// Hovedfunktionen styrer hele optagelsesprocessen.
int main() 
{
    // Initialiserer ncurses mode.
    initscr();  // Starter curses mode.
    noecho();   // Slår echo af input fra.
    cbreak();   // Line buffering slået fra, passér hver input til programmet.
    timeout(0); // Non-blocking input mode.

    // Initialiserer BCM2835 biblioteket.
    if (!bcm2835_init()) {
        endwin();
        std::cerr << "BCM2835 init ERROR." << std::endl;
        return -1;
    }

    // Initialiserer SPI.
    if (!bcm2835_spi_begin()) {
        bcm2835_close();
        endwin();
        std::cerr << "SPI init ERROR." << std::endl;
        return -1;
    }

    // Konfigurerer SPI-indstillingerne.
    bcm2835_spi_setBitOrder(BCM2835_SPI_BIT_ORDER_MSBFIRST);          // MSB først for dataoverførsel.
    bcm2835_spi_setDataMode(BCM2835_SPI_MODE0);                       // SPI mode 0.
    bcm2835_spi_setClockDivider(BCM2835_SPI_CLOCK_DIVIDER_256);       // Sætter SPI clock divider.
    bcm2835_spi_chipSelect(BCM2835_SPI_CS0);                          // Vælger SPI chip (CS0).
    bcm2835_spi_setChipSelectPolarity(BCM2835_SPI_CS0, LOW);          // CS0 er aktiv ved lav signal.

    // Åbner output filen for at skrive data.
    std::ofstream outputFile(OUTPUT_FILENAME, std::ios::binary | std::ios::out | std::ios::trunc);
    if (!outputFile.is_open()) {
        bcm2835_spi_end();
        bcm2835_close();
        endwin();
        std::cerr << "Cannot open file." << std::endl;
        return -1;
    }

    // Hovedløkke til indsamling af data og styring af optagelse.
    while (true) 
    {
        // Læser input fra brugeren.
        int ch = getch();
        if (ch == 's') break; // Stopper optagelsen hvis 's' trykkes.

        // Håndtering af handshake signal.
        uint8_t handshakeBuffer[2];                                                                     // Opretter en buffer til handshake data.
        bcm2835_spi_transfern((char*)handshakeBuffer, 2);                                               // Overfører data fra SPI bufferen til handshake bufferen.
        uint16_t handshakeSignal = static_cast<uint16_t>(handshakeBuffer[0]) << 8 | handshakeBuffer[1]; // Konverterer SPI data til 16-bit data.
        
        // Hvis handshake signalet er modtaget, modtages data.
        if (handshakeSignal == HANDSHAKE_SIGNAL) {  
            for (int i = 0; i < DATA_PACKET_SIZE; i++) {                                   // Læser data fra SPI bufferen.
                uint8_t spiBuffer[SPI_BUFFER_SIZE];                                        // Opretter en buffer til SPI data.
                bcm2835_spi_transfern((char*)spiBuffer, SPI_BUFFER_SIZE);                  // Overfører data fra SPI bufferen til SPI data bufferen.
                uint16_t data = static_cast<uint16_t>(spiBuffer[i]) << 8 | spiBuffer[i+1]; // Konverterer SPI data til 16-bit data.
                finalData.push_back(data);                                                 // Tilføjer data til finalData vector.
            }
        }
    }
    
    // Filstørrelsen beregnes.
    fileSize = sizeof(finalData);

    writeWAVHeader(outputFile);
    // Daten skrives til filen.
    for (auto &data : finalData) {
        outputFile.write(reinterpret_cast<const char*>(&data), sizeof(data));
    }

    // Efter optagelse lukkes filen.
    outputFile.close();
    
    printf("file size %d", sizeof(fileSize));

    // Lukker SPI og BCM2835 biblioteket.
    bcm2835_spi_end();
    bcm2835_close();

    // Afslutter ncurses mode.
    endwin();

    return 0;
}
