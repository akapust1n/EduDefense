#include "defaulttower.h"

DefaultTower::DefaultTower(double x, double y) {
    this->x = x;
    this->y = y;
    radius = 30;
    range = 150;
    baseDamage = 20;
    damage = baseDamage;
    period = 2;
    loadSprite("images/Tower/FireTower.png");
}
