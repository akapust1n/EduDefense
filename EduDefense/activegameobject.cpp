#include "activegameobject.h"

ActiveGameObject::~ActiveGameObject() {}

void ActiveGameObject::loop() {
    if (++loopCount == loopCountThreshold) {
        loopCount = 0;
        action();
    }
}
