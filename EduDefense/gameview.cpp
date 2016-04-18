#include "gamemenu.h"
#include "map.h"
#include <gameview.h>

/*GameView::GameView(std::shared_ptr<StateManager> &temp)   {
    m_statemanager=temp;
}*/

void GameView::drawMainMenu(const Menu &menu) {
    window->clear();
    window->draw(menu.getSprite());
    const sf::Text *temp_menu = menu.getMenuList();
    for (size_t i = 0; i < MAX_NUMBER_OF_ITEMS; i++) {
        window->draw(temp_menu[i]);
    }
    window->display();
}
void GameView::drawLevelChoose(const LevelMenu &menu){
    window->clear();
    window->draw(menu.getSprite());
    const sf::Text *temp_menu = menu.getMenuList();

    for (size_t i = 0; i < MAX_NUMBER_OF_LEVEL_ITEMS; i++) {
        window->draw(temp_menu[i]);
    }
    window->display();

}
void GameView::drawLevel(int level_num)
{
   switch(level_num)
   {
   case 0:{
       Waiter waiter;
       UsualMapBuilder umap(*window, "maps/map.png");
       waiter.SetMapBuilder(&umap);
       waiter.ConstructMap();

       WaiterMenu waiterMenu;
       UsualGameMenuBuilder umenu(*window, "maps/background.jpg");
       waiterMenu.SetGameMenuBuilder(&umenu);
       waiterMenu.ConstructGameMenu();
       break;
   }
   case 1:
       break;
   }
}

//void GameView::Dr
