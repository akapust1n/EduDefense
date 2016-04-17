#ifndef MOVEABLE_H
#define MOVEABLE_H

#include "gameobject.h"

class Moveable : public GameObject {
public:
    virtual ~Moveable() = 0;
    double getSpeed();
    void setSpeed(double speed);

    /**
     * @brief Объект приблизится к точке с координатами (x, y),
     * переместившись на speed
     * @param x
     * @param y
     */
    void moveToward(double x, double y);

protected:
    double speed;
};

#endif // MOVEABLE_H
