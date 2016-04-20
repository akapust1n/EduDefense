#ifndef GAMEVIEW_H
#define GAMEVIEW_H
#include "menu.h"
#include <SFML/Graphics.hpp>
#include <memory>
#include <statemanger.h>
#include <gamemenu.h>

class GameView {

    sf::RenderWindow *window;
    std::shared_ptr<StateManager> m_statemanager;
    WaiterMenu *waiterMenu1;


  public:
     GameView(){}
     void setMenu(WaiterMenu &temp){waiterMenu1=&temp;}
    void setWindow(sf::RenderWindow &window2) { window = &window2; }
    void drawMainMenu(const Menu &menu);
    void drawMap();
    void drawLevelChoose(const LevelMenu &menu);
    void drawSettings();
    void drawStats();
    void drawLevel(int level_num);
    void highcolorTower(GameMenu &menu, hc item);
    void drawGameMenu(WaiterMenu &waiterMenu);

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
