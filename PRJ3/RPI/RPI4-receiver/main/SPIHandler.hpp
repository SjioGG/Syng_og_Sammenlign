#ifndef SPIHANDLER_HPP
#define SPIHANDLER_HPP

#include <bcm2835.h> // SPI-bibliotek
#include <vector>    // std::vector

// Konstanter
const int SPI_BUFFER_SIZE = 512;           // Størrelse på SPI-buffer.
const uint16_t HANDSHAKE_SIGNAL = 0xFFFF;  // Handshake signal.

// Størrelse på datapakke.
class SPIHandler {
public:
    SPIHandler();                     // Constructor
    ~SPIHandler();                    // Destructor
    std::vector<uint16_t> readData(); // Læs data fra SPI-buffer.

private:
    void initSPI(); // Initialiser SPI.
};

#endif // SPIHANDLER_HPP
