#include "Game.hpp"
#include "Plataform.hpp"
#include "CharacterInput.hpp"

#include <iostream>
using namespace std;

Game::Game() : gfx("Plataformer", 1600, 900),
               events(),
               lvl1(&gfx)
{
    cout << "Game Initialized" << endl;

    CharacterInput inp1 = CharacterInput(SDL_SCANCODE_A, SDL_SCANCODE_D, SDL_SCANCODE_W);
    //CharacterInput inp2 = CharacterInput(SDL_SCANCODE_LEFT, SDL_SCANCODE_RIGHT, SDL_SCANCODE_UP);

    player = new Player(&gfx, &events, inp1, 0, 0);
    //player2 = new Player(&gfx, &events, inp2, 20, 20);
    lvl1.getEntityList()->insert(static_cast<Entity *>(player));
    //lvl1.getEntityList()->insert(static_cast<Entity *>(player2));

    Plataform *pl = new Plataform(&gfx, 0, 700);
    lvl1.getEntityList()->insert(static_cast<Entity *>(pl));
    lvl1.getCollisionManager()->getListPlataforms()->push_back(pl);

    isRunning = true;

    while (isRunning)
    {
        events.listen(isRunning);

        lvl1.getCollisionManager()->handleCollision(player);

        update();
        render();
    }
}

Game::~Game()
{
    cout << "Game Deleted" << endl;
}

void Game::update()
{
    lvl1.update();
}

void Game::render()
{
    SDL_RenderClear(gfx.getRenderer());

    lvl1.render();

    SDL_RenderPresent(gfx.getRenderer());
}