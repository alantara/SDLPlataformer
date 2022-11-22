#include "Game.hpp"

#include <string>
#include <iostream>
using namespace std;

GraphicManager *Game::gfx = GraphicManager::getInstance();

Game::Game() : player(new Player()), player2(new Player()), lvl1(&evManager, player, player2), lvl2(&evManager, player, player2), isRunning(true), gameState(-2), menu(&evManager, this), pause(&evManager, this), mainMenu(&evManager, this), over(&evManager, this), ld(&evManager, this)
{
    init();

    while (isRunning)
    {
        evManager.listen(isRunning);
        update();
        render();
    }
}

Game::~Game()
{
    resetLevels();
    GraphicManager::getInstance()->deleteInstance();

    delete player;
    delete player2;
}

void Game::init()
{
    player->setSprite("assets/solo.png", 0, 0, 64, 59, 1);
    player->setInputSystem(&evManager, SDL_SCANCODE_A, SDL_SCANCODE_D, SDL_SCANCODE_SPACE, SDL_SCANCODE_Q);
    player->setDeletable(false);
    player->setEntID(10);

    player2->setSprite("assets/chew.png", 0, 0, 44, 64, 1);
    player2->setInputSystem(&evManager, SDL_SCANCODE_J, SDL_SCANCODE_L, SDL_SCANCODE_I, SDL_SCANCODE_U);
    player2->setDeletable(false);
    player2->setEntID(11);
}

void Game::update()
{
    if (evManager.getKeyDown(SDL_SCANCODE_ESCAPE) && (gameState == 1 || gameState == 2))
    {
        gameState = -1;
    }

    if(player->getPhysics()->getYPosition() > 2000)
        player->Deactivate();
    if(player2->getPhysics()->getYPosition() > 2000)
        player2->Deactivate();

    if (!player->getIsActive() && !player2->getIsActive())
    {
        gameState = 3;
        over.setPoints(Player::getScorePoints());
        player->reset();
        player2->reset();
        resetLevels();
    }

    switch (gameState)
    {
    case -2:
        mainMenu.update();
        break;
    case -1:
        pause.update();
        break;
    case 0:
        menu.update();
        break;
    case 1:
        lvl1.update();
        if (player->getPhysics()->getXPosition() > 1790 || player2->getPhysics()->getXPosition() > 1790)
        {
            gameState = 2;
            Level2Initialize();
        }
        break;
    case 2:
        lvl2.update();
        if (lvl2.getEnemySize() == 0 || player->getPhysics()->getXPosition() > 1790 || player2->getPhysics()->getXPosition() > 1790)
            gameState = 3;
        break;
    case 3:
        over.update();
        break;
    case 4:
        ld.update();
        break;
    default:
        isRunning = false;
        break;
    }
}

void Game::render()
{
    SDL_RenderClear(gfx->getRenderer());
    switch (gameState)
    {
    case -2:
        mainMenu.render();
        break;
    case -1:
        pause.render();
        break;
    case 0:
        menu.render();
        break;
    case 1:
        lvl1.render();
        break;
    case 2:
        lvl2.render();
        break;
    case 3:
        over.render();
        break;
    case 4:
        ld.render();
        break;
    default:
        isRunning = false;
        break;
    }
    SDL_RenderPresent(gfx->getRenderer());
}

void Game::resetLevels()
{
    lvl1.clean();
    lvl2.clean();
    player->reset();
    player2->reset();
}

void Game::Level1Initialize()
{
    lvl1.initialize(player, player2, multiplayer);
}

void Game::Level2Initialize()
{
    lvl2.initialize(player, player2, multiplayer);
}

void Game::saveLevel1()
{
    lvl1.save();
}

void Game::saveLevel2()
{
    //lvl2.save();
}

int Game::loadLVL1()
{
    return lvl1.load();
}

void Game::upLeaderboard()
{
    ld.setNames();
}

/*
void Game::getInput()
{
    bool quit = false;

    SDL_Event e;

    SDL_Color textColor = { 255, 255, 255, 0xFF };

    string inputText = "Enter name:";

    Font name(560, 600, 800, 100);
    name.setMessage(inputText);
    name.render();

    inputText = "";

    SDL_StartTextInput();

    while(!quit)
    {
        bool renderText = false;

        while(SDL_PollEvent(&e) != 0)
        {
            if(e.type == SDL_KEYDOWN)
            {
                if( e.key.keysym.sym == SDLK_BACKSPACE && inputText.length() > 0 )
                {
                    inputText.pop_back();
                    renderText = true;
                } 
            }
            else if(e.type == SDL_TEXTINPUT)
            {
                if( !( SDL_GetModState() & KMOD_CTRL && ( e.text.text[ 0 ] == 'c' || e.text.text[ 0 ] == 'C' || e.text.text[ 0 ] == 'v' || e.text.text[ 0 ] == 'V' ) ) )
                {
                    inputText += e.text.text;
                    renderText = true;
                }
            }
        }
        if(renderText)
        {
            if(inputText != "")
            {
                name.update(inputText);
                name.render();
            }
            else
            {
                name.update("");
                name.render();
            }
        }

        SDL_RenderClear( GraphicManager::getInstance()->getRenderer() );

        SDL_RenderPresent( GraphicManager::getInstance()->getRenderer() );
    }
    SDL_StopTextInput();

}*/