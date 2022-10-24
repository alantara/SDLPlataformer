linker = -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
includes = -Isrc/core -Isrc/managers/screen -Isrc/managers/events -Isrc/sscene

all: main core screen events
	g++ -o main bin/*.o $(linker)

build: bin/*.o
	g++ -o main bin/*.o $(linker)

main: main.cpp
	g++ -c main.cpp -o bin/main.o $(includes) $(linker)
	
core: src/core/Core.cpp src/core/Core.hpp
	g++ -c src/core/Core.cpp -o bin/core.o $(includes) $(linker)

screen: src/managers/screen/Screen.cpp src/managers/screen/Screen.hpp
	g++ -c src/managers/screen/Screen.cpp -o bin/screen.o $(includes) $(linker)

events: src/managers/events/Event.cpp src/managers/events/Event.hpp
	g++ -c src/managers/events/Event.cpp -o bin/events.o $(includes) $(linker)
	