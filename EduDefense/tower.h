#ifndef TOWER_H
#define TOWER_H

#include "gameobject.h"
#include "enemy.h"
#include "missle.h"

static const size_t MAX_GRADE = 2;
static const double GRADE_FACTORS[] {1.0, 1.4, 2.0};

class Tower : public GameObject
{
public:
    virtual ~Tower() = 0;

    size_t getGrade();
    void setGrade(size_t grade);
    double getBaseDamage();
    void setBaseDamage(double baseDamage);
    double getRange();
    void setRange(double range);
    void upgrade();
    /**
     * @brief Запускает снаряд во врага
     * @param enemy
     */
    void shoot(Enemy *enemy);

protected:
    size_t grade;
    double baseDamage;
    double damage = baseDamage;
    double range;
};

#endif // TOWER_H
