#ifndef GAME_H
#define GAME_H
#include "menu.h"
#include <SFML/Graphics.hpp>
#include <statemanger.h>
#include <gameobjectcreator.h>
#include <memory>
#define GAME_TITLE "Edu Defense"
#include <gameview.h>
#include "controller.h"
#include "player.h"
#include "gamemanager.h"
#include <gamemenu.h>
class Game {
  public:
    Game(size_t width, size_t height);

    void run();
    Menu menu;
    void Exit() { m_Exit = true; }
    state fromMenuItemtoState(MenuItem a);

  private:
    size_t window_width;
    size_t window_height;
    sf::RenderWindow window;
    GameView gameview;
    bool m_Exit;
    LevelMenu m_levelmenu;
    StateManager m_stateManager;
    Controller controller;
    WaiterMenu waiterMenu;
    GameManager gameManager;
    Player player;

};
#endif
