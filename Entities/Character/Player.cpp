#include "Player.hpp"
using namespace Entities;
using namespace Character;

Player::Player(GraphicManager *graphM, EventManager *ev, int xPos, int yPos) : Character(graphM)
{
    event = ev;
    x = xPos;
    y = yPos;
}

Player::~Player()
{
}

void Player::update()
{
    if (event->getKeyDown(SDL_SCANCODE_W))
    {
        y--;
    }
    if (event->getKeyDown(SDL_SCANCODE_A))
    {
        x--;
    }
    if (event->getKeyDown(SDL_SCANCODE_S))
    {
        y++;
    }
    if (event->getKeyDown(SDL_SCANCODE_D))
    {
        x++;
    }
}
