#makefile is finally sexy

CC = g++
SOURCES = src/*.cc src/*/*.cc
COMPILER_FLAGS = -O3
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_mixer -lpigScript -ldanylib
OUTPUT = bin/main


all: $(SOURCES)
	#the building part
	$(CC) $(SOURCES) $(LINKER_FLAGS) -o $(OUTPUT)
