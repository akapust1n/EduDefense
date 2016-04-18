#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "player.h"
#include "gameobject.h"
#include "tower.h"

#include <vector>

class GameManager {
public:
    GameManager();

    Player getPlayer();
    void setPlayer(Player player);
    std::vector<GameObject *> getStones();
    void setStones(std::vector<GameObject *> stones);
    std::vector<GameObject *> getFreeAreas();
    void setFreeAreas(std::vector<GameObject *> freeAreas);
    std::vector<GameObject *> getRoads();
    void setRoads(std::vector<GameObject *> roads);
    std::vector<Tower *> getTowers();
    std::vector<Enemy *> getEnemies();
    std::vector<Missle *> getMissles();

    void loop(); // Основной цикл игры

private:
    Player player;
    // Списки получаем из GameObjectCreator
    std::vector<GameObject *> stones;
    std::vector<GameObject *> freeAreas;
    std::vector<GameObject *> roads;

    std::vector<Tower *> towers;
    std::vector<Enemy *> enemies;
    std::vector<Missle *> missles;
};

#endif // GAMEMANAGER_H
