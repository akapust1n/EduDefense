#include "menu.h"
#include <SFML/Graphics.hpp>
#include <statemanger.h>
#include <gameobjectcreator.h>
#define GAME_TITLE "Edu Defense"

class Game {
  public:
    Game(size_t width, size_t height);

    void run();
    void drawGame();
    Menu menu;
    void Exit() { m_Exit = true; }
    state fromMenuItemtoState(MenuItem a);

  private:
    size_t window_width;
    size_t window_height;
    sf::RenderWindow window;
    StateManager m_stateManager;
    bool m_Exit;
};
