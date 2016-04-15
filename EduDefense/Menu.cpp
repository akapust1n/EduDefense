#include "Menu.h"

Menu::Menu(float width, float height)
{
    if (!font.loadFromFile("fonts/9711.otf")) {
        // handle error
    }

    menu[0].setFont(font);
    menu[0].setColor(sf::Color::Red);
    menu[0].setString("Play");
    menu[0].setPosition(sf::Vector2f(width / 4, height / (MAX_NUMBER_OF_ITEMS + 5) * 1));

    menu[1].setFont(font);
    menu[1].setColor(sf::Color::White);
    menu[1].setString("Options");
    menu[1].setPosition(sf::Vector2f(width / 4, height / (MAX_NUMBER_OF_ITEMS + 5) * 2));

    menu[2].setFont(font);
    menu[2].setColor(sf::Color::White);
    menu[2].setString("Statistics");
    menu[2].setPosition(sf::Vector2f(width / 4, height / (MAX_NUMBER_OF_ITEMS + 5) * 3));

    menu[3].setFont(font);
    menu[3].setColor(sf::Color::White);
    menu[3].setString("Exit");
    menu[3].setPosition(sf::Vector2f(width / 4, height / (MAX_NUMBER_OF_ITEMS + 5) * 4));

    selectedItemIndex = 0;

    if (!texture.loadFromFile("images/fon.jpg")) {
        // ошибка...
    };

    sprite.setTexture(texture);
    sprite.setTextureRect(IntRect(0, 0, width, height));
    sprite.setPosition(0, 0);

    if (!buffer.loadFromFile("music/MenuMusic.ogg")) {
        // ошибка...
    }
    sound.setBuffer(buffer);
    sound.play();
    sound.setLoop(true);
}

Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
    //sprite.setTextureRect(sf::IntRect(0, 0, window.getSize().x, window.getSize().y));
    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++) {
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
