#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
public:
    Player() {}
    Player(size_t money1, size_t life1);

    size_t getMoney() { return money; }
    void setMoney(size_t money) { this->money = money; }
    size_t getLife() { return life; }
    void setLife(size_t life) { this->life = life; }

private:
    size_t money;
    size_t life;
};

#endif // PLAYER_H
