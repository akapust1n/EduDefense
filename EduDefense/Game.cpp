#include <Game.h>
#include <iostream>
using namespace std;
Game::Game()
    : window_width(1024)
    , window_height(768)
    , window(sf::VideoMode(1024, 768), "Edu Defense")
    , menu(1024, 768)
{
}

void Game::run()
{
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::KeyReleased:
                switch (event.key.code) {
                case sf::Keyboard::Up:
                    menu.MoveUp();
                    break;
                case sf::Keyboard::Down:
                    menu.MoveDown();
                    break;
                case sf::Keyboard::Return:
                    switch (menu.GetPressedItem()) {
                    case 0:
                        std::cout << "Play button has been pressed" << std::endl;
                        break;
                    case 1:
                        std::cout << "Option button has been pressed" << std::endl;
                        break;
                    case 2:
                        std::cout << "Statistic button has been pressed" << std::endl;
                        break;
                    case 3:
                        window.close();
                        break;
                    default:
                        break;
                    }
                    break;
                default:
                    break;
                }
                break;
            case sf::Event::Closed:
                window.close();
                break;
            default:
                break;
            }
        }
        window.clear();
        menu.draw(window);
        window.display();
    }

}
