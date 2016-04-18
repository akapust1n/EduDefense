#include "map.h"
#include "gamemenu.h"
#include <game.h>
#include <gameview.h>
#include <iostream>

using namespace std;
Game::Game(size_t width, size_t height)
    : window(sf::VideoMode(width, height), GAME_TITLE), window_width(width),
      m_levelmenu(width, height),
      window_height(height), menu(width, height), m_Exit(false) {}

void Game::run() {
    int i = 0;

    while (window.isOpen() && !m_Exit) {
        sf::Event event;
        i++;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                Exit();
            }
        }
        switch (m_stateManager.getcurrentState()) {
        case MenuMain: {
            gameview.drawMainMenu(window, menu);
            MenuItem i = menu.process(window, gameview);
            m_stateManager.setState(fromMenuItemtoState(i));
            break;
        }
        case Levelchoose: { // потом тут будет выбор уровня, но пока его нет
            drawGame();
            //gameview.drawLevelChoose(window,);

            break;
        }
        case Quit: {
            Exit();
            break;
        }
        default:
            cout << "Smth strange happend";
        }
    }
    cout << i;
}

void Game::drawGame() {
    Waiter waiter;
    UsualMapBuilder umap(window, "maps/map.png");
    waiter.SetMapBuilder(&umap);
    waiter.ConstructMap();

    WaiterMenu waiterMenu;
    UsualGameMenuBuilder umenu(window, "maps/background.jpg");
    waiterMenu.SetGameMenuBuilder(&umenu);
    waiterMenu.ConstructGameMenu();
}

state Game::fromMenuItemtoState(MenuItem i) {
    switch (i) {
    case PLAY:
        return Levelchoose;
    case OPTIONS:
        return Options;
    case STATS:
        return Stats;
    case QUIT:
        return Quit;
    default:
        return MenuMain; //такого не должно произойти
    }
}
