#include "Level.hpp"

#include <iostream>
using namespace std;
using namespace Levels;

Level::Level(GraphicManager *graphM) : Ente(graphM)
{
    cout << "Level Initialized " << endl;
}

Level::~Level()
{
    cout << "Level Destroyed" << endl;
}

void Level::render()
{
    entList.renderAll();
}