#include "enemy.h"

int Enemy::getHealth() {
    return health;
}

void Enemy::setHealth(int health) {
    this->health = health;
}

bool Enemy::isAlive() {
    return health <= 0;
}
