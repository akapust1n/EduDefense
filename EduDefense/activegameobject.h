#ifndef ACTIVEGAMEOBJECT_H
#define ACTIVEGAMEOBJECT_H

#include "gameobject.h"
#include <SFML/Graphics.hpp>

class ActiveGameObject : public GameObject {
public:
    virtual ~ActiveGameObject() = 0;
    void loop();

protected:
    sf::Clock clock;
    float period;
    virtual void action() = 0;
};

#endif // ACTIVEGAMEOBJECT_H
