# Makefile

# Compiler
CC = g++

# Compiler flags
CFLAGS = -Wall -std=c++11

# Source files
SRC = cache_sim.cpp

# Output executable
OUT = cache_sim

all: $(SRC)
    $(CC) $(CFLAGS) $(SRC) -o $(OUT)

clean:
    rm -f $(OUT)
