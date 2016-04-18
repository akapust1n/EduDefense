#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "gameobject.h"
#include "tower.h"

#include <vector>

class GameManager
{
public:
    GameManager();

    std::vector<GameObject> getStones() { return stones; }
    std::vector<GameObject> getFreeAreas() { return freeAreas; }
    std::vector<GameObject> getRoads() { return roads; }
    std::vector<Tower> getTowers() { return towers; }
    std::vector<Enemy> getEnemies() { return enemies; }
    std::vector<Missle> getMissles() { return missles; }

private:
    // Списки получаем из GameObjectCreator
    std::vector<GameObject> stones;
    std::vector<GameObject> freeAreas;
    std::vector<GameObject> roads;

    std::vector<Tower> towers;
    std::vector<Enemy> enemies;
    std::vector<Missle> missles;
};

#endif // GAMEMANAGER_H
