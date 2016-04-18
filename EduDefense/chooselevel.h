#ifndef CHOOSELEVEL_H
#define CHOOSELEVEL_H
#include <SFML/Graphics.hpp>
#include <map.h>

class ChooseLevel {
public:
    void loadLevel(sf::RenderWindow &window );
    void loadMenuLevels(sf::sRenderWindow &window);
};

#endif // CHOOSELEVEL_H
