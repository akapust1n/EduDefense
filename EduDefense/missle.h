#ifndef MISSLE_H
#define MISSLE_H

#include <cstring>
#include "moveable.h"
#include "activegameobject.h"
#include "enemy.h"

class Missle : public Moveable, public ActiveGameObject {
public:
    virtual ~Missle() = 0;
    double getDamage();
    void setDamage(double damage);
    Enemy *getTarget();
    void setTarget(Enemy *target);
    bool isExploded();
protected:
    double damage;
    Enemy *target;
    bool exploded = false;
    void hitTarget();
    void action() override;
};

#endif // MISSLE_H
