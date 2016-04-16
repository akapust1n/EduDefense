#include "tower.h"

size_t Tower::getGrade() {
    return grade;
}

void Tower::setGrade(size_t grade) {
    this->grade = grade;
}

void Tower::upgrade() {
    if (grade < MAX_GRADE) {
        grade++;
        damage = baseDamage * GRADE_FACTORS[grade];
    }
}

void Tower::shoot(Enemy *enemy) {

}
