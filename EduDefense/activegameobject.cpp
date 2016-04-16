#include "activegameobject.h"

void ActiveGameObject::loop() {
    if (++loopCount == loopCountThreshold) {
        loopCount = 0;
        action();
    }
}
