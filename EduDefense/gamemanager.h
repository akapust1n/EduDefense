#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "player.h"
#include "mapobject.h"
#include "tower.h"

#include <vector>

class GameManager {
public:
    GameManager();

    Player getPlayer();
    void setPlayer(Player player);
    std::vector<MapObject> getStones();
    void setStones(std::vector<MapObject> stones);
    std::vector<MapObject> getFreeAreas();
    void setFreeAreas(std::vector<MapObject> freeAreas);
    std::vector<MapObject> getRoads();
    void setRoads(std::vector<MapObject> roads);
    std::vector<Tower *> getTowers();
    std::vector<Enemy *> getEnemies();
    std::vector<Missile *> getMissles();
    void loop(); // Основной цикл игры

private:
    Player player;
    // Списки получаем из GameObjectCreator
    std::vector<MapObject> stones;
    std::vector<MapObject> freeAreas;
    std::vector<MapObject> roads;
    std::vector<Tower *> towers;
    std::vector<Enemy *> enemies;
    std::vector<Missile *> missiles;
};

#endif // GAMEMANAGER_H
