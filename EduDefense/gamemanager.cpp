#include "gamemanager.h"

#include "defaultenemy.h"
#include "defaulttower.h"

GameManager::GameManager() {
    enemies.push_back(new DefaultEnemy(-60, 60));
    towers.push_back(new DefaultTower(300, 120));
    //---------
}

Player GameManager::getPlayer() {
    return player;
}

void GameManager::setPlayer(Player player) {
    this->player = player;
}

std::vector<MapObject> GameManager::getStones() {
    return stones;
}

void GameManager::setStones(std::vector<MapObject> stones) {
    this->stones = stones;
}

std::vector<MapObject> GameManager::getFreeAreas() {
    return freeAreas;
}

void GameManager::setFreeAreas(std::vector<MapObject> freeAreas) {
    this->freeAreas = freeAreas;
}

std::vector<MapObject> GameManager::getRoads() {
    return roads;
}

void GameManager::setRoads(std::vector<MapObject> roads) {
    this->roads = roads;
}

std::vector<Tower *> GameManager::getTowers() {
    return towers;
}

std::vector<Enemy *> GameManager::getEnemies() {
    return enemies;
}

std::vector<Missile> GameManager::getMissles() {
    return missiles;
}

void GameManager::loop() {
    // тут в enemies должен добавляться следующий монстр из волны, если прошла задержка


    for (std::vector<Enemy *>::iterator it = enemies.begin(); it != enemies.end(); ) {
        if (!(*it)->isAlive()) {
            // удаляем мертвых и начисляем игроку награду
            player.setMoney(player.getMoney() + (*it)->getBounty());
            delete *it;
            it = enemies.erase(it);
        } else {
            (*it)->loop();
            if ((*it)->isPassed()) {
                delete *it;
                it = enemies.erase(it);
                player.setLife(player.getLife() - 1);
            } else {
                it++;
            }
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
        if (tower->getTarget() != NULL && tower->isReady()) {
            // запускаем ракету (скорость пока магическое число)
            Missile missile(tower->getX(), tower->getY(), 10, tower->getDamage(),
                          tower->getTarget());
            missiles.push_back(missile);
            tower->setReady(false);
        }
        tower->loop();
    }
    for (std::vector<Missile>::iterator it = missiles.begin(); it != missiles.end(); ) {
        if (it->isExploded()) {
            it = missiles.erase(it);
        } else {
            it->loop();
            it++;
        }
    }
}
