#include "enemy.h"

Enemy::~Enemy() {}

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

bool Enemy::isPassed() {
    return path.it == path.path.end();
}

void Enemy::action() {
    moveToward((path.it)->getX(), (path.it)->getY());
    if (distance(&(*path.it)) < 1e-5) {
        path.it++;
    }
}
