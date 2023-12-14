#ifndef WAVFILEHANDLER_H
#define WAVFILEHANDLER_H

#include <string>   // std::string
#include <fstream>  // std::ofstream
#include <vector>   // std::vector

// Konstanter
typedef struct WAVHeader {
    uint8_t riffHeader[4] = { 'R', 'I', 'F', 'F' }; // Standard 'RIFF'-header til WAV-filer.
    uint32_t wavSize;                               // Implementeres under writeWAVHeader-funktionen.
    uint8_t waveHeader[4] = { 'W', 'A', 'V', 'E' }; // Standard 'WAVE'-header til WAV-filer.
    uint8_t fmtHeader[4] = { 'f', 'm', 't', ' ' };  // 'fmt'-sub-chunk-header.
    uint32_t fmtChunkSize = 16;                     // 16 for PCM.
    uint16_t audioFormat = 1;                       // 1 for PCM.
    uint16_t numChannels = 1;                       // 1 for mono, 2 for stereo.
    uint32_t sampleRate = 44100;                    // 44100 samples pr. sekund.
    uint32_t byteRate = sampleRate * 2;             // 2 bytes pr. sample.
    uint16_t blockAlign = 2;                        // 2 bytes for 16-bit mono.
    uint16_t bitsPerSample = 16;                    // 16 bits pr. sample.
    uint8_t dataHeader[4] = { 'd', 'a', 't', 'a' }; // 'data'-sub-chunk-header.
    uint32_t dataChunkSize;                         // Implementeres under writeWAVHeader-funktionen.
} wav_hdr;                                          // WAV-header-struktur.

// Klasse til at håndtere WAV-filer.
class WAVFileHandler {
public:
    WAVFileHandler(const std::string& filename);       // Constructor
    void writeData(const std::vector<uint16_t>& data); // Skriv data til WAV-fil.
    void finalizeFile();                               // Afslut WAV-fil.

private:
    std::ofstream file;    // WAV-fil.
    std::string filename;  // Filnavn for WAV-fil.
    uint32_t fileSize;     // Filstørrelse for WAV-fil.
    wav_hdr wavHeader;     // WAV-header.
    
    void writeWAVHeader(); // Skriv WAV-header.
};

#endif // WAVFILEHANDLER_H
