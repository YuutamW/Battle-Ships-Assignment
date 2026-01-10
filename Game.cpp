#include "Game.hpp"
#include <iostream>
#include <exception>

Game::Game(Player *p1, Player *p2) : player1(p1), player2(p2)
{
    if (!p1 || !p2)
    {
        throw std::invalid_argument("Error : One or more of the players does not exist");
    }
}

void Game::setup()
{
    try
    {
        player1->placeAllShips();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        player2->placeAllShips();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}

void Game::start()
{
    do
    {
        try
        {
            player1->makeMove(player2);
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
        if (player2->allShipsSunk())
        {
            std::cout << player1->getPlayerName() << " won!" << std::endl;
        }

        try
        {
            player2->makeMove(player1);
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
        if (player1->allShipsSunk())
        {
            std::cout << player2->getPlayerName() << " won!" << std::endl;
        }
    } while (!isGameOver());
}
