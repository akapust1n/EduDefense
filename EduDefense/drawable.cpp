#include "drawable.h"

Drawable::~Drawable() {}

void Drawable::draw(sf::RenderWindow *window) {
    sprite.setPosition(x, y);
    window->draw(sprite);
}

void Drawable::loadSprite(std::string filename) {
    sf::Texture texture;
    texture.loadFromFile(filename);
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, 60, 60));
}
