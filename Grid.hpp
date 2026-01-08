#pragma once
#define BOARDSIZE 10
#define VALIDGRIDINP(row,col) ((row >= 0) && (col >= 0) && (row < BOARDSIZE) && (col <BOARDSIZE))
#include <iostream>

class Grid
{
private:
  char cells[BOARDSIZE][BOARDSIZE];
public:
  Grid();
  ~Grid();

  inline bool isTileOccupied(int row, int col) const {return VALIDGRIDINP(row,col)? (cells[col][row] != '~') : false ;  }


  
};


