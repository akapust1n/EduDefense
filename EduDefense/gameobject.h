#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class GameObject
{
public:
    virtual ~GameObject() = 0;
    double getX();
    void setX(double x);
    double getY();
    void setY(double y);

protected:
    double x;
    double y;
};

#endif // GAMEOBJECT_H
