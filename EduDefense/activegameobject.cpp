#include "activegameobject.h"

ActiveGameObject::~ActiveGameObject() {}

void ActiveGameObject::loop() {
    if (clock.getElapsedTime().asSeconds() > period) {
        action();
        clock.restart();
    }
}
