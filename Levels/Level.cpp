#include "Level.hpp"
using namespace Levels;

#include <iostream>
using namespace std;

#include "Spike.hpp"
#include "Plataform.hpp"
#include "Barrel.hpp"
#include "Trooper.hpp"
#include "Vader.hpp"
#include "Maul.hpp"

Level::Level(EventManager *ev) : evManager(ev)
{
    cout << "Level Initialized " << endl;

    p1 = nullptr;
    p2 = nullptr;
    gnd = nullptr;
}

Level::~Level()
{
    cout << "Level Destroyed" << endl;

    evManager = nullptr;
    p1 = nullptr;
    p2 = nullptr;
    gnd = nullptr;
}

void Level::render()
{
    sprite.render();
    entList.renderAll();
}

void Level::clean()
{
    entList.clean();
    colManager.clean();
}

void Level::groundInitialize()
{
    gnd = new Ground();
    gnd->setDeletable(false);

    createPlataform(-129, GraphicManager::getHeight() - 88);
    createPlataform(GraphicManager::getWidth(), GraphicManager::getHeight() - 88);

    gnd->setPhysics(-129, gfx->getHeight() - 44, gfx->getWidth() + 258, 44, 0, 0, 0, 0);
    colManager.setGND(gnd);
}

void Level::createSpike(int x, int y)
{
    Spike *spike = new Spike();
    spike->getPhysics()->setPosition(x, y);
    colManager.insertObs(static_cast<Obstacle *>(spike));
    entList.insert(static_cast<Entity *>(spike));
}

void Level::createPlataform(int x, int y, int type)
{
    Plataform *plataform = new Plataform(type);
    plataform->getPhysics()->setPosition(x, y);
    colManager.insertObs(static_cast<Obstacle *>(plataform));
    entList.insert(static_cast<Entity *>(plataform));
}

void Level::createBarrel(int x, int y)
{
    Barrel *barrel = new Barrel();
    barrel->getPhysics()->setPosition(x, y);
    colManager.insertObs(static_cast<Obstacle *>(barrel));
    entList.insert(static_cast<Entity *>(barrel));
}

void Level::createTrooper(int x, int y)
{
    Trooper *trp = new Trooper(p1, p2);
    trp->getPhysics()->setPosition(x, y);
    entList.insert(static_cast<Entity *>(trp));
    entList.insert(static_cast<Entity *>(trp->getBullet()));
    colManager.insertEnemy(static_cast<Enemy *>(trp));
}

void Level::createVader(int x, int y)
{
    Vader *vader = new Vader(p1, p2);
    vader->getPhysics()->setPosition(x, y);
    entList.insert(static_cast<Entity *>(vader));
    colManager.insertEnemy(static_cast<Enemy *>(vader));
}

void Level::createMaul(int x, int y)
{
    Maul *maul = new Maul(p1, p2);
    maul->getPhysics()->setPosition(x, y);
    entList.insert(static_cast<Entity *>(maul));
    colManager.insertEnemy(static_cast<Enemy *>(maul));
}

void Level::spikeBulkInitialize(int n, int xi, int yi, int xf, int yf)
{
    while (n--)
    {
        int xRnd = rand() % (xf - xi) + xi;
        int yRnd = rand() % (yf - yi) + yi;

        createSpike(xRnd, yRnd);
    }
}

void Level::plataformBulkInitialize(int n, int xi, int yi, int xf, int yf, int type)
{
    while (n--)
    {
        int xRnd = rand() % (xf - xi) + xi;
        int yRnd = rand() % (yf - yi) + yi;

        createPlataform(xRnd, yRnd, type);
    }
}

void Level::barrelBulkInitialize(int n, int xi, int yi, int xf, int yf)
{
    while (n--)
    {
        int xRnd = rand() % (xf - xi) + xi;
        int yRnd = rand() % (yf - yi) + yi;

        createBarrel(xRnd, yRnd);
    }
}
void Level::trooperBulkInitialize(int n, int xi, int yi, int xf, int yf)
{
    while (n--)
    {
        int xRnd = rand() % (xf - xi) + xi;
        int yRnd = rand() % (yf - yi) + yi;

        createTrooper(xRnd, yRnd);
    }
}
void Level::vaderBulkInitialize(int n, int xi, int yi, int xf, int yf)
{
    while (n--)
    {
        int xRnd = rand() % (xf - xi) + xi;
        int yRnd = rand() % (yf - yi) + yi;

        createVader(xRnd, yRnd);
    }
}
void Level::maulBulkInitialize(int n, int xi, int yi, int xf, int yf)
{
    while (n--)
    {
        int xRnd = rand() % (xf - xi) + xi;
        int yRnd = rand() % (yf - yi) + yi;

        createMaul(xRnd, yRnd);
    }
}
