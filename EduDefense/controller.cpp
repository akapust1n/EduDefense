#include <controller.h>
#include <iostream>
#include <math.h>
using namespace sf;
//контроллер главного меню
MenuItem Controller::MenuMain(Menu &menu1, sf::Event event) {
    static int choose_flag = 0; //Флаг того, что что-то выбрано
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
        if (i != MAX_NUMBER_OF_ITEMS) {
            choose_flag = 1;
            menu1.setselectedItemIndex(menu1.ncgetMenuList(), i,
                                       MAX_NUMBER_OF_ITEMS);
        } else {
            choose_flag = 0;
            menu1.clearselectedItemIdex(menu1.ncgetMenuList(), i,
                                        MAX_NUMBER_OF_ITEMS);
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
            menu1.moveDown(menu1.ncgetMenuList(), MAX_NUMBER_OF_ITEMS);
        } break;
        case sf::Keyboard::Return:
            if (choose_flag == 1)
                return (MenuItem)menu1.getselectedItemIndex();
            break;
        default:
            break;
        }
        break;
    case Event::MouseButtonPressed: { //если нажата клавиша мыши
        if (event.key.code == Mouse::Left)
          if (choose_flag == 1) //если у нас выбран какой-то пункт меню
              return (MenuItem)menu1.getselectedItemIndex();

    }
    case sf::Event::Closed:
        window->close();
        break;
    default:
        break;
    }
    return STAYHERE;
}

//проверяем подоходят ли координаты контроллера в меню
//ПОДБОР ЗНАЧЕНИЙ - ВИЗУАЛЬНО(что плохо)
//по-хорошему, вот такую штуку нужно делать для каждой клавиши в зависимости
//от длины её текста. но пока вот так
bool Controller::ContainsMenuItem(Vector2f coord) {
    if ((coord.x) < pixelPos.x and (pixelPos.x) < (coord.x + 240))
        if ((coord.y ) < pixelPos.y and (pixelPos.y) < (coord.y + 80))
            return true;
    return false;
}
