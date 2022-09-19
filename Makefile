all:
	g++ -o main main.cpp src/core/Core.cpp src/gfx/TextureManager.cpp src/map/Map.cpp -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer