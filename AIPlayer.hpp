#pragma once
#include "Player.hpp"

class AIPlayer : public Player
{
private:
    std::string playerName;

public:
    AIPlayer(std::string &playerName) : Player(playerName) {}
    ~AIPlayer() {}

    void placeAllShips();
    void makeMove(Player *opponent);

    inline int getRandomCoordinate() { return std::rand() % BOARDSIZE; }
    inline int getRandomOrientation() { return std::rand() % 2; }
};
