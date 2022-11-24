#include "Level2.hpp"

namespace Levels
{
    Level2::Level2(EventManager *ev, Player *player, Player *player2) : Level(ev)
    {
        p1 = player;
        p2 = player2;

        sprite.setSprite("assets/bglvl2.jpg", 0, 0, 1920, 1080);
        groundInitialize();
        maxTroopers = 5;
    }
    Level2::~Level2()
    {
    }

    Trooper *Level2::createTrooper(int x, int y)
    {
        Trooper *trp = new Trooper(p1, p2);
        trp->getPhysics()->setPosition(x, y);
        entList.insert(static_cast<Entity *>(trp));
        entList.insert(static_cast<Entity *>(trp->getBullet()));
        colManager.insertEnemy(static_cast<Enemy *>(trp));
        return trp;
    }

    void Level2::trooperBulkInitialize()
    {
        
    }

    void Level2::spikeBulkInitialize()
    {

    }

    void Level2::barrelBulkInitialize()
    {

    }

    void Level2::vaderBulkInitialize()
    {
       
    }

    void Level2::initialize(Player *player, Player *player2, bool multi)
    {
        cout << "Level1 Initialized" << endl;
        entList.insert(static_cast<Entity *>(gnd));

        //------------------------------------------------------------------------
        // Player initialize

        player->getPhysics()->setPosition(50, 950);
        entList.insert(static_cast<Entity *>(player));
        entList.insert(static_cast<Entity *>(player->getBullet()));
        colManager.setPlayer(player);

        player2->getPhysics()->setPosition(150, 950);
        entList.insert(static_cast<Entity *>(player2));
        entList.insert(static_cast<Entity *>(player2->getBullet()));
        colManager.setPlayer2(player2);

        player2->Activate();
        if (!multi)
            player2->Deactivate();

        //-------------------------------------------------------------------------
        //Enemy Initialize

        vaderBulkInitialize();
        trooperBulkInitialize();

        //-------------------------------------------------------------------------
        // Obstacles Initialize

        barrelBulkInitialize();
        spikeBulkInitialize();

        //-------------------------------------------------------------------------
        //"Static" plataforms

        for (int i = 4; i > 0; i--)
            createPlataform(0, 830 - i * 45, 3);
        createPlataform(0, 830, 2);
        for (int i = 4; i > 0; i--)
        {
            createPlataform(0, GraphicManager::getInstance()->getHeight() - 45 - i * 45, 3);
            createPlataform(GraphicManager::getInstance()->getWidth() - 43, GraphicManager::getInstance()->getHeight() - 45 - i * 45, 3);
        }

        createPlataform(228, 735, 2);
        for (int i = 5; i > 0; i--)
            createPlataform(314, 990 - i * 45, 3);
        createPlataform(270, 900, 5);
        createPlataform(270, 945, 3);
        createPlataform(225, 900, 5);
        createPlataform(225, 945, 3);
        createPlataform(185, 990, 5);
        createPlataform(228, 990);

        createPlataform(1161, 850, 2);
        for (int i = 3; i > 0; i--)
            createPlataform(1161, 990 - i * 45, 3);
        createPlataform(1117, 945, 5);
        createPlataform(1075, 990);
    }

    void Level2::update()
    {
        gnd->render();
        colManager.Execute();
        entList.updateAll();
        Score.update("Points: " + to_string(Player::getScorePoints()));
        p1Life.update("HP: " + to_string(p1->getHealth()));
        p2Life.update("HP: " + to_string(p2->getHealth()));
    }

    int Level2::load()
    {
        ifstream arq;
        arq.open("da.txt", ios::in);

        entList.insert(static_cast<Entity *>(gnd));
        int lvlnum;
        int id, active;
        int x, y;
        int vx, vy;

        int bid;
        int bActive;
        int bx, by;
        int bvx, bvy;
        int type;

        Trooper *trooper = nullptr;
        Vader *vader = nullptr;

        arq >> lvlnum;

        while (!arq.eof())
        {
            arq >> id;
            cout << id << endl;

            switch (id)
            {
            case 2:
                arq >> active;
                arq >> x >> y;
                arq >> vx >> vy;

                arq >> bid;
                arq >> bActive;
                arq >> bx >> by;
                arq >> bvx >> bvy;
                trooper = createTrooper(x, y);
                trooper->getPhysics()->setVelocity(vx, vy);

                trooper->getBullet()->getPhysics()->setPosition(bx, by);
                trooper->getBullet()->getPhysics()->setVelocity(bvx, bvy);

                trooper->getBullet()->Deactivate();
                if (bActive)
                {
                    trooper->getBullet()->Activate();
                }
                break;
            case 4:
                arq >> active;
                arq >> x >> y;
                arq >> vx >> vy;
                vader = createVader(x, y);
                vader->getPhysics()->setVelocity(vx, vy);
                break;
            case 5:
                arq >> active;
                arq >> x;
                arq >> y;
                createBarrel(x, y);
                break;
            case 6:
                arq >> active;
                arq >> x;
                arq >> y;
                createSpike(x, y);
                break;
            case 7:
                arq >> type;
                arq >> active;
                arq >> x;
                arq >> y;
                createPlataform(x, y, type);
                break;
            case 10:
                arq >> active;
                arq >> x >> y;
                arq >> vx >> vy;

                arq >> bid;
                arq >> bActive;
                arq >> bx >> by;
                arq >> bvx >> bvy;

                p1->getPhysics()->setPosition(x, y);
                p1->getPhysics()->setVelocity(vx, vy);

                p1->getBullet()->getPhysics()->setPosition(bx, by);
                p1->getBullet()->getPhysics()->setVelocity(bvx, bvy);

                p1->getBullet()->Deactivate();
                if (bActive)
                {
                    p1->getBullet()->Activate();
                }

                entList.insert(static_cast<Entity *>(p1));
                entList.insert(static_cast<Entity *>(p1->getBullet()));
                colManager.setPlayer(p1);
                p1->Deactivate();
                if (active)
                {
                    p1->Activate();
                }
                break;
            case 11:
                arq >> active;
                arq >> x >> y;
                arq >> vx >> vy;

                arq >> bid;
                arq >> bActive;
                arq >> bx >> by;
                arq >> bvx >> bvy;

                p2->getPhysics()->setPosition(x, y);
                p2->getPhysics()->setVelocity(vx, vy);

                p2->Deactivate();
                if (active)
                {
                    p2->Activate();
                }

                p2->getBullet()->getPhysics()->setPosition(bx, by);
                p2->getBullet()->getPhysics()->setVelocity(bvx, bvy);

                p2->getBullet()->Deactivate();
                if (bActive)
                {
                    p2->getBullet()->Activate();
                }

                entList.insert(static_cast<Entity *>(p2));
                entList.insert(static_cast<Entity *>(p2->getBullet()));
                colManager.setPlayer2(p2);

                break;

            default:
                break;
            }
        }

        arq.close();
        if (p1 == nullptr)
            return 0;
        return lvlnum;
    }

    void Level2::save()
    {
        entList.save("da.txt", 2);
    }
}