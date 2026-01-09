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

Ship *Player::findShipInGrid(int row, int col)
{
    for (int i = 0; i < SHIPSAMOUNT; i++)
    {
        // If tile is the start tile of the ship - return ship
        if (row == ships[i]->getRowStart() && col == ships[i]->getColStart())
        {
            return ships[i];
        }

        // If the tile is diagonal to the ship - continue
        if (ships[i]->isHorizontal() && row != ships[i]->getRowStart() || !ships[i]->isHorizontal() && col != ships[i]->getColStart())
        {
            continue;
        }
        if (ships[i]->isHorizontal())
        {
            // If tile is farther than the ship size - continue
            if (std::abs(col - ships[i]->getColStart()) > ships[i]->getSize())
            {
                continue;
            }
            // Check if ship is placed ltr/rtl
            if (grid.getCell(row, ships[i]->getColStart() + 1) == 'S' || grid.getCell(row, ships[i]->getColStart() + 1) == 'X')
            {
                if (col >= ships[i]->getColStart() && col <= ships[i]->getColStart() + ships[i]->getSize())
                {
                    return ships[i];
                }
            }
            if (grid.getCell(row, ships[i]->getColStart() - 1) == 'S' || grid.getCell(row, ships[i]->getColStart() + 1) == 'X')
            {
                if (col >= ships[i]->getColStart() && col <= ships[i]->getColStart() + ships[i]->getSize())
                {
                    return ships[i];
                }
            }
        }
        else
        {
            if (std::abs(row - ships[i]->getRowStart()) > ships[i]->getSize())
            {
                continue;
            }
        }
    }
}
