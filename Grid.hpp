#pragma once
#define BOARDSIZE 10
#define VALIDGRIDINP(row,col) ((row >= 0) && (col >= 0) && (row < BOARDSIZE) && (col <BOARDSIZE))
#define MAXSHIPSALLOWED 5
#include <iostream>
class Grid
{
private:
  char cells[BOARDSIZE][BOARDSIZE] = {'~'};
  int numOfShipsOnGrid;
  void shipPlacementIndex(int& startPoint, int& endPoint , bool horizontal) const;
public:
  Grid() : numOfShipsOnGrid(0) {}
  ~Grid();

  inline bool isTileOccupied(int row, int col) const {return VALIDGRIDINP(row,col)? (cells[row][col] == 'S' || cells[row][col] == 'X'): false ;  }

  bool inBounds(int row , int col, int shipSize, bool horizontal) const;

  void placeShip(int row, int col, int shipSize, bool horizontal);

  inline void markHit(int row, int col) {if(VALIDGRIDINP(row,col)) cells[row][col] = 'X'; }

  inline void markMiss(int row, int col) {if(VALIDGRIDINP(row,col)) cells[row][col] = 'M'; }
  
  char getCell(int row, int col) const ;

  void printGrid() const;

};
