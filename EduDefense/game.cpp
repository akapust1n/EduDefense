#include "gamemanager.h"
#include "gamemenu.h"
#include "map.h"
#include <game.h>
#include <gameview.h>
#include <iostream>

using namespace std;
Game::Game(size_t width, size_t height)
    : window(sf::VideoMode(width, height), GAME_TITLE), window_width(width),
      m_levelmenu(width, height), window_height(height), menu(width, height),
      m_Exit(false) {
    gameview.setMenu(waiterMenu);
    gameview.setWindow(window);
    controller.setWindow(window);
}

void Game::run() {
    player.setLife(10);
    player.setMoney(100);
    gameManager.setPlayer(player);
    int levelNum = 0;
    int gamerun_state = -1;
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
                levelNum = controller.MenuCont(m_levelmenu, event,
                                                MAX_NUMBER_OF_LEVEL_ITEMS, -1);
                if (levelNum == 0)
                    m_stateManager.setState(LevelRun);
                if (levelNum == 5)
                    m_stateManager.setState(MenuMain);
                break;
            }
            case LevelRun: {
                gamerun_state = controller.GameLevelCont(waiterMenu, event);
                break;
            }
            default:
                break;
            }
        }
        //отрисовки
        switch (m_stateManager.getcurrentState()) {
        case MenuMain:
            gameview.drawMainMenu(menu);
            break;
        case Levelchoose:
            gameview.drawLevelChoose(m_levelmenu);
            break;
        case LevelRun:
            gameview.drawLevel(levelNum);
            gameview.drawGameMenu(waiterMenu);
            if (gamerun_state == monsterRun || gamerun_state == btnPlay ) { //по-хорошему тут нужен ОТДЕЛЬНЫЙ класс
                gameManager.loop();
            }
            gameview.drawGameObjects(gameManager);

            break;
        case Quit:
            Exit();
            break;
        default:
            cout << "Smth strange happend(or window.close)";
            break;
        }
        window.display();
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
