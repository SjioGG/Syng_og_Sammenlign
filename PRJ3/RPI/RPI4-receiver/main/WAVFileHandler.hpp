#ifndef WAVFILEHANDLER_H
#define WAVFILEHANDLER_H

#include <string>   // std::string
#include <fstream>  // std::ofstream
#include <vector>   // std::vector

// Define these constants as per your requirement.
typedef struct WAVHeader {
    uint8_t riffHeader[4] = { 'R', 'I', 'F', 'F' }; // Standard 'RIFF' header for WAV files.
    uint32_t wavSize; // Implementeres under writeWAVHeader funktionen.
    uint8_t waveHeader[4] = { 'W', 'A', 'V', 'E' }; // WAVE header.
    uint8_t fmtHeader[4] = { 'f', 'm', 't', ' ' }; // 'fmt ' chunk header.
    uint32_t fmtChunkSize = 16; // 16 for PCM.
    uint16_t audioFormat = 1; // 1 for PCM.
    uint16_t numChannels = 1; // 1 for mono, 2 for stereo.
    uint32_t sampleRate = 44100; // 44100 Hz.
    uint32_t byteRate = sampleRate * 2; // SampleRate * NumChannels * BitsPerSample/8.
    uint16_t blockAlign = 2; // 2 bytes for 16 bit mono.
    uint16_t bitsPerSample = 16; // 8 bits = 8, 16 bits = 16, etc.
    uint8_t dataHeader[4] = { 'd', 'a', 't', 'a' }; // 'data' sub-chunk header.
    uint32_t dataChunkSize; // Implementeres under writeWAVHeader funktionen.
} wav_hdr; // WAV header struct.

// writeWAVHeader funktionen skriver headeren til WAV filen.
class WAVFileHandler {
public:
    WAVFileHandler(const std::string& filename); // Constructor
    void writeData(const std::vector<uint16_t>& data); // Write data to WAV file.
    void finalizeFile(); // Finalize WAV file.

private:
    std::ofstream file; // WAV file.
    std::string filename; // WAV file name.
    uint32_t fileSize; // WAV file size.
    wav_hdr wavHeader; // WAV header.
    
    void writeWAVHeader(); // Write WAV header.
};

#endif // WAVFILEHANDLER_H