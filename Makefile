#OBJS specifies which files to compile as part of the project
OBJS = src/*.cpp src/core/*.cpp src/sprite/sprite.cpp

#INCLUDE_PATHS specifies the additional include paths we'll need
INCLUDE_PATHS = -Isrc\sdl\include\SDL2 -Isrc

#LIBRARY_PATHS specifies the additional library paths we'll need
LIBRARY_PATHS = -Lsrc\sdl\lib

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image

#OBJ_NAME specifies the name of our exectuable
EXE_NAME = main

#This is the target that compiles our executable
compile : 
	g++ $(OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(EXE_NAME)