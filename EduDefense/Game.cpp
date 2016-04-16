#include <Game.h>
#include <iostream>

using namespace std;
Game::Game(size_t width, size_t height)
    : window(sf::VideoMode(width, height), GAME_TITLE)
    , window_width(width)
    , window_height(height)
    , menu(width, height)
{
}

void Game::run()
{
    switch(menu.process(window)) {
    case PLAY:
        cout<<"PLAY";
        break;
    case OPTIONS:
        cout<<"OPTIONS";
        break;
    case STATS:
        cout<<"STATS";
        break;
    case QUIT:
        cout<<"QUIT";
        return;
    default:
        cout<<"This should not happen";
        break;
    }
}
