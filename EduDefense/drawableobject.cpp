#include "drawableobject.h"

DrawableObject::~DrawableObject() {}

void DrawableObject::draw(sf::RenderWindow *window) {
    sprite.setPosition(x, y);
    window->draw(sprite);
    //window->display();
}

void DrawableObject::loadSprite(std::string filename) {
    sf::Image image;
    image.loadFromFile(filename);
    sf::Texture texture;
    texture.loadFromImage(image);
    sprite.setTexture(texture);
}
