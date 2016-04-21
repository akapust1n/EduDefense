#include "missile.h"

Missile::Missile(double x, double y, double speed, double damage, Enemy *target) {
    this->x = x;
    this->y = y;
    this->speed = speed;
    this->damage = damage;
    this->target = target;
    this->radius = 2;
    loadSprite("images/Bullets/PoisonBullet.png");
    period = 0.01;
}

double Missile::getDamage() {
    return damage;
}

void Missile::setDamage(double damage) {
    this->damage = damage;
}

Enemy *Missile::getTarget() {
    return target;
}

void Missile::setTarget(Enemy *target) {
    this->target = target;
}

bool Missile::isExploded() {
    return exploded;
}

void Missile::hitTarget() {
    target->setHealth(target->getHealth() - damage);
    exploded = true;
}

void Missile::action() {
    moveToward(target->getX(), target->getY());
    if (isCollided(target)) {
        hitTarget();
    }
}
