#include "WAVFileHandler.h" // WAVFileHandler
#include "SPIHandler.h" // SPIHandler
#include <ncurses.h> // ncurses
#include <iostream> // std::cerr
#include <vector> // std::vector

// Hovedfunktionen.
int main() {
    try {
        initscr(); // Starter curses mode.
        noecho(); // Slår echo af input fra.
        cbreak(); // Line buffering slået fra, passér hver input til programmet.
        timeout(0); // Non-blocking input mode.

        // Initialiserer BCM2835 biblioteket.
        SPIHandler spiHandler; // Initialiserer SPIHandler.
        WAVFileHandler wavHandler("PSOC.wav"); // Initialiserer WAVFileHandler.

        // Hovedløkken.
        while (true) {
            int ch = getch(); // Læser input fra brugeren.
            if (ch == 's') break; // Stopper optagelsen hvis brugeren trykker på 's'.

            std::vector<uint16_t> data = spiHandler.readData(); // Læser data fra SPI bufferen.
            if (!data.empty()) { // Hvis der er data i bufferen, skrives de til filen.
                wavHandler.writeData(data); // Skriver data til WAV filen.
            }
        }

        // Afslutter programmet.
        wavHandler.finalizeFile();

        // Afslutter SPI.
        endwin();

      // Håndterer fejl.  
    } catch (const std::exception& e) { // Catcher alle exceptions.
        endwin(); // Afslutter ncurses mode.
        std::cerr << e.what() << std::endl; // Udskriver fejlbeskeden.
        return -1; // Returnerer -1.
    }

    return 0; // Returnerer 0.
}
