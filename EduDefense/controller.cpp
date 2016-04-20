#include <controller.h>
#include <iostream>
#include <math.h>
using namespace sf;
MenuItem Controller::MenuMain(Menu &menu1, sf::Event event) {
    switch (event.type) {
    case Event::MouseMoved: {
        pixelPos = Mouse::getPosition(*window); //забираем координаты курсора
        int i = 0;
        for (; i < MAX_NUMBER_OF_ITEMS;
             i++) { //такая штука с циклом это плоховато, но т.к мало вариантов
                    //клика -сойдет
            const Vector2f temp = menu1.getposition(i);
            if (ContainsMenuItem(temp))
                break;
        }
        if (i != MAX_NUMBER_OF_ITEMS)
            menu1.setselectedItemIndex(menu1.ncgetMenuList(), i,
                                       MAX_NUMBER_OF_ITEMS);
        else
            menu1.clearselectedItemIdex(menu1.ncgetMenuList(), i,
                                         MAX_NUMBER_OF_ITEMS);
        break;
    }
    case sf::Event::KeyReleased:
        switch (event.key.code) {
        case sf::Keyboard::Up:
            menu1.moveUp(menu1.ncgetMenuList());
            break;
        case sf::Keyboard::Down:
            menu1.moveDown(menu1.ncgetMenuList(), MAX_NUMBER_OF_ITEMS);
            break;
        case sf::Keyboard::Return:
            return (MenuItem)menu1.getselectedItemIndex();
        default:
            break;
        }
        break;
    case sf::Event::Closed:
        window->close();
        break;
    default:
        break;
    }
    return STAYHERE;
}
//проверяем подоходят ли координаты контроллера в меню
//размер 120  40 -от балды
bool Controller::ContainsMenuItem(Vector2f coord) {
    if ((coord.x ) <pixelPos.x and
        (pixelPos.x ) < (coord.x + 400))
        if ((coord.y +90) > pixelPos.y and
            (pixelPos.y ) < (coord.y + 200))
            return true;
    return false;
}
