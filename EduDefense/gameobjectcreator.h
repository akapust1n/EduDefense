#ifndef GAMEOBJECTCREATOR_H
#define GAMEOBJECTCREATOR_H

#include "gameobject.h"
#include <string>
#include <vector>
#include "kind_maps.h"

//Чтение из файла и создание игровых объектов
class ObjectsCreator {
  public:
    ObjectsCreator(std::string filename);
    int getStonesCount() { return stonesCount; }
    int getFreeAreasCount() { return freeAreasCount; }
    int getNumRoads() { return roadsCount; }
    std::vector<GameObject> getStones() { return stones; }
    std::vector<GameObject> getFreeAreas() { return freeAreas; }
    std::vector<GameObject> getRoads() { return roads; }
  private:
    void readfile();
    map_state charToMapState(char c);
    std::string file;
    std::string mapStates;
    std::vector<GameObject> stones;
    std::vector<GameObject> freeAreas;
    std::vector<GameObject> roads;
    int stonesCount;
    int freeAreasCount;
    int roadsCount;
    const int texture_size = 32; //размер текстурки
};

#endif // GAMEOBJECTCREATOR_H
