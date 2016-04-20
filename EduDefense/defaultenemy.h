#ifndef DEFAULTENEMY_H
#define DEFAULTENEMY_H

#include "enemy.h"

class DefaultEnemy : public Enemy
{
public:
    DefaultEnemy() {}
    DefaultEnemy(double x, double y);
    ~DefaultEnemy() {}
};

#endif // DEFAULTENEMY_H
