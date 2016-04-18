#include "missle.h"

Missle::Missle(double x, double y, double speed, double damage, Enemy *target) {
    this->x = x;
    this->y = y;
    this->speed = speed;
    this->damage = damage;
    this->target = target;
    loopCount = 1; // например
}

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
