#include "AIPlayer.hpp"

void AIPlayer::placeAllShips()
{
    int row, col, orientation;
    bool horizontal;
    int i = 0;
    while (i < SHIPSAMOUNT)
    {
        row = getRandomCoordinate();
        col = getRandomCoordinate();
        std::cout << "Choosing random location..." << std::endl;
        orientation = getRandomOrientation();
        std::cout << "Choosing random orientation..." << std::endl;
        horizontal = (orientation) ? true : false;

        if (!getGrid().inBounds(row, col, getShip(i)->getSize(), horizontal))
        {
            std::cout << "Ship placement is out of bounds, try again" << std::endl;
            continue;
        }
        else if (getGrid().isTileOccupied(row, col))
        {
            std::cout << "Tile is already occupied, try again" << std::endl;
            continue;
        }
        else
        {
            if( getGrid().placeShip(row, col, getShip(i)->getSize(), horizontal))
                getShip(i)->setPos(row, col, horizontal);
            else continue;
        }
        i++;
    }
}

void AIPlayer::makeMove(Player *opponent)
{
    int row, col;
    row = getRandomCoordinate();
    col = getRandomCoordinate();
    opponent->recieveAttack(row, col);
    std::cout << this->getPlayerName() << "'s Grid: " << std::endl;
    grid.printGrid();
    std::cout << opponent->getPlayerName() << "'s Grid:" << std::endl;
    opponent->getGrid().printGrid();
    return;
}
