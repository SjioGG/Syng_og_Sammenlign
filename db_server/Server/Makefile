# Default compiler
CC=g++

# Check for TARGET parameter
ifeq ($(TARGET),host)
    CC=g++
else
    CC=arm-rpizw-g++
endif

# Compiler flags
CFLAGS=-Wall

# Linker flags
LFLAGS=-lsqlite3

# Output executable
OUTPUT=file_server

# Source files
SRC=file_server.cpp

# Default target
all: $(OUTPUT)

# Rule for building the output
$(OUTPUT): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(OUTPUT) $(LFLAGS)

# Clean target
clean:
	rm -f $(OUTPUT)

