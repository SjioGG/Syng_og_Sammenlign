#ifndef SPIHANDLER_HPP
#define SPIHANDLER_HPP

#include <bcm2835.h> // SPI library
#include <vector>    // std::vector

// Define these constants as per your requirement.
const int SPI_BUFFER_SIZE = 512;           // SPI buffer size.
const uint16_t HANDSHAKE_SIGNAL = 0xFFFF;  // Handshake signal.

// Data packet size.
class SPIHandler {
public:
    SPIHandler(); // Constructor
    ~SPIHandler(); // Destructor
    std::vector<uint16_t> readData(); // Read data from SPI buffer.

private:
    void initSPI(); // Initialize SPI.
};

#endif // SPIHANDLER_HPP