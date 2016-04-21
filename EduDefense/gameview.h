#ifndef GAMEVIEW_H
#define GAMEVIEW_H
#include "menu.h"
#include <SFML/Graphics.hpp>
#include <gamemanager.h>
#include <gamemenu.h>
#include <memory>
#include <statemanger.h>
class TowerDrawMask {
public:
    gameMenuItem type;
    sf::Vector2i coord;
};

class GameView {
    sf::RenderWindow *window;
    std::shared_ptr<StateManager> m_statemanager;
    WaiterMenu *waiterMenu1;
    std::vector<TowerDrawMask> mask;

  public:
    GameView() {}
    void addTowerMask(gameMenuItem type,sf::Vector2i coord);
    void setMenu(WaiterMenu &temp) { waiterMenu1 = &temp; }
    void setWindow(sf::RenderWindow &window2) { window = &window2; }
    void drawMainMenu(const Menu &menu);
    void drawMap();
    void drawLevelChoose(const LevelMenu &menu);
    void drawSettings();
    void drawStats();
    void drawLevel(int level_num);
    void highcolorTower(GameMenu &menu, gameMenuItem item);
    void drawGameMenu(WaiterMenu &waiterMenu);
    void drawTower(sf::Vector2i coord, GameManager &gameManager, gameMenuItem tower);
    void drawTowerMask();
    void drawGameObjects(GameManager &gameManager);

};

#endif // GAMEVIEW_H
