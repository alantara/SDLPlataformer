#include "Level.hpp"

#include <iostream>
using namespace std;
using namespace Levels;

#include "Spike.hpp"

Level::Level(EventManager *ev) : evManager(ev)
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

void Level::spikeBulkInitialize(int n, int xi, int yi, int xf, int yf)
{
    while (n--)
    {
        Spike *spk = new Spike();

        int xRnd = rand() % (xf - xi) + xi;
        int yRnd = rand() % (yf - yi) + yi;

        spk->setPhysics(xRnd, yRnd, 64, 43, 0, 0, 0, 0);
        colManager.insertObs(static_cast<Obstacle *>(spk));
        entList.insert(static_cast<Entity *>(spk));
    }
}

void Level::plataformBulkInitialize(int n, int xi, int yi, int xf, int yf)
{
    while (n--)
    {
        Plataform *plat = new Plataform();

        int xRnd = rand() % (xf - xi) + xi;
        int yRnd = rand() % (yf - yi) + yi;

        plat->setPhysics(xRnd, yRnd, 64, 43, 0, 0, 0, 0);
        colManager.insertObs(static_cast<Obstacle *>(plat));
        entList.insert(static_cast<Entity *>(plat));
    }
}

void Level::groundInitialize()
{
    gnd = new Ground();
    Plataform* leftWall = new Plataform();
    Plataform* rightWall = new Plataform();

    leftWall->setPhysics(-129, GraphicManager::getHeight() - 88, 129, 44, 0, 0, 0, 0);
    rightWall->setPhysics(GraphicManager::getWidth(), GraphicManager::getHeight() - 88, 129, 44, 0, 0, 0, 0);
    entList.insert(static_cast<Entity *>(leftWall));
    entList.insert(static_cast<Entity *>(rightWall));
    colManager.insertObs(static_cast<Obstacle*>(leftWall));
    colManager.insertObs(static_cast<Obstacle*>(rightWall));


    gnd->setPhysics(-129, gfx->getHeight() - 44, gfx->getWidth() + 258, 44, 0, 0, 0, 0);
    colManager.setGND(gnd);
    entList.insert(static_cast<Entity *>(gnd));
}