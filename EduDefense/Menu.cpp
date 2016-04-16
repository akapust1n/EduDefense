#include "Menu.h"
#include <Exceptions.h>

static const char *FONT = "fonts/9711.otf";
static const char *BG_IMG = "images/fon.jpg";
static const char *MUSIC = "music/MenuMusic.ogg";

Menu::Menu(double width, double height)
{
    if (!font.loadFromFile(FONT)) {
       throw(file_load_error());
    }
    menuItemsCount = 4;
    FontSize = 60;
    for(size_t i = 0; i< menuItemsCount; i++)
        menu[i].setCharacterSize(FontSize);

    menu[PLAY].setFont(font);
    menu[PLAY].setColor(sf::Color::Red);
    menu[PLAY].setString("Play");
    menu[PLAY].setPosition(sf::Vector2f(width / 3.5, height / (MAX_NUMBER_OF_ITEMS + 5) * 1 + 50));

    menu[OPTIONS].setFont(font);
    menu[OPTIONS].setColor(sf::Color::White);
    menu[OPTIONS].setString("Options");
    menu[OPTIONS].setPosition(sf::Vector2f(width / 3.5, height / (MAX_NUMBER_OF_ITEMS + 5) * 2 + 50));

    menu[STATS].setFont(font);
    menu[STATS].setColor(sf::Color::White);
    menu[STATS].setString("Statistics");
    menu[STATS].setPosition(sf::Vector2f(width / 3.5, height / (MAX_NUMBER_OF_ITEMS + 5) * 3 + 50));

    menu[QUIT].setFont(font);
    menu[QUIT].setColor(sf::Color::White);
    menu[QUIT].setString("Exit");
    menu[QUIT].setPosition(sf::Vector2f(width / 3.5, height / (MAX_NUMBER_OF_ITEMS + 5) * 4 + 50));

    selectedItemIndex = 0;

    if (!texture.loadFromFile(BG_IMG)) {
        throw(file_load_error());
    };

    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, width, height));
    sprite.setPosition(0, 0);

    if (!buffer.loadFromFile(MUSIC)) {
        throw(file_load_error());
    }
    sound.setBuffer(buffer);
    sound.play();
    sound.setLoop(true);
}

Menu::Menu() {}

Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
    //sprite.setTextureRect(sf::IntRect(0, 0, window.getSize().x, window.getSize().y));
    for (size_t i = 0; i < MAX_NUMBER_OF_ITEMS; i++) {
        window.draw(menu[i]);
    }

    // внутри главного цикла, между window.clear() и window.display()
}

void Menu::MoveUp()
{
    if (selectedItemIndex - 1 >= 0) {
        menu[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex--;
        menu[selectedItemIndex].setColor(sf::Color::Red);
    }
}

void Menu::MoveDown()
{
    if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS) {
        menu[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex++;
        menu[selectedItemIndex].setColor(sf::Color::Red);
    }
}
