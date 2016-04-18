#include "moveable.h"

#include <math.h>

Moveable::~Moveable() {}

double Moveable::getSpeed() {
    return speed;
}

void Moveable::setSpeed(double speed) {
    this->speed = speed;
}

void Moveable::moveToward(double x, double y) {
    // Направляющий вектор
    double dirX = x - this->x;
    double dirY = y - this->y;
    // Длина направляющего вектора
    double length = sqrt(dirX * dirX + dirY * dirY);
    // Единичный направляющий вектор
    dirX /= length;
    dirY /= length;
    this->x += dirX * speed;
    this->y += dirY * speed;
}
