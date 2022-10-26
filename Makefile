linker = -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
includes = -Isrc/core -Isrc/managers/screen -Isrc/managers/events -Isrc/scene -Isrc/scene/menu -Isrc/scene/menu/main -Isrc/managers/scenes -Isrc/managers/frame -Isrc/entity/plataforms/ -Isrc/components/gfx -Isrc/entity -Isrc/managers/entity -Isrc/managers/map -Isrc/managers/entity -Isrc/managers/map
CMP = main.cpp src/core/Core.cpp src/managers/screen/Screen.cpp src/managers/events/Event.cpp src/managers/scenes/ScenesM.cpp src/scene/menu/main/MainMenu.cpp src/managers/frame/Frame.cpp src/components/gfx/Sprite.cpp src/entity/plataforms/Tiles.cpp src/entity/Entity.cpp src/managers/map/Map.cpp src/managers/entity/EntityM.cpp src/managers/map/Tileset.cpp

all: 
	g++ -o main $(CMP) $(linker) $(includes)

build: bin/*.o
	g++ -o main bin/*.o $(linker) $(includes)

clear: 
	rm bin/*.o

main: main.cpp
	g++ -c main.cpp -o bin/main.o $(includes) $(linker)