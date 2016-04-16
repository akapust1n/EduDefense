#ifndef TOWER_H
#define TOWER_H

#include <gameobject.h>

enum Grade {ONE, TWO, THREE};

class Tower : public GameObject
{
public:
    virtual ~Tower() = 0;
private:
     Grade grade;
     //Missle missle;
};

#endif // TOWER_H
