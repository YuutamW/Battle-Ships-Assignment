#include "HumanPlayer.hpp"

void HumanPlayer::placeAllShips()
{
    int row, col;
    char orientation;
    bool horizontal;
    int i = 0;
    while (i < SHIPSAMOUNT)
    {
        std::cout << "Enter tile number for the " << getShip(i)->getName() << ": ex. 1 1" << std::endl;
        std::cin >> row >> col;
        if (!VALIDGRIDINP(row, col))
        {
            std::cout << "Invalid row/column" << std::endl;
            continue;
        }
        std::cout << "Enter desired orientation: H for horizontal, V for vertical" << std::endl;
        std::cin >> orientation;
        switch (orientation)
        {
        case 'H':
            horizontal = true;
            break;

        case 'h':
            horizontal = true;
            break;

        case 'V':
            horizontal = false;
            break;

        case 'v':
            horizontal = false;
            break;

        default:
            break;
        }

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
            getGrid().placeShip(row, col, getShip(i)->getSize(), horizontal);
            getShip(i)->setPos(row, col, horizontal);
        }
        i++;
    }
}

void HumanPlayer::makeMove(Player *opponent)
{
    int row, col;
    std::cout << "Enter tile number for your next move: ex. 1 1" << std::endl;
    std::cin >> row >> col;
    if (!VALIDGRIDINP(row, col))
    {
        std::cout << "Invalid row/column, try again" << std::endl;
        makeMove(opponent);
    }
    opponent->recieveAttack(row, col);
    std::cout << this->getPlayerName() << "'s Grid: " << std::endl;
    grid.printGrid();
    std::cout << opponent->getPlayerName() << "'s Grid:" << std::endl;
    opponent->getGrid().printGrid();
    return;
}
