#ifndef GAMEVIEW_H
#define GAMEVIEW_H
#include "menu.h"
#include <SFML/Graphics.hpp>
#include <memory>
#include <statemanger.h>
class GameView {

    sf::RenderWindow *window;
    std::shared_ptr<StateManager> m_statemanager;

  public:
     GameView() {}
    void setWindow(sf::RenderWindow &window2) { window = &window2; }
    void drawMainMenu(const Menu &menu);
    void drawMap();
    void drawLevelChoose(const LevelMenu &menu);
    void drawSettings();
    void drawStats();
    void drawLevel(int level_num);
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
