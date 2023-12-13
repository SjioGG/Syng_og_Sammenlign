#include "SPIHandler.hpp"
#include <bcm2835.h>

// Define these constants as per your requirement.
SPIHandler::SPIHandler() { 
    initSPI(); // Initialize SPI.
}

// Destructor
SPIHandler::~SPIHandler() {
    bcm2835_spi_end(); // End SPI.
    bcm2835_close(); // Close BCM2835 library.
}

// Initialize SPI.
void SPIHandler::initSPI() { 
    // Initialize BCM2835 library.
    if (!bcm2835_init()) {
        throw std::runtime_error("BCM2835 init ERROR."); // Throw runtime error if BCM2835 library cannot be initialized.
    }
    // Initialize SPI.
    if (!bcm2835_spi_begin()) { 
        bcm2835_close(); // Close BCM2835 library.
        throw std::runtime_error("SPI init ERROR."); // Throw runtime error if SPI cannot be initialized.
    }

    // Configure SPI settings
    bcm2835_spi_setBitOrder(BCM2835_SPI_BIT_ORDER_MSBFIRST);  // MSB first for data transfer.
    bcm2835_spi_setDataMode(BCM2835_SPI_MODE0); // SPI mode 0.
    bcm2835_spi_setClockDivider(BCM2835_SPI_CLOCK_DIVIDER_256); // Set SPI clock divider.
    bcm2835_spi_chipSelect(BCM2835_SPI_CS0); // Select SPI chip (CS0).
    bcm2835_spi_setChipSelectPolarity(BCM2835_SPI_CS0, LOW); // CS0 is active low.
}

// Read data from SPI buffer.
std::vector<uint16_t> SPIHandler::readData() {
    std::vector<uint16_t> data; // Data vector.
    uint8_t spiBuffer[SPI_BUFFER_SIZE];  // SPI buffer.

    uint8_t handshakeBuffer[2]; // Handshake buffer.
    bcm2835_spi_transfern(reinterpret_cast<char*>(handshakeBuffer), 2); // Transfer data from SPI buffer to handshake buffer.
    uint16_t handshakeSignal = static_cast<uint16_t>(handshakeBuffer[0]) << 8 | handshakeBuffer[1]; // Convert SPI data to 16-bit data.

    // If handshake signal is received, receive data.
    if (handshakeSignal == HANDSHAKE_SIGNAL) {  // Define HANDSHAKE_SIGNAL appropriately
        bcm2835_spi_transfern(reinterpret_cast<char*>(spiBuffer), SPI_BUFFER_SIZE); // Transfer data from SPI buffer to SPI data buffer.
        for (int i = 0; i < SPI_BUFFER_SIZE; i += 2) { // Read data from SPI buffer.
            uint16_t spiData = static_cast<uint16_t>(spiBuffer[i]) << 8 | spiBuffer[i + 1]; // Convert SPI data to 16-bit data.
            data.push_back(spiData); // Add data to data vector.
        }
    }
    return data; // Return data vector.
}
