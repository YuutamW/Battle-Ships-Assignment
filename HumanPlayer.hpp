#pragma once
#include "Player.hpp"

class HumanPlayer : public Player
{
private:
    std::string playerName;

public:
    HumanPlayer(std::string &playerName) : Player(playerName) {}
    ~HumanPlayer() {}

    void placeAllShips();
    void makeMove(Player *opponent);
    
};
