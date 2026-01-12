#include <iostream>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <string>

// Include your project headers
#include "Game.hpp"
#include "HumanPlayer.hpp"
#include "AiPlayer.hpp"
#include "Grid.hpp"
#include "Ship.hpp"

// ==========================================
// TEST SUITE
// ==========================================

void printTestHeader(const std::string& testName) {
    std::cout << "\n========================================\n";
    std::cout << "TEST: " << testName << "\n";
    std::cout << "========================================\n";
}


void testAiVsAiSimulation() {
    using namespace std;
    printTestHeader("AI vs AI Stress Test");
    
    // We will run a full game between two AIs to ensure no infinite loops 
    // and that game termination logic works.
    
    std::cout << "[INFO] Initializing AI Players...\n";
    Player* bot1 = new AIPlayer("T-800");
    Player* bot2 = new AIPlayer("Skynet");

    Game simGame(bot1, bot2);

    std::cout << "[INFO] Setting up boards (Auto-Placement)...\n";
    simGame.setup(); 
    
    bot1->displayGrid();
    bot2->displayGrid();
    cout<<"continue?"<<endl;
    char inp;
    cin>>inp;
    if(inp == 'y')
    std::cout << "[INFO] Starting high-speed simulation...\n";
    
    unsigned long long counter;
    // We can simulate turns manually or call simGame.start() if start() doesn't require "Enter" presses.
    // If your Game::start() waits for user input (cin.get()), this test might hang.
    // Assuming start() runs automatically for AIs:
    simGame.start(); 

    if (simGame.isGameOver()) {
        std::cout << "[PASS] Game finished successfully.\n";
    } else {
        std::cerr << "[FAIL] Game loop exited but isGameOver() is false.\n";
    }
    
    // Cleanup handled by Game destructor if implemented, or we delete here
    delete bot1;
    delete bot2;
}

// ==========================================
// MAIN ENTRY
// ==========================================
int main() {
    using namespace std;
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::cout << "Select Mode:\n";
    std::cout << "1. Run Stress Tests\n";
    std::cout << "2. Play Standard Game (Human vs AI)\n";
    std::cout << "> ";
    
    int choice;
    if (std::cin >> choice) {
        if (choice == 1) {
            // testGridBoundaries();
            // testShipOverlap();
            testAiVsAiSimulation();
        } else {
            string S1 = "human Player";
            string S2 = "Ai Player";
            // Standard Game from the example
            Player* p1 = new HumanPlayer(S1);
            Player* p2 = new AIPlayer(S2);

            Game game(p1, p2);
            game.setup();
            game.start();

            delete p1;
            delete p2;
        }
    }

    return 0;
}