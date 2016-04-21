#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <SFML/Graphics.hpp>
#include <menu.h>
#include "gamemenu.h"

class Controller {
    sf::RenderWindow *window;
    sf::Vector2i pixelPos; //координаты курсора
    bool ContainsMenuItem(sf::Vector2f coord);
    const int accuracyX = 10;
    const int accuracyY = 10;
    gameMenuItem currentTower = empty;
  public:
    Controller() {}
    gameMenuItem getCurrentTower(){return currentTower;}
    void setWindow(sf::RenderWindow &window2) { window = &window2; }
    int MenuCont(Menu &menu1, sf::Event event, int max_items,
                      int def = (int)STAYHERE);
    int GameLevelCont(WaiterMenu &gamemenu, Event event);
     sf::Vector2i TowerPickCont();
};

#endif // CONTROLLER_H
