#ifndef ACTIVEGAMEOBJECT_H
#define ACTIVEGAMEOBJECT_H

#include "gameobject.h"
#include <cstring>

/**
 * @brief Суть: игра каждые ? мс делает игровой цикл (loop).
 * Каждый loop инкрементирует loopCount.
 * Когда loopCount становится равен loopCountThreshold, вызывается action().
 */
class ActiveGameObject : public GameObject {
public:
    virtual ~ActiveGameObject() = 0;
    void loop();

protected:
    size_t loopCountThreshold;
    size_t loopCount = 0;
    virtual void action() = 0;
};

#endif // ACTIVEGAMEOBJECT_H
