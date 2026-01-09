#pragma once
#include "Grid.hpp"
#include "Ship.hpp"
using std::string;
#define SHIPSAMOUNT 5
class Player
{
private:

    string playerName;
    Ship* ships[SHIPSAMOUNT];
    Grid grid;
    int numOfShipsAlive = SHIPSAMOUNT;
public:
    Player(const string& name);
    virtual ~Player();
    virtual void placeAllShips();
    virtual void makeMove(Player* opponent);

    inline bool allShipsSunk() const {return numOfShipsAlive <= 0;}

    inline void displayGrid() const {grid.printGrid();}
};
