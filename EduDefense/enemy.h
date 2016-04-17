#ifndef ENEMY_H
#define ENEMY_H

#include "moveable.h"
#include "activegameobject.h"

class Enemy : public Moveable, public ActiveGameObject {
public:
    virtual ~Enemy() = 0;

    double getHealth();
    void setHealth(double health);
    bool isAlive();

private:
    double health;
};

#endif // ENEMY_H
