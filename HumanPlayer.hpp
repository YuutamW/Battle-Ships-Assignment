#pragma once
#include "Player.hpp"

class HumanPlayer : public Player
{
private:

public:
    HumanPlayer(const std::string &playerName) : Player(playerName) {}
    ~HumanPlayer() {}

    void placeAllShips();
    void makeMove(Player *opponent);
    
};
