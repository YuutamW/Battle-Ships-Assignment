#include "Grid.hpp"
#include <stdexcept>
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

bool Grid::shipPlacementIndex(int row, int col, int &endPoint, bool horizontal , int shipSize) const
{
    if(!VALIDGRIDINP(row,col)) return false;
    int tilesFound = 0;
    if(horizontal)
    {
        int c = col;
        //we try to add ship to grid from col to col + i. if col +i = 'S' we break and try other way
        while (c < BOARDSIZE && tilesFound < shipSize)
        {
           if(cells[row][c] == 'S') break;
           tilesFound++;
           endPoint = c;
           c++; 
        }
        if(tilesFound < shipSize)   //here we tried to go right on the grid but ddint work, so we go left
        {
            c = col;
            tilesFound = 0;
            while (c >= 0 && tilesFound < shipSize) //going left if we see 'S' break, if out of bounds throw.
            {
                if(c < 0) {std::cout<<("Ship cannot be placed here out of grid Bounds!!")<<std::endl; return false;}
                else
                {
                    if(cells[row][c] == 'S') break;
                    tilesFound++;
                    endPoint = c;
                    c--;
                }
            }
        }
    }
    else        //same thing but for vertical
    {
        int r = row;
        while(r < BOARDSIZE && tilesFound < shipSize)
        {
            if(cells[r][col] == 'S') break;
            tilesFound++;
            endPoint = r;
            r++;
        }
        if(tilesFound < shipSize)
        {
            tilesFound = 0; 
            r = row;
            
            while (r >= 0)
            {
                if(r < 0) {std::cout<<("Ship cannot be placed here out of grid Bounds!!")<<std::endl; return false;}
                else {
                    if(cells[r][col] == 'S') break;
                    tilesFound++;
                    endPoint = r;
                    r--;
                }
            }
        }
    }
    //this is where all the breaks lead to, meaning we tried to place between two ships.
    if(tilesFound < shipSize) {std::cout<<("Ship cannot be placed here, overlapping other ships!")<<std::endl; return false;}
    return true;

}

bool Grid::placeShip(int row, int col, int shipSize, bool horizontal, int& actualPos, char symbol)
{
    if(numOfShipsOnGrid >= MAXSHIPSALLOWED)
    {
        std::cout<< "number of ships Exceeded max amount allowed!"<<std::endl;
        return false;
    }
        int endpoint = 0;
        
        //ship placement index throws an out_of_bounds exception
        if(!shipPlacementIndex(row,col,endpoint,horizontal,shipSize)) return false;

        if(horizontal)
        {
            int start  = std::min(col, endpoint);
            int end = std::max(col, endpoint);
            actualPos = start;
            for(int c = start; c <= end; c++)
                cells[row][c] = symbol;
        }
        else
        {
            int start  = std::min(row, endpoint);
            int end = std::max(row, endpoint);
            actualPos = start;
            for(int r = start; r <= end; r++)
                cells[r][col] = symbol;
        }
        numOfShipsOnGrid++;
        return true;
}

char Grid::getCell(int row, int col) const
{
   if(!VALIDGRIDINP(row,col)) throw std::out_of_range("Invalid row/column");
   return cells[row][col];
}

void Grid::printGrid() const
{
    using namespace std;
    cout<<"  ";
    for (int i = 0; i < BOARDSIZE; i++)
    {
        cout << i << " ";
    }
    cout<<endl;
    for(int r = 0; r < BOARDSIZE; r++)
    {
        cout << r << " ";
        for(int c = 0; c < BOARDSIZE; c++)
        {
            cout << cells[r][c] << " ";
        }
        cout<<endl;
    }
}
