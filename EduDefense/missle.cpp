#include "missle.h"

double Missle::getDamage() {
    return damage;
}

void Missle::setDamage(double damage) {
    this->damage = damage;
}

Enemy *Missle::getTarget() {
    return target;
}

void Missle::setTarget(Enemy *target) {
    this->target = target;
}

bool Missle::isExploded() {
    return exploded;
}

void Missle::hitTarget() {
    target->setHealth(target->getHealth() - damage);
    exploded = true;
}

void Missle::action() {
    moveToward(target->getX(), target->getY());
    if (isCollided(target)) {
        hitTarget();
    }
}
