#include "SPIHandler.hpp"
#include <bcm2835.h>
#include <iostream> // std::cerr

// Constructor
SPIHandler::SPIHandler() { 
    initSPI(); // Initialiserer SPI.
}

// Destructor
SPIHandler::~SPIHandler() {
    bcm2835_spi_end(); // Afslutter SPI.
    bcm2835_close();   // Afslutter BCM2835 biblioteket.
}

// Initialiserer SPI.
void SPIHandler::initSPI() { 
    // Initialiserer BCM2835 biblioteket.
    if (!bcm2835_init()) {
        std::cerr << "BCM2835 init ERROR." << std::endl; // Kaster en runtime error, hvis BCM2835 biblioteket ikke kan initialiseres.
    }
    // Initialiserer SPI.
    if (!bcm2835_spi_begin()) { 
        bcm2835_close();                                 // Lukker BCM2835 biblioteket.
        std::cerr << "SPI init ERROR." << std::endl;    // Kaster en runtime error, hvis SPI ikke kan initialiseres.
    }

    // Konfigurerer SPI indstillinger
    bcm2835_spi_setBitOrder(BCM2835_SPI_BIT_ORDER_MSBFIRST);    // MSB først for dataoverførsel.
    bcm2835_spi_setDataMode(BCM2835_SPI_MODE0);                 // SPI mode 0.
    bcm2835_spi_setClockDivider(BCM2835_SPI_CLOCK_DIVIDER_256); // Sætter SPI clock divider.
    bcm2835_spi_chipSelect(BCM2835_SPI_CS0);                    // Vælger SPI chip (CS0).
    bcm2835_spi_setChipSelectPolarity(BCM2835_SPI_CS0, LOW);    // CS0 er aktiv lav.
}

// Læser data fra SPI bufferen.
std::vector<uint16_t> SPIHandler::readData() {
    std::vector<uint16_t> data;          // Data vektor.
    uint8_t spiBuffer[SPI_BUFFER_SIZE];  // SPI buffer.

    uint8_t handshakeBuffer[2];                                                                     // Handshake buffer.
    bcm2835_spi_transfern(reinterpret_cast<char*>(handshakeBuffer), 2);                             // Overfører data fra SPI bufferen til handshake bufferen.
    uint16_t handshakeSignal = static_cast<uint16_t>(handshakeBuffer[0]) << 8 | handshakeBuffer[1]; // Konverterer SPI data til 16-bit data.

    // Hvis handshake signal modtages, modtag data.
    if (handshakeSignal == HANDSHAKE_SIGNAL) {                                              // Definér HANDSHAKE_SIGNAL passende
        bcm2835_spi_transfern(reinterpret_cast<char*>(spiBuffer), SPI_BUFFER_SIZE);         // Overfører data fra SPI bufferen til SPI data bufferen.
        for (int i = 0; i < SPI_BUFFER_SIZE; i += 2) {                                      // Læser data fra SPI bufferen.
            uint16_t spiData = static_cast<uint16_t>(spiBuffer[i]) << 8 | spiBuffer[i + 1]; // Konverterer SPI data til 16-bit data.
            data.push_back(spiData);                                                        // Tilføjer data til data vektoren.
        }
    }
    return data; // Returnerer data vektoren.
}
