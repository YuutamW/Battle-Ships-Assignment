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
            Carrier *carrier;
            ships[i] = carrier;
            break;

        case 1:
            BattleShip *battleShip;
            ships[i] = battleShip;
            break;

        case 2:
            Cruiser *cruiser;
            ships[i] = cruiser;
            break;

        case 3:
            Submarine *submarine;
            ships[i] = submarine;
            break;

        case 4:
            Destroyer *destroyer;
            ships[i] = destroyer;
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
        ships[i] = nullptr;
    }
}

bool Player::recievAttack(int row, int col)
{
    if(!VALIDGRIDINP(row,col)) return false;
    char cell = grid.getCell(row,col);
    if(cell == 'S')
    {
        for(int i = 0; i  < SHIPSAMOUNT; i++)
        {
            if(ships[i]->covers(row,col))
            {
                ships[i]->takeHit();
                if(ships[i]->isSunk())
                    numOfShipsAlive--;
                break;
            }
        }
        grid.markHit(row,col);
        return true;
    }
    else if(cell == 'X' || cell == 'M')
    {
        std::cout<<"Already shot at coordinates: "<<row<<","<<col<<" Missed!"<<std::endl;
        grid.markMiss(row,col);
    }
    else
    {
        std::cout<<"Miss! "<<std::endl;
        grid.markMiss(row,col);
    }
    return false;
}
