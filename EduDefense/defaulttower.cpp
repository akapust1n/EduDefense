#include "defaulttower.h"

DefaultTower::DefaultTower(double x, double y) {
    this->x = x;
    this->y = y;
    radius = 30;
    range = 200;
    baseDamage = 20;
    frequency = 2;
    loadSprite("images/Tower/FireTower.png");
}
