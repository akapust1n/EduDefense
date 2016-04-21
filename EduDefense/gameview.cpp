#include "gamemenu.h"
#include "map.h"
#include <gameview.h>
#include <vector>

void GameView::drawMainMenu(const Menu &menu) {
    window->clear();
    window->draw(menu.getSprite());
    const sf::Text *temp_menu = menu.getMenuList();
    for (size_t i = 0; i < MAX_NUMBER_OF_ITEMS; i++) {
        window->draw(temp_menu[i]);
    }
}

void GameView::drawLevelChoose(const LevelMenu &menu) {
    window->clear();
    window->draw(menu.getSprite());
    const sf::Text *temp_menu = menu.getMenuList();

    for (size_t i = 0; i < MAX_NUMBER_OF_LEVEL_ITEMS; i++) {
        window->draw(temp_menu[i]);
    }
}

void GameView::drawLevel(int level_num) {
    switch (level_num) {
    case 0: {
        static Waiter waiter;
        static UsualMapBuilder umap(*window, "maps/map.png", "maps/level1.txt");
        waiter.SetMapBuilder(&umap);
        waiter.ConstructMap();
    } break;
    default:
        break;
    }
}
void GameView::drawGameMenu(WaiterMenu &waiterMenu) {
    static UsualGameMenuBuilder umenu(*window, "maps/background.jpg");
    waiterMenu.SetGameMenuBuilder(&umenu);
    waiterMenu.ConstructGameMenu();
}

void GameView::highcolorTower(GameMenu &menu, gameMenuItem item) {}

void GameView::drawTower(sf::Vector2i coord, GameManager &gameManager,
                         gameMenuItem tower) {

    int size_free_areas = gameManager.getFreeAreas().size();
    std::vector<MapObject> temp = gameManager.getFreeAreas();
    for (int i = 0; i < size_free_areas; i++) {
        //  if( coord.x>temp[i].getX() and coord.x<(temp[i].getX()+60))
        //    if ( coord.y>temp[i].getY() and coord.y<(temp[i].getY()+60))
        addTowerMask(tower, coord);
    }
}

void GameView::addTowerMask(gameMenuItem type, sf::Vector2i coord) {
    TowerDrawMask temp;
    temp.type = type;
    temp.coord = coord;
    mask.push_back(temp);
}
void GameView::drawTowerMask() {
    sf::Image image;
    sf::Texture texture;
    sf::Sprite sprite;
    image.loadFromFile("images/Tower/FireTower.png");
    texture.loadFromImage(image); //заряжаем текстуру картинкой
    sprite.setTexture(texture);
    sprite.setTextureRect(IntRect(0, 0, 60, 60));
    for (int i = 0; i < mask.size(); i++) {
        sprite.setPosition(mask[i].coord.x, mask[i].coord.y);
        window->draw(sprite);
    }
    window->display(); //???????
}

void GameView::drawGameObjects(GameManager &gameManager) {
    for (Enemy *enemy : gameManager.getEnemies()) {
        enemy->draw(window);
    }
    for (Tower *tower : gameManager.getTowers()) {
        tower->draw(window);
    }
    for (Missile *missile : gameManager.getMissles()) {
        missile->draw(window);
    }
}
