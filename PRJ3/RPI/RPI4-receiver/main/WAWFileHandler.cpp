#include "WAVFileHandler.hpp" // WAVFileHandler
#include <cassert> // assert

// Hovedfunktionen.
WAVFileHandler::WAVFileHandler(const std::string& filename) : filename(filename), fileSize(0) { // Constructor
    file.open(filename, std::ios::binary | std::ios::out | std::ios::trunc); // Åbner output filen for at skrive data.
    if (!file.is_open()) { // Hvis filen ikke kan åbnes, kastes en exception.
        throw std::runtime_error("Cannot open file."); // Kaster en runtime error.
    }
}

// Skriver data til WAV filen.
void WAVFileHandler::writeData(const std::vector<uint16_t>& data) { 
    for (auto& d : data) { 
        file.write(reinterpret_cast<const char*>(&d), sizeof(d)); 
        fileSize += sizeof(d); // Filstørrelsen opdateres.
    }
}

// Finalize WAV file.
void WAVFileHandler::finalizeFile() { 
    writeWAVHeader(); // Skriver WAV headeren til filen.
    file.close(); // Lukker filen.
}

// Skriver WAV headeren til filen.
void WAVFileHandler::writeWAVHeader() { // Write WAV header.
    static_assert(sizeof(wav_hdr) == 44, ""); // Assert at størrelsen af wav_hdr er 44 bytes.
    wavHeader.wavSize = fileSize + sizeof(wav_hdr) - 8; // Filstørrelsen opdateres.
    wavHeader.dataChunkSize = fileSize; // Størrelsen på data sub-chunk opdateres.
    file.seekp(0, std::ios::beg); // Sætter filpointeren til starten af filen.
    file.write(reinterpret_cast<const char*>(&wavHeader), sizeof(wav_hdr)); // Skriver headeren til filen.
}