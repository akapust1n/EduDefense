#include "activegameobject.h"

ActiveGameObject::~ActiveGameObject() {}

void ActiveGameObject::loop() {
    if (clock.getElapsedTime().asSeconds() > frequency) {
        action();
        clock.restart();
    }
}
