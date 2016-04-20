#ifndef ENEMY_H
#define ENEMY_H

#include "moveable.h"
#include "path.h"

class Enemy : public Moveable {
public:
    virtual ~Enemy() = 0;

    double getHealth();
    void setHealth(double health);
    size_t getBounty();
    void setBounty(size_t bounty);
    bool isAlive();
    bool isPassed();
    void action() override;
protected:
    double health;
    size_t bounty;
    Path path;
};

#endif // ENEMY_H
