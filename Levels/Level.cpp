#include "Level.hpp"

#include <iostream>
using namespace std;
using namespace Levels;

Level::Level(GraphicManager *p_graphM, EventManager *ev) : Ente(p_graphM), evManager(ev)
{
    cout << "Level Initialized " << endl;

    p1 = nullptr;
    p2 = nullptr;
}

Level::~Level()
{
    cout << "Level Destroyed" << endl;

    evManager = nullptr;
    p1 = nullptr;
    p2 = nullptr;
}

void Level::render()
{
    sprite.render(gfx);
    entList.renderAll();
}