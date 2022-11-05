#include "Level.hpp"

#include <iostream>
using namespace std;
using namespace Levels;

Level::Level(GraphicManager *graphM, EventManager *ev) : gfx(graphM), events(ev), colManager(new CollisionManager())
{
    cout << "Level Initialized " << endl;
}

Level::~Level()
{
    cout << "Level Destroyed" << endl;
}

void Level::render()
{
    sprite.render();
    entList.renderAll();
}