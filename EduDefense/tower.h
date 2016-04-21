#ifndef TOWER_H
#define TOWER_H

#include "gameobject.h"
#include "enemy.h"
#include "missile.h"

static const size_t MAX_GRADE = 2;
static const double GRADE_FACTORS[] {1.0, 1.4, 2.0}; // множители урона

class Tower : public DrawableObject {
public:
    virtual ~Tower() = 0;

    size_t getGrade();
    void setGrade(size_t grade);
    double getBaseDamage();
    void setBaseDamage(double baseDamage);
    double getDamage();
    double getRange();
    void setRange(double range);
    Enemy *getTarget();
    void setTarget(Enemy *target);
    bool isReady();
    void setReady(bool ready);
    void upgrade();
    void action() override;

protected:
    size_t grade = 0;
    double baseDamage;
    double damage = baseDamage;
    double range;
    Enemy *target = NULL;
    bool ready = false;
};

#endif // TOWER_H
