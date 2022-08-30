
C_FILES = src/animator/*.cpp src/characters/*.cpp src/core/*.cpp src/event-handler/*.cpp src/graphics/*.cpp src/physics/*.cpp src/timer/*.cpp

all:
	g++ main.cpp $(C_FILES) -w -lSDL2 -lSDL2_image -o main