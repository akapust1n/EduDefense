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
    hc type;
    sf::Vector2i coord;
};

class GameView {
    sf::RenderWindow *window;
    std::shared_ptr<StateManager> m_statemanager;
    WaiterMenu *waiterMenu1;
    std::vector<TowerDrawMask> mask;

  public:
    GameView() {}
    void addTowerMask(hc type,sf::Vector2i coord);
    void setMenu(WaiterMenu &temp) { waiterMenu1 = &temp; }
    void setWindow(sf::RenderWindow &window2) { window = &window2; }
    void drawMainMenu(const Menu &menu);
    void drawMap();
    void drawLevelChoose(const LevelMenu &menu);
    void drawSettings();
    void drawStats();
    void drawLevel(int level_num);
    void highcolorTower(GameMenu &menu, hc item);
    void drawGameMenu(WaiterMenu &waiterMenu);
    void drawTower(sf::Vector2i coord, GameManager &gameManager, hc tower);
    void drawTowerMask();
    void drawGameObjects(GameManager &gameManager);

};

/*
enum state{
    MenuMain,
    Levelchoose,
    LevelRun,
    Options,
    Stats,
    Quit
};
*/
#endif // GAMEVIEW_H
