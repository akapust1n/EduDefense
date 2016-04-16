#include "enemy.h"

double Enemy::getHealth() {
    return health;
}

void Enemy::setHealth(double health) {
    this->health = health;
}

bool Enemy::isAlive() {
    return health > 0;
}
