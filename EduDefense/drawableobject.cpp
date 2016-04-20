#include "drawableobject.h"

DrawableObject::~DrawableObject() {}

void DrawableObject::draw(sf::RenderWindow *window) {
    sprite.setPosition(x, y);
    window->draw(sprite);
    //window->display();
}

void DrawableObject::loadSprite(std::string filename) {
    texture.loadFromFile(filename);
    sprite.setTexture(texture);
}
