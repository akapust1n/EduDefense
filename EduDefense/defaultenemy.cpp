#include "defaultenemy.h"

DefaultEnemy::DefaultEnemy(double x, double y) {
    this->x = x;
    this->y = y;
    radius = 16;
    health = 100;
    bounty = 25;
    speed = 2;
    loopCount = 1;
}
