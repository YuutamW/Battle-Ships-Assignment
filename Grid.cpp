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
    {
        if((col + shipSize) > BOARDSIZE && (col - shipSize) < 0)
        {
            cout<<"Placing ship sized "<<shipSize<<" tiles at ["<<row<<"]["<<col<<"] is Out of Bounds, probably shipSize bigger than grid."<<endl;
            return false;
        }
        else return true;
    }
    else
    {
        if((row + shipSize) > BOARDSIZE && (row - shipSize) < 0)
        {
            cout<<"Placing ship sized "<<shipSize<<" tiles at ["<<row<<"]["<<col<<"] is Out of Bounds, probably shipSize bigger than grid."<<endl;
            return false;
        }
        else return true;
    }
}

void Grid::shipPlacementIndex(int &startPoint, int &endPoint, bool horizontal) const
{
    
}
void Grid::placeShip(int row, int col, int shipSize, bool horizontal)
{
    char symbol = 'S';
    if(!inBounds(row,col,shipSize,horizontal)) {
        std::cout<< "Ship Placing is not allowed!"<<std::endl;
        return;
    }
    if(numOfShipsOnGrid >= MAXSHIPSALLOWED)
    {
        std::cout<< "number of ships Exceeded max amount allowed!"<<std::endl;
        return;
    }
    numOfShipsOnGrid++;
}

char Grid::getCell(int row, int col) const
{
   
}
