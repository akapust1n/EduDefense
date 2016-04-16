#include <SFML/Graphics.hpp>
#include "Menu.h"

#define GAME_TITLE "Edu Defense"

class  Game {
public:
     Game(size_t width, size_t height);
     void run();
     Menu menu;

private:
     size_t window_width;
     size_t window_height;
     sf::RenderWindow window;
};
