#ifndef GAMEOBJECTCREATOR_H
#define GAMEOBJECTCREATOR_H
#include "gameobject.h"
#include <string>

class ObjectsCreator {
  public:
    ObjectsCreator(std::string filename) : file(filename){}
    GameObject *stones;
    GameObject *freeareas;
    GameObject *roads;
    int get_num_stones() { return num_stones; }
    int get_num_freeares() { return num_freeares; }
    int get_num_roads() { return num_roads; }

  private:
    void readfile();
    std::string file;
    std::string *map;
    int num_stones;
    int num_freeares;
    int num_roads;
    const int texture_size = 32; //размер текстурки
};

#endif // GAMEOBJECTCREATOR_H
