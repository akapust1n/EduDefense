#ifndef MISSLE_H
#define MISSLE_H

#include <cstring>

#include "moveable.h"

class Missle : public Moveable
{
public:
    virtual ~Missle() = 0;

    double getDamage();
    void setDamage(double damage);

protected:
    double damage;
};

#endif // MISSLE_H
