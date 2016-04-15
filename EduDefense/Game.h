#include <SFML/Graphics.hpp>
#include "Menu.h"
class  Game
{
public:
     Game();
     void run();
     Menu menu;
private:
     size_t window_width;
     size_t window_height;
     sf::RenderWindow window;
};
