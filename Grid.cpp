#include "Grid.hpp"
#include <exception>
#define CELL_OCC_MSG(row,col) std::cout<<"Cell Already Occupied at: " << (row)<<" "<<(col)<<std::endl
bool Grid::inBounds(int row, int col, int shipSize, bool horizontal) const
{
    using namespace std;
    if( ! VALIDGRIDINP(row,col) ) 
    {
        cout<< "Invalid row/column "<<endl;
        return false;
    }
    if(shipSize <= 0)
    {
        cout<< "Invalid Ship Size "<<endl;
        return false;
    }
    if(horizontal)
    for(int i = 0; i < shipSize; i++)
    {
        if(cells[row][col+i] == 'S')
        {
            CELL_OCC_MSG(row,col+i);
            return false;
        }
    }
    else
    for(int i = 0; i <shipSize; i++)
    {
        if(cells[row+i][col] == 'S')
        {
            CELL_OCC_MSG(row+i,col);
            return false;
        }
    }
    return true;
}

void Grid::placeShip(int row, int col, int shipSize, bool horizontal)
{
    char symbol = 'S';
    if(!inBounds) {
        std::cout<< "Ship Placing is not allowed!"<<std::endl;
        return;
    }
    if(numOfShipsOnGrid >= MAXSHIPSALLOWED)
    {
        std::cout<< "number of ships Exceeded max amount allowed!"<<std::endl;
        return;
    }
    if(horizontal) 
    for(int i = 0; i < shipSize;  i++  )
    cells[row][col + i] = symbol;
    else
    for(int i = 0; i < shipSize;  i++  )
    cells[row + i][col] = symbol;

    numOfShipsOnGrid++;
}

char Grid::getCell(int row, int col) const
{
    try
    {
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}
