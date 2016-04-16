#ifndef ENEMY_H
#define ENEMY_H

#include "gameobject.h"

class Enemy : public GameObject
{
public:
    virtual ~Enemy() = 0;
    int getHealth();
    void setHealth(int health);
    bool isAlive();
private:
    int health;
};

#endif // ENEMY_H
