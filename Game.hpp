#pragma once
#include "Player.hpp"

class Game
{
private:
    Player *player1;
    Player *player2;

public:
    Game(Player *p1, Player *p2);
    ~Game() {}

    void setup();
    void start();
    inline bool isGameOver() const { return player1->allShipsSunk() || player2->allShipsSunk(); }
};
