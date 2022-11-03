#include "Level.hpp"

#include <iostream>
using namespace std;
using namespace Levels;

Level::Level(GraphicManager *graphM, EventManager *ev) : gfx(graphM), events(ev)
{
    cout << "Level Initialized " << endl;
}

Level::~Level()
{
    cout << "Level Destroyed" << endl;
}

void Level::render()
{
    bg.render();
    entList.renderAll();
}