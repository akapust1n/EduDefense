#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "Map.h"
class  Game
{
public:
     Game();
     void run();
     Menu menu;
     //MapCreator
private:
     size_t window_width;
     size_t window_height;
     sf::RenderWindow window;
};
