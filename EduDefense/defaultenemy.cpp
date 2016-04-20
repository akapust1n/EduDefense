#include "defaultenemy.h"

DefaultEnemy::DefaultEnemy(double x1, double y1) {
    x = x1;
    y = y1;
    radius = 16;
    health = 100;
    bounty = 25;
    speed = 2;
    frequency = 0.2;
    loadSprite("images/Enemies/EnemySmall.png");
}
