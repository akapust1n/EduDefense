#ifndef KIND_MAPS_H
#define KIND_MAPS_H

#include "gameobject.h"

enum Area { ERROR, FREE, ROAD, STONE };

class MapObject : public GameObject {
  public:
    MapObject(double x, double y, Area area) {
        this->x = x;
        this->y = y;
        this->area = area;
    }
    ~MapObject() {}

    Area getArea() { return area; }
    void setArea(Area area) { this->area = area; }


private:
    Area area;
};

#endif // KIND_MAPS_H
