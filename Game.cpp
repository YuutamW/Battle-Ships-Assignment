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
    using namespace std;
    cout<<"____________SETTING UP GAME______________"<<endl;
    cout<<"COMMANDER "<<player1->getPlayerName()<<" _VS._ COMMANDER "<<player2->getPlayerName()<<endl;
    cout<<"Commander "<<player1->getPlayerName()<<" Setting up the board:"<<endl;
    try
    {
        player1->placeAllShips();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    cout<<"Commander "<<player1->getPlayerName()<<"'S BOARD:"<<endl;
    player1->displayGrid();
    cout<<"Commander "<<player2->getPlayerName()<<" Setting up the board:"<<endl;
    try
    {
        player2->placeAllShips();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    cout<<"Commander "<<player2->getPlayerName()<<"'S BOARD:"<<endl;
    player2->displayGrid();
    cout<<"\tBOARDS ARE SET! LET THE BATTLE BEGIN!"<<endl;
}

void Game::start()
{
    unsigned long long counter = 0;
    using namespace std;
    do
    {
        cout<<"\t\t\t__ITERATIONS:["<<++counter<<"]"<<std::endl;
        try
        {
            cout<<player1->getPlayerName()<<" MAKES A MOVE: "<<endl;
            player1->makeMove(player2);
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
        if (player2->allShipsSunk())
        {
            
            victory(player1->getPlayerName());
        }

        try
        {
            cout<<player2->getPlayerName()<<" MAKES A MOVE: "<<endl;
            player2->makeMove(player1);
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
        if (player1->allShipsSunk())
        {
            victory(player2->getPlayerName());
        }
    } while (!isGameOver());
}


void Game::victory(string winnerName)
{
    std::cout << "\n\n";
    std::cout << R"(
                                     |__
                                     |\/
                                     ---
                                     / | [
                              !      | |||
                            _/|     _/|-++'
                        +  +--|    |--|--|_ |-
                     { /|__|  |/\__|  |--- |||__/
                    +---------------___[}-_===_.'____               /\
                ____`-' ||___-{]_| _[}-  |     |_[___\==--          \/   _
 __..._____--==/___]_|__|_____________________________[___\==--____,------' .7
|                                                                     BB-61/
 \_________________________________________________________________________|
  )" << "\n";

    std::cout << R"(
   _   _ _____ _____ _____ ___________ __   __  _ 
  | | | |_   _/  __ \_   _|  _  | ___ \\ \ / / | |
  | | | | | | | /  \/ | | | | | | |_/ / \ V /  | |
  | | | | | | | |     | | | | | |    /   \ /   | |
  \ \_/ /_| |_| \__/\ | | \ \_/ / |\ \   | |   |_|
   \___/ \___/ \____/ \_/  \___/\_| \_|  \_/   (_)
                                                  
    )" << "\n";
    
    std::cout << "\n\t\tCOMMANDER " << winnerName << " WINS THE WAR!\n";
    std::cout << "\n================================================================\n\n";
}