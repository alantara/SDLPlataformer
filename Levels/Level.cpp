#include "Level.hpp"

using namespace Levels;

Level::Level()
{

}

Level::~Level()
{
}

void Level::render()
{
    entities.renderAll();
}