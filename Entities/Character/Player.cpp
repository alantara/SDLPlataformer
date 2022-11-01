#include "Player.hpp"
using namespace Entities;
using namespace Characters;
//(GraphicManager *gfxMan, EventManager *eveMan, CaracterInput charInp, SpriteConstraints sprConst, Position pos)
Player::Player(GraphicManager *graphM, EventManager *ev, CharacterInput inp, int xPos, int yPos) : Character(graphM, xPos, yPos), input(inp)
{
    event = ev;
    id = 1;
    vx = vy = 0;
    ay = 1;
    ax = 0;
}

Player::~Player()
{
}

void Player::update()
{
    ax = 0;
    if (event->getKeyDown(input.getJump()))
    {
        ay = -1; // A Fazer
    }
    if (event->getKeyDown(input.getLeft()))
    {
        ax += -1;
    }
    if (event->getKeyDown(input.getRight()))
    {
        ax += 1;
    }

    vy += ay;
    y += vy;
    vx += ax;
    x += vx;
}
