#ifndef KIND_MAPS_H
#define KIND_MAPS_H
#include "gameobject.h"
//что может быть на карте
enum map_state { freearea, road, stone,not_map_element };
//что есть на карте
class MapObject : public GameObject {
  public:
    MapObject(double x1, double y1, map_state kind1) : kind(kind1) {
        x = x1;
        y = y1;
    }
    ~MapObject() {}


    map_state kind;
};

#endif // KIND_MAPS_H
