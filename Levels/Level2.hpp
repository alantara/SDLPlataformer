#pragma once

#include "Level.hpp"

namespace Levels
{
    class Level2 : public Level
    {
    private:
        int maxTroopers;

    public:
        Level2(EventManager *ev, Player *player, Player *player2);
        ~Level2();

        void createTrooper(int x, int y);
        void trooperBulkInitialize(int n, int xi, int yi, int xf, int yf);
        void initialize(Player *player, Player *player2, bool multi);

        void update();
        int load();
        void save();
    };
}