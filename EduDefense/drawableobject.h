#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <SFML/Graphics.hpp>

#include "activegameobject.h"

class DrawableObject : public ActiveGameObject {
public:
    ~DrawableObject() = 0;

    void draw(sf::RenderWindow *window);
    void loadSprite(std::string filename);

protected:
    sf::Sprite sprite;
    sf::Texture texture;
};

#endif // DRAWABLE_H
