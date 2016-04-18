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
    void moveUp(sf::Text *menu1);
    void moveDown(sf::Text *menu1, int max_number);
     MenuItem process(sf::RenderWindow &window,GameView& gameview);
    sf::Sprite getSprite() const { return sprite; }
    virtual const sf::Text *getMenuList() const { return &menu[0]; }

  protected:
    int selectedItemIndex;
    sf::Font font;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::SoundBuffer buffer;
    sf::Sound sound;
    size_t FontSize;
    size_t menuItemsCount;\
private:
     sf::Text menu[MAX_NUMBER_OF_ITEMS];
};
class LevelMenu : public Menu {
public:
    LevelMenu(double width, double height) ;
    int process(sf::RenderWindow &window,GameView& gameview);
    virtual const sf::Text *getMenuList() const { return &levelMenu[0]; }
  private:
    sf::Text levelMenu[MAX_NUMBER_OF_LEVEL_ITEMS];
};
#endif
