#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <SFML/Graphics.hpp>

#include "gameobject.h"

class Drawable : public GameObject {
public:
    ~Drawable() = 0;
    void draw(sf::RenderWindow *window);
    void loadSprite(std::string filename);
protected:
    sf::Sprite sprite;
};

#endif // DRAWABLE_H
