#include "gamemenu.h"
#include "map.h"
#include <game.h>
#include <gameview.h>
#include <iostream>
#include "gamemanager.h"

using namespace std;
Game::Game(size_t width, size_t height)
    : window(sf::VideoMode(width, height), GAME_TITLE), window_width(width),
      m_levelmenu(width, height), window_height(height), menu(width, height),
      m_Exit(false) {
    gameview.setWindow(window);
    controller.setWindow(window);
}

void Game::run() {
    sf::Clock clock;
    float delay = 1;
    GameManager gameManager;
    Player player(100, 10);
    gameManager.setPlayer(player);
    int level_num = 0;
    // по-хорошему, это надо бы куда-то унести, но пока хз куда
    while (window.isOpen() && !m_Exit) {
        sf::Event event;
        //контроллеры
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) { //временное решение
                Exit();
            }
            switch (m_stateManager.getcurrentState()) {
            case MenuMain: {
                MenuItem i = (MenuItem)controller.MenuCont(menu, event,
                                                           MAX_NUMBER_OF_ITEMS);
                m_stateManager.setState(fromMenuItemtoState(i));
                break;
            }
            case Levelchoose: {
                int level_num = controller.MenuCont(
                    m_levelmenu, event, MAX_NUMBER_OF_LEVEL_ITEMS, -1);
                if (level_num == 0)
                    m_stateManager.setState(LevelRun);
                if (level_num == 5)
                    m_stateManager.setState(MenuMain);

                break;
            }
            default:
                break;
            }
        }
       //отрисовки
        switch (m_stateManager.getcurrentState()) {
        case MenuMain: {
            gameview.drawMainMenu(menu);

            break;
        }
        case Levelchoose: {

            gameview.drawLevelChoose(m_levelmenu);
            // level_num = m_levelmenu.process(window, gameview);
            // m_stateManager.setState(LevelRun);
            break;
        }
        case LevelRun: {
            //тут должен использовать level_num
            gameview.drawLevel(level_num);
            // gameview.drawLevelCh;
            if (clock.getElapsedTime().asSeconds() > delay) {
                gameManager.loop();
                clock.restart();
            }
            break;
        }
        case Quit: {
            Exit();
            break;
        }

        break;
        default:
            cout << "Smth strange happend(or window.close)";
        }
    }
}

//что-то мне подсказывает, что можно обойтись одним enum
state Game::fromMenuItemtoState(MenuItem i) {
    switch (i) {
    case STAYHERE:
        return MenuMain;
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
