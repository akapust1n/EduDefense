#ifndef ENEMY_H
#define ENEMY_H

#include "moveable.h"
#include "activegameobject.h"

class Enemy : public Moveable, public ActiveGameObject {
public:
    virtual ~Enemy() = 0;

    int getHealth();
    void setHealth(int health);
    bool isAlive();

private:
    int health;
};

#endif // ENEMY_H
