#pragma once
#include "Player.hpp"
#include <queue>

class AIPlayer : public Player
{
private:
    std::queue<std::pair<int,int>> pendingTarget;
    
    void queueNeighbours(int r, int c, const Grid& opponentGrid);
public:
    AIPlayer(const std::string &playerName) : Player(playerName) {}
    ~AIPlayer() {}

    void placeAllShips();
    void makeMove(Player *opponent);

    inline int getRandomCoordinate() { return std::rand() % BOARDSIZE; }
    inline int getRandomOrientation() { return std::rand() % 2; }
};
