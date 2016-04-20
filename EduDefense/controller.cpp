#include <controller.h>
#include <iostream>
#include <math.h>
using namespace sf;
//контроллер главного меню
int Controller::MenuCont(Menu &menu1, sf::Event event, int max_items, int def) {
    static int choose_flag = 0; //Флаг того, что что-то выбрано
    std::cout << "hey";
    switch (event.type) {
    case Event::MouseMoved: {
        pixelPos = Mouse::getPosition(*window); //забираем координаты курсора
        int i = 0;
        for (; i < max_items;
             i++) { //такая штука с циклом это плоховато, но т.к мало вариантов
            //клика -сойдет
            const Vector2f temp = menu1.getposition(menu1.ncgetMenuList(), i);
            if (ContainsMenuItem(temp))
                break;
        }
        if (i != max_items) {
            choose_flag = 1;
            menu1.setselectedItemIndex(menu1.ncgetMenuList(), i, max_items);
        } else {
            choose_flag = 0;
            menu1.clearselectedItemIdex(menu1.ncgetMenuList(), i, max_items);
        }
        break;
    }

    case sf::Event::KeyReleased:
        switch (event.key.code) {
        case sf::Keyboard::Up: {
            choose_flag = 1;
            menu1.moveUp(menu1.ncgetMenuList());
        } break;
        case sf::Keyboard::Down: {
            choose_flag = 1;
            menu1.moveDown(menu1.ncgetMenuList(), max_items);
        } break;
        case sf::Keyboard::Return:
            if (choose_flag == 1)
                return menu1.getselectedItemIndex();
            break;
        default:
            break;
        }
        break;
    case Event::MouseButtonPressed: { //если нажата клавиша мыши
        if (event.key.code == Mouse::Left)
            if (choose_flag == 1) { //если у нас выбран какой-то пункт меню
                menu1.clearselectedItemIdex(menu1.ncgetMenuList(),
                                            menu1.getselectedItemIndex(),
                                            max_items);
                return menu1.getselectedItemIndex();
            }
        break;
    }
    case sf::Event::Closed:
        window->close();
        break;
    default:
        break;
    }
    return def;
}

//проверяем подоходят ли координаты контроллера в меню
//ПОДБОР ЗНАЧЕНИЙ - ВИЗУАЛЬНО(что плохо)
//по-хорошему, вот такую штуку нужно делать для каждой клавиши в зависимости
//от длины её текста. но пока вот так
bool Controller::ContainsMenuItem(Vector2f coord) {
    if ((coord.x) < pixelPos.x and (pixelPos.x) < (coord.x + 240))
        if ((coord.y) < pixelPos.y and (pixelPos.y) < (coord.y + 80))
            return true;
    return false;
}

// "клики по итемам захаркдкожены". координаты взяты визуально, а надо их брать
// из gamemenu
int Controller::GameLevelCont(WaiterMenu &gamemenu1, sf::Event event) {
    // GameMenu gamemenu1.GetGameMenu()
    // std::cout<<"towerUNCLIK";
    std::shared_ptr<GameMenu> gamemenu = gamemenu1.GetGameMenu();
    switch (event.type) {
    case Event::MouseButtonPressed: { //если нажата клавиша мыши
        pixelPos = Mouse::getPosition(*window);
        if (event.key.code == Mouse::Left) { //а именно левая
            //-------------------Выделяем конкретную
            //башню--------------------------------
            if (pixelPos.x > 792 and pixelPos.x < 892) //первая башня
                if (pixelPos.y > 136 and pixelPos.y < 236) {
                    gamemenu->state = tower0;
                    break;
                } else if ((pixelPos.y > 279 and pixelPos.y < 379)) {
                    gamemenu->state = tower2;
                    break;
                }

            if (pixelPos.x > 908 and pixelPos.x < 1008)
                if (pixelPos.y > 136 and pixelPos.y < 236) {
                    gamemenu->state = tower1;
                    break;
                } else if ((pixelPos.y > 279 and pixelPos.y < 379)) {
                    gamemenu->state = tower3;
                    break;
                }
        }
        //смотрим не нажали мы кнопку play
        if (pixelPos.x > 790 and pixelPos.x < 1011)
            if (pixelPos.y > 527 and pixelPos.y < 657) {
                gamemenu->state = btnPlay;
                break;
            }
        std::cout << "towerCLICK";
        break;
    }
    default:
        break;
    }
}
