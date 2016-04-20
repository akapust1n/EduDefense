#include <controller.h>
#include <iostream>
#include <math.h>
using namespace sf;
MenuItem Controller::MenuMain(Menu &menu1, sf::Event event) {
    switch (event.type) {
    case Event::MouseMoved: {
        pixelPos = Mouse::getPosition(*window); //забираем координаты курсора
        for (int i = 0; i < MAX_NUMBER_OF_ITEMS;
             i++) { //такая штука с циклом это плоховато, но т.к мало вариантов
                    //клика -сойдет
            const Vector2f temp = menu1.getposition(i);
            if (ContainsMenuItem(temp))
                std::cout << "вин";
        }
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
    }
}
//проверяем подоходят ли координаты контроллера в меню
//размер 120  40 -от балды
bool Controller::ContainsMenuItem(Vector2f coord) {
    if ((coord.x + accuracy_x) > pixelPos.x and
        (pixelPos.x - accuracy_x) < (coord.x + 120))
        if ((coord.y + accuracy_y) > pixelPos.y and
            (pixelPos.y - accuracy_y) < (coord.y + 50))
            return true;
    return false;
}
