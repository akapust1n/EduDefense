#ifndef ENEMY_H
#define ENEMY_H

#include "moveable.h"

class Enemy : public Moveable {
public:
    virtual ~Enemy() = 0;

    double getHealth();
    void setHealth(double health);
    size_t getBounty();
    void setBounty(size_t bounty);
    bool isAlive();

private:
    double health;
    size_t bounty;
};

#endif // ENEMY_H
