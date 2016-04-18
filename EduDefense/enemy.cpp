#include "enemy.h"

double Enemy::getHealth() {
    return health;
}

void Enemy::setHealth(double health) {
    this->health = health;
}

size_t Enemy::getBounty() {
    return bounty;
}

void Enemy::setBounty(size_t bounty) {
    this->bounty = bounty;
}

bool Enemy::isAlive() {
    return health > 0;
}
