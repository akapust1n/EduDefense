#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

#define MAX_NUMBER_OF_ITEMS 4

enum MenuItem {
    PLAY,
    OPTIONS,
    STATS,
    QUIT
};

class Menu {
public:
    Menu();
    Menu(double width, double height);
    ~Menu();

    void draw(sf::RenderWindow& window);
    void moveUp();
    void moveDown();
    MenuItem process(sf::RenderWindow& window);

private:
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
