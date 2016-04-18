#include "gamemanager.h"

#include <algorithm>

GameManager::GameManager() {

}

Player GameManager::getPlayer() {
    return player;
}

void GameManager::setPlayer(Player player) {
    this->player = player;
}

std::vector<GameObject *> GameManager::getStones() {
    return stones;
}

void GameManager::setStones(std::vector<GameObject *> stones) {
    this->stones = stones;
}

std::vector<GameObject *> GameManager::getFreeAreas() {
    return freeAreas;
}

void GameManager::setFreeAreas(std::vector<GameObject *> freeAreas) {
    this->freeAreas = freeAreas;
}

std::vector<GameObject *> GameManager::getRoads() {
    return roads;
}

void GameManager::setRoads(std::vector<GameObject *> roads) {
    this->roads = roads;
}

std::vector<Tower *> GameManager::getTowers() {
    return towers;
}

std::vector<Enemy *> GameManager::getEnemies() {
    return enemies;
}

std::vector<Missle *> GameManager::getMissles() {
    return missles;
}

void GameManager::loop() {
    for (std::vector<Enemy *>::iterator it = enemies.begin(); it != enemies.end(); ) {
        if (!(*it)->isAlive()) {
            // удаляем мертвых и начисляем игроку награду
            player.setMoney(player.getMoney() + (*it)->getBounty());
            enemies.erase(it);
        } else {
            // TODO: перемещение врага
            it++;
        }
    }
    for (Tower *tower : towers) {
        // Установка цели башни на враге в зоне досягаемости
        if (tower->getTarget() == NULL) {
            for (Enemy *enemy : enemies) {
                if (tower->distance(enemy) < tower->getRange()) {
                    tower->setTarget(enemy);
                    break;
                }
            }
        }
        if (tower->getTarget() != NULL) {
            // запускаем ракету (скорость пока магическое число)
            missles.push_back(new Missle(tower->getX, tower->getY, 0.1, tower->getDamage(), tower->getTarget()));
        }
        tower->loop();
    }
    for (std::vector<Missle *>::iterator it = missles.begin(); it != missles.end(); ) {
        if ((*it)->isExploded()) {
            missles.erase(it);
        } else {
            (*it)->loop();
            it++;
        }
    }
}
