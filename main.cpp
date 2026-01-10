#include <iostream>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <ctime>

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

void testGridBoundaries() {
    printTestHeader("Grid Boundaries & Validation");
    Grid testGrid;
    
    std::cout << "[INFO] Testing Negative Coordinates...\n";
    try {
        // Try placing at -1, -1
        testGrid.placeShip(-1, -1, 5, true, 'S');
        std::cerr << "[FAIL] Negative coordinates did not throw/return error!\n";
    } catch (...) {
        std::cout << "[PASS] Negative coordinates rejected.\n";
    }

    std::cout << "[INFO] Testing Out of Bounds (Right Edge)...\n";
    // Grid is 10x10 (0-9). Placing size 5 at col 6 horizontal occupies 6,7,8,9,10 -> 10 is OOB.
    if (testGrid.inBounds(0, 6, 5, true)) {
        std::cerr << "[FAIL] Grid allowed placing ship exceeding right boundary.\n";
    } else {
        std::cout << "[PASS] Right boundary respected.\n";
    }

    std::cout << "[INFO] Testing Out of Bounds (Bottom Edge)...\n";
    if (testGrid.inBounds(8, 0, 3, false)) { // 8, 9, 10 -> OOB
        std::cerr << "[FAIL] Grid allowed placing ship exceeding bottom boundary.\n";
    } else {
        std::cout << "[PASS] Bottom boundary respected.\n";
    }
}

void testShipOverlap() {
    printTestHeader("Ship Overlap Logic");
    Grid testGrid;

    // 1. Place a Destroyer at (0,0) Horizontal
    // Occupies (0,0) and (0,1)
    std::cout << "[INFO] Placing valid Destroyer at (0,0)...\n";
    testGrid.placeShip(0, 0, 2, true, 'S');

    // 2. Try to place a Submarine overlapping at (0,1) Vertical
    // Should occupy (0,1), (1,1), (2,1). (0,1) is taken.
    std::cout << "[INFO] Attempting to overlap at (0,1)...\n";
    if (testGrid.isTileOccupied(0, 1)) {
        std::cout << "[PASS] Tile (0,1) correctly identified as occupied.\n";
    } else {
        std::cerr << "[FAIL] Tile (0,1) should be occupied but isn't.\n";
    }

    // Depending on your implementation of placeShip, check if it throws or handles it
    try {
        // This relies on your Grid throwing logic you implemented earlier
        testGrid.placeShip(0, 1, 3, false, 'S'); 
        std::cerr << "[FAIL] Overlapping ship placement succeeded (should have failed).\n";
    } catch (const std::exception& e) {
        std::cout << "[PASS] Overlap caught exception: " << e.what() << "\n";
    }
}

void testAiVsAiSimulation() {
    printTestHeader("AI vs AI Stress Test");
    
    // We will run a full game between two AIs to ensure no infinite loops 
    // and that game termination logic works.
    
    std::cout << "[INFO] Initializing AI Players...\n";
    Player* bot1 = new AiPlayer("T-800");
    Player* bot2 = new AiPlayer("Skynet");

    Game simGame(bot1, bot2);

    std::cout << "[INFO] Setting up boards (Auto-Placement)...\n";
    simGame.setup(); 

    std::cout << "[INFO] Starting high-speed simulation...\n";
    
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
int main(int argc, char* argv[]) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::cout << "Select Mode:\n";
    std::cout << "1. Run Stress Tests\n";
    std::cout << "2. Play Standard Game (Human vs AI)\n";
    std::cout << "> ";
    
    int choice;
    if (std::cin >> choice) {
        if (choice == 1) {
            testGridBoundaries();
            testShipOverlap();
            testAiVsAiSimulation();
        } else {
            // Standard Game from the example
            Player* p1 = new HumanPlayer("Human Commander");
            Player* p2 = new AiPlayer("Enemy AI");

            Game game(p1, p2);
            game.setup();
            game.start();

            delete p1;
            delete p2;
        }
    }

    return 0;
}