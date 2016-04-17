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
   std:: vector<GameObject> stones;
    std::vector<GameObject> freeareas;
    std::vector<GameObject> roads;
    int get_num_stones() { return num_stones; }
    int get_num_freeares() { return num_freeares; }
    int get_num_roads() { return num_roads; }

  private:
    void readfile();
    map_state case_map_state(char temp);
    std::string file;
    std::string map_states;
    int num_stones;
    int num_freeares;
    int num_roads;
    const int texture_size = 32; //размер текстурки
};

#endif // GAMEOBJECTCREATOR_H
