#include "menu.h"
#include <SFML/Graphics.hpp>

#define GAME_TITLE "Edu Defense"

class Game {
  public:
    Game(size_t width, size_t height);
    void run();
    Menu menu;
    void Exit() { m_Exit = true; }

  private:
    size_t window_width;
    size_t window_height;
    sf::RenderWindow window;
    bool m_Exit;
};
