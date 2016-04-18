#ifndef MENU_H
#define MENU_H
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#define MAX_NUMBER_OF_ITEMS 4
#define MAX_NUMBER_OF_LEVEL_ITEMS 5
class GameView;
enum MenuItem { PLAY, OPTIONS, STATS, QUIT };

class Menu {
  public:
    Menu();
    Menu(double width, double height);
    ~Menu();

    void draw(sf::RenderWindow &window);
    void moveUp();
    void moveDown();
    MenuItem process(sf::RenderWindow &window,GameView& gameview);
    sf::Sprite getSprite() const { return sprite; }
    const sf::Text *getMenuList() const { return &menu[0]; }

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
public:
    LevelMenu(double width, double height) ;

  private:
    sf::Text levelMenu[MAX_NUMBER_OF_LEVEL_ITEMS];
};
#endif
