#include "Player.hpp"
#include "Carrier.hpp"
#include "BattleShip.hpp"
#include "Cruiser.hpp"
#include "Submarine.hpp"
#include "Destroyer.hpp"
#include <stdexcept>

Player::Player(const string &name) : playerName(name)
{
    if (playerName.empty())
    {
        throw std::invalid_argument("Error : Invalid playerName");
    }

    for (int i = 0; i < SHIPSAMOUNT; i++)
    {
        switch (i)
        {
        case 0:
            ships[i] = new Carrier();
            break;

        case 1:
            ships[i] = new BattleShip();
            break;

        case 2:
            ships[i] = new Cruiser();
            break;

        case 3:
            ships[i] = new Submarine();
            break;

        case 4:
            ships[i] = new Destroyer();
            break;

        default:
            break;
        }
    }
}

Player::~Player()
{
    for (int i = 0; i < SHIPSAMOUNT; i++)
    {
        if(ships[i]){
            delete ships[i];
            ships[i] = nullptr;
        }
    }
}

bool Player::recieveAttack(int row, int col)
{
    if (!VALIDGRIDINP(row, col))
        return false;
    char cell = grid.getCell(row, col);
    if (cell == 'S')
    {
        for (int i = 0; i < SHIPSAMOUNT; i++)
        {
            if (ships[i]->covers(row, col))
            {
                ships[i]->takeHit();
                if (ships[i]->isSunk())
                    numOfShipsAlive--;
                break;
            }
        }
        grid.markHit(row, col);
        return true;
    }
    else if (cell == 'X')
    {
        std::cout << "Already shot at coordinates: " << row << "," << col << " Was a Hit!" << std::endl;
    }
    else if (cell == 'M')
    {
        std::cout << "Already shot at coordinates: " << row << "," << col << " Missed!" << std::endl;
    }
    else
    {
        std::cout << "Miss! " << std::endl;
        grid.markMiss(row, col);
    }
    return false;
}
