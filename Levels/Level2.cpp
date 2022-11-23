#include "Level2.hpp"

namespace Levels
{
    Level2::Level2(EventManager *ev, Player *player, Player *player2) : Level(ev)
    {
        p1 = player;
        p2 = player2;

        sprite.setSprite("assets/bglvl2.jpg", 0, 0, 1920, 1080);
        groundInitialize();
        maxTroopers = 10;
    }
    Level2::~Level2()
    {

    }

    void Level2::createTrooper(int x, int y)
    {
        Trooper *trp = new Trooper(p1, p2);
        trp->getPhysics()->setPosition(x, y);
        entList.insert(static_cast<Entity *>(trp));
        entList.insert(static_cast<Entity *>(trp->getBullet()));
        colManager.insertEnemy(static_cast<Enemy *>(trp));
    }

    void Level2::trooperBulkInitialize(int n, int xi, int yi, int xf, int yf)
    {
        while (n--)
        {
            int xRnd = rand() % (xf - xi) + xi;
            int yRnd = rand() % (yf - yi) + yi;

            createTrooper(xRnd, yRnd);
        }
    }

    void Level2::initialize(Player *player, Player *player2, bool multi)
    {
        cout << "Level1 Initialized" << endl;
        entList.insert(static_cast<Entity *>(gnd));

        //------------------------------------------------------------------------
        // Player initialize
        player->getPhysics()->setPosition(150, 450);
        entList.insert(static_cast<Entity *>(player));
        entList.insert(static_cast<Entity *>(player->getBullet()));
        colManager.setPlayer(player);

        player2->getPhysics()->setPosition(80, 450);
        entList.insert(static_cast<Entity *>(player2));
        entList.insert(static_cast<Entity *>(player2->getBullet()));
        colManager.setPlayer2(player2);

        player2->Activate();
        if (!multi)
            player2->Deactivate();

        vaderBulkInitialize(3, 400, 500, 800, 600);

        trooperBulkInitialize(rand() % (maxTroopers - 2) + 3, 900, 500, 1400, 600);

        //-------------------------------------------------------------------------
        // Obstacles Initialize
        barrelBulkInitialize(3, 200, 700, 1600, 800);

        spikeBulkInitialize(3, 500, 700, 800, 800);

        //"Static" plataforms

        createPlataform(0, 100, 5);
        createPlataform(0, 200, 5);
        createPlataform(0, 300, 5);
        createPlataform(0, 400, 5);
        createPlataform(0, 500, 5);

        createPlataform(GraphicManager::getInstance()->getWidth() - 50, 100, 5);
        createPlataform(GraphicManager::getInstance()->getWidth() - 50, 200, 5);
        createPlataform(GraphicManager::getInstance()->getWidth() - 50, 300, 5);
        createPlataform(GraphicManager::getInstance()->getWidth() - 50, 400, 5);
        createPlataform(GraphicManager::getInstance()->getWidth() - 50, 500, 5);

        createPlataform(900, 900, 4);
        createPlataform(950, 900, 6);
        createPlataform(450, 900, 5);

        createPlataform(400, 1000);
        createPlataform(900, 1000);
        createPlataform(1500, 1000);
        createPlataform(1600, 1000);
    }

    void Level2::update()
    {
        gnd->render();
        colManager.Execute();
        entList.updateAll();
        Score.update(to_string(Player::getScorePoints()));
        p1Life.update(to_string(p1->getHealth()));
        p2Life.update(to_string(p2->getHealth()));
    }

    int Level2::load()
    {
        ifstream arq;
        arq.open("da.txt", ios::in);

        entList.insert(static_cast<Entity *>(gnd));
        int lvlnum;
        int x, y;
        int id, active;
        int type;

        arq >> lvlnum;

        while (!arq.eof())
        {
            arq >> id;
            cout << id << endl;

            switch (id)
            {
            case 2:
                arq >> active;
                arq >> x;
                arq >> y;
                createTrooper(x, y);
                break;
            case 4:
                arq >> active;
                arq >> x;
                arq >> y;
                createVader(x, y);
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
                arq >> x;
                arq >> y;

                p1->getPhysics()->setPosition(x, y);
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
                arq >> x;
                arq >> y;

                p2->getPhysics()->setPosition(x, y);
                entList.insert(static_cast<Entity *>(p2));
                entList.insert(static_cast<Entity *>(p2->getBullet()));
                colManager.setPlayer2(p2);
                p2->Deactivate();
                if (active)
                {
                    p2->Activate();
                }
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