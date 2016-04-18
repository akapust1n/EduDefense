#include "tower.h"

size_t Tower::getGrade() {
    return grade;
}

void Tower::setGrade(size_t grade) {
    this->grade = grade;
}

double Tower::getBaseDamage() {
    return damage;
}

void Tower::setBaseDamage(double baseDamage) {
    this->baseDamage = baseDamage;
}

double Tower::getDamage() {
    return damage;
}

double Tower::getRange() {
    return range;
}

void Tower::setRange(double range) {
    this->range = range;
}

Enemy *Tower::getTarget() {
    return target;
}

void Tower::setTarget(Enemy *target) {
    this->target = target;
}

void Tower::upgrade() {
    if (grade < MAX_GRADE) {
        grade++;
        damage = baseDamage * GRADE_FACTORS[grade];
    }
}

void Tower::shoot(Enemy *enemy) {

}

