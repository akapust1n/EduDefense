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
    return path.it == path.path.end() - 1;
}

void Enemy::action() {
    if (distance(&(*path.it)) < speed) {
        x = path.it->getX();
        y = path.it->getY();
        path.it++;
    } else {
        moveToward((path.it)->getX(), (path.it)->getY());
    }
}
