#pragma once
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"

#define MAX_NUMBER_OF_ITEMS 4
#define MAX_NUMBER_OF_LEVEL_ITEMS 5

enum MenuItem { PLAY, OPTIONS, STATS, QUIT };

class Menu {
  public:
    Menu();
    Menu(double width, double height);
    ~Menu();

    void draw(sf::RenderWindow &window);
    void moveUp();
    void moveDown();
    MenuItem process(sf::RenderWindow &window);

  protected:
    int selectedItemIndex;
    sf::Font font;
    sf::Text menu[MAX_NUMBER_OF_ITEMS];
    sf::Texture texture;
    sf::Sprite sprite;
    sf::SoundBuffer buffer;
    sf::Sound sound;
    size_t FontSize;
    size_t menuItemsCount;
};
class LevelMenu : public Menu {
    LevelMenu(double width, double height) : Menu(width, height) {}
private:
    sf::Text levelMenu[MAX_NUMBER_OF_LEVEL_ITEMS ];

};
