#ifndef DEFAULTTOWER_H
#define DEFAULTTOWER_H

#include "tower.h"

class DefaultTower : public Tower {
public:
    DefaultTower() {}
    ~DefaultTower() {}
    DefaultTower(double x, double y);
};

#endif // DEFAULTTOWER_H
