CXXFLAGS = -I.
LDFLAGS = -lncurses -lbcm2835
CC = g++
EXE = prog
SOURCES = main.cpp SPIHandler.cpp WAVFileHandler.cpp SPIHandler.hpp WAVFileHandler.hpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(EXE)

.PHONY: all clean help

$(EXE): $(OBJECTS)
    $(CC) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
    $(CC) -g -c $< $(CXXFLAGS)

clean:
    rm -f $(OBJECTS) $(EXE)

help:
    @echo "all available targets"
    @echo "make all"
    @echo "make clean"
    @echo "make help"
    @echo "Executable: ./prog"