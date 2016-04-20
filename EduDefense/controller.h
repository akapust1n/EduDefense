#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <SFML/Graphics.hpp>
#include <menu.h>
#include "gamemenu.h"
class Controller {
    sf::RenderWindow *window;
    sf::Vector2i pixelPos; //координаты курсора
    bool ContainsMenuItem(sf::Vector2f coord);
    const int accuracy_x = 10;
    const int accuracy_y = 10;

  public:
    Controller() {}
    void setWindow(sf::RenderWindow &window2) { window = &window2; }
    int MenuCont(Menu &menu1, sf::Event event, int max_items,
                      int def = (int)STAYHERE);
    int GameLevelCont(WaiterMenu &gamemenu, Event event);
};

#endif // CONTROLLER_H
