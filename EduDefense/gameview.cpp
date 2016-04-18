#include "gameview.h"
/*GameView::GameView(std::shared_ptr<StateManager> &temp)   {
    m_statemanager=temp;
}*/

void GameView::drawMainMenu(sf::RenderWindow &window, const Menu &menu) {
    window.clear();
    window.draw(menu.getSprite());
    const sf::Text *temp_menu = menu.getMenuList();
    for (size_t i = 0; i < MAX_NUMBER_OF_ITEMS; i++) {
        window.draw(temp_menu[i]);
    }
    window.display();
}
void GameView::drawLevelChoose(sf::RenderWindow &window, const LevelMenu &menu){
    window.clear();
    window.draw(menu.getSprite());
    const sf::Text *temp_menu = menu.getMenuList();

    for (size_t i = 0; i < MAX_NUMBER_OF_LEVEL_ITEMS; i++) {
        window.draw(temp_menu[i]);
    }
    window.display();


}
