#include "Menu.h"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <Game.h>
#include "Map.h"
int main()
{
    //sf::RenderWindow window(sf::VideoMode(1024, 768), "Edu Defense");

    //Menu menu(window.getSize().x, window.getSize().y);


        //pizza->ShowMap();
/*
        SpicyPizzaBuilder spicyPizzaBuilder;
        waiter.SetPizzaBuilder(&spicyPizzaBuilder);
        waiter.ConstructPizza();
        pizza = waiter.GetPizza();
        pizza->ShowPizza();*/
    Game TheGame;
    TheGame.run();
return 0;
}
