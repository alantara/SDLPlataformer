#include "Leaderboard.hpp"
using namespace Menus;

#include <fstream>
using namespace std;

#include "Game.hpp"

Leaderboard::Leaderboard(EventManager *ev, Game *gm) : Menu(ev, gm)
{
    sprite.setSprite("assets/galaxy.jpg", 0, 0, 1920, 1080, 1);

    mainMenu.setButton(760, 900, 400, 100);
    mainMenu.setSprite("assets/Menu/mainmenu.png", 0, 0, 400, 100, 1);
}
Leaderboard::~Leaderboard()
{
    events = nullptr;
}

void Leaderboard::update()
{
    if (isButtonClicked(mainMenu))
    {
        game->setGameState(-2);
    }
}

void Leaderboard::clean()
{
    vector<Font*>::iterator it = names.begin();

    while( it != names.end())
    {
        delete (*it);
        it++;
    }
    names.clear();
}

void Leaderboard::setNames()
{
    clean();

    ifstream arq;
    arq.open("lb.txt", ios::in);

    string name, points;

    int i = 1;
    while(!arq.eof())
    {
        if(i  > 10)
            continue;
            
        Font* namei = new Font(560, 100*i, 800, 100);
        arq >> points >> name;
        namei->setMessage(name + "......." + points);
        names.push_back(namei);
        i++;
    }
}

void Leaderboard::renderNames()
{
    vector<Font*>::iterator it = names.begin();

    while(it != names.end())
    {
        (*it)->render();
        it++;
    }
}

void Leaderboard::render()
{
    sprite.render();
    mainMenu.render();
    renderNames();
}