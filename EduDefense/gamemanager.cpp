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

}
