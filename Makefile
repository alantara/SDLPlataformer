linker = -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
includes = -Isrc/core -Isrc/managers/screen -Isrc/managers/events -Isrc/scene -Isrc/scene/menu -Isrc/scene/menu/main -Isrc/managers/scenes -Isrc/managers/frame

all: main core screen events scenesM MainMenu frame
	g++ -o main bin/*.o $(linker)

build: bin/*.o
	g++ -o main bin/*.o $(linker)

clear: 
	rm bin/*.o

main: main.cpp
	g++ -c main.cpp -o bin/main.o $(includes) $(linker)
	
core: src/core/Core.cpp src/core/Core.hpp
	g++ -c src/core/Core.cpp -o bin/core.o $(includes) $(linker)

screen: src/managers/screen/Screen.cpp src/managers/screen/Screen.hpp
	g++ -c src/managers/screen/Screen.cpp -o bin/screen.o $(includes) $(linker)

events: src/managers/events/Event.cpp src/managers/events/Event.hpp
	g++ -c src/managers/events/Event.cpp -o bin/events.o $(includes) $(linker)
	
scenesM: src/managers/scenes/ScenesM.cpp src/managers/scenes/ScenesM.hpp
	g++ -c src/managers/scenes/ScenesM.cpp -o bin/scene.o $(includes) $(linker)
	
MainMenu: src/scene/menu/main/MainMenu.cpp src/scene/menu/main/MainMenu.hpp
	g++ -c src/scene/menu/main/MainMenu.cpp -o bin/mainmenu.o $(includes) $(linker)
		
frame: src/managers/frame/Frame.cpp src/managers/frame/Frame.hpp
	g++ -c src/managers/frame/Frame.cpp -o bin/frame.o $(includes) $(linker)
	