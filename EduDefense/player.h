#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
public:
    Player();

    size_t getMoney() { return money; }
    void setMoney(size_t money) { this->money = money; }
    size_t getLife() { return life; }
    void setLife(size_t life) { this->life = life; }

private:
    size_t money;
    size_t life;
};

#endif // PLAYER_H
