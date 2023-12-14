#include "WAVFileHandler.hpp" // WAVFileHandler
#include "SPIHandler.hpp" // SPIHandler
#include <ncurses.h> // ncurses
#include <iostream> // std::cerr
#include <vector> // std::vector

// Hovedfunktionen.
int main() {
    try {
        initscr();   // Initialiserer ncurses mode.
        noecho();    // Slå echo fra.
        cbreak();    // Slå line buffering fra.
        timeout(0);  // Sætter getch til non-blocking.

        // Initialiserer SPI.
        SPIHandler spiHandler;                 // Initialiserer SPIHandler.
        WAVFileHandler wavHandler("PSOC.wav"); // Initialiserer WAVFileHandler.

        // Starter optagelsen.
        while (true) {
            int ch = getch();                                   // Læser input fra brugeren.
            if (ch == 's') break;                               // Hvis inputtet er 's', starter optagelsen.

            std::vector<uint16_t> data = spiHandler.readData(); // Læser data fra SPI.
            if (!data.empty()) {                                // Hvis der er data, skrives det til WAV filen.
                wavHandler.writeData(data);                     // Skriver data til WAV filen.
            }
        }

        // Afslutter optagelsen.
        wavHandler.finalizeFile();

        // Afslutter ncurses mode.
        endwin();

      // Catcher alle exceptions.
    } catch (const std::exception& e) {     
        endwin();                           // Afslutter ncurses mode.
        std::cerr << e.what() << std::endl; // Skriver fejlbeskeden til stderr.
        return -1;                          // Returnerer -1.
    }

    return 0;                               // Returnerer 0.
}
