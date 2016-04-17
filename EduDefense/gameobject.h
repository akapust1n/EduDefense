#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class GameObject {
public:
   // virtual ~GameObject() = 0; а зачем?

    double getX();
    void setX(double x);
    double getY();
    void setY(double y);
    double getRadius();
    void setRadius(double radius);

    /**
     * @brief Пересекается ли объект с другим
     * @param gameObject
     * @return
     */
    bool isCollided(GameObject *gameObject);

protected:
    double x;
    double y;
    double radius;
};

#endif // GAMEOBJECT_H
