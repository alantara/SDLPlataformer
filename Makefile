linker = -lSDL2main -lSDL2 -lSDL2_image
cpps = main.cpp Managers/GraphicManager.cpp Managers/EventManager.cpp Lists/EntityList.cpp Levels/Level.cpp Game/Game.cpp Entities/Obstacle/Plataform.cpp Entities/Character/Player.cpp Managers/CollisionManager.cpp
includes = -IManagers -ILists -ILevels -IGame -IEntities -IEntities/Character -IEntities/Obstacle -IComponents -I./

all:
	g++ -o main $(cpps) $(includes) $(linker)