#include "Game.hpp"
#include "Plataform.hpp"

#include "CharacterInput.hpp"
#include "Sprite.hpp"
#include "Position.hpp"
#include "Physics.hpp"

#include <iostream>
using namespace std;

Game::Game() : gfx("Plataformer", 1600, 900),
               events(),
               lvl1(&gfx, &events, player, player2)
{
    cout << "Game Initialized" << endl;

    isRunning = true;

    while (isRunning)
    {
        events.listen(isRunning);
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