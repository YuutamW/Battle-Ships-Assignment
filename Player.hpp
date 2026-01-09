#pragma once
#include "Grid.hpp"
#include "Ship.hpp"
using std::string;
#define SHIPSAMOUNT 5

class Player
{
private:
    string playerName;
    Ship *ships[SHIPSAMOUNT];
    Grid grid;
    int numOfShipsAlive = SHIPSAMOUNT;

public:
    Player(const string &name);
    virtual ~Player();
    virtual void placeAllShips() {}
    virtual void makeMove(Player *opponent) {}

    inline bool allShipsSunk() const { return numOfShipsAlive <= 0; }

    inline void displayGrid() const { grid.printGrid(); }

    inline string getPlayerName() { return playerName; };
    inline Ship *getShip(int index) { return ships[index]; }
    inline Grid getGrid() { return grid; }
    inline int numOfShipsAlive() { return numOfShipsAlive; }
    bool recievAttack(int row, int col);
};
