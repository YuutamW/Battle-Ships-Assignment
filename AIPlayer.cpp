#include "AIPlayer.hpp"

void AIPlayer::queueNeighbours(int r, int c, const Grid &opponentGrid)
{
    //list of 4 directions for row,col:
    int directionRow[] = {-1,1,0,0};
    int directionCol[] = {0,0,-1,1};

    for(int i = 0; i < 4; ++i)
    {
        int neighbourRow = r + directionRow[i];
        int neighbourCol = c + directionCol[i];
        //check if neighbour is inside the board:
        if(VALIDGRIDINP(neighbourRow,neighbourCol))
        {
            //check if we have already shot there:
            try
            {
                char cell = opponentGrid.getCell(neighbourRow,neighbourCol);
                if(cell != 'X' && cell != 'M')
                    pendingTarget.push({neighbourRow,neighbourCol});
            }
            catch(...) {/*ignore out of bounds*/}
            
        }
    }
}

void AIPlayer::placeAllShips()
{
    int row, col, orientation;
    bool horizontal;
    int i = 0;
    int realStart = 0;
    while (i < SHIPSAMOUNT)
    {
        row = getRandomCoordinate();
        col = getRandomCoordinate();
        std::cout << "Choosing random location..." << std::endl;
        orientation = getRandomOrientation();
        std::cout << "Choosing random orientation..." << std::endl;
        horizontal = (orientation) ? true : false;

        if (!getGrid().inBounds(row, col, getShip(i)->getSize(), horizontal))
        {
            std::cout << "Ship placement is out of bounds, try again" << std::endl;
            continue;
        }
        else if (getGrid().isTileOccupied(row, col))
        {
            std::cout << "Tile is already occupied, try again" << std::endl;
            continue;
        }
        else
        {
            if( getGrid().placeShip(row, col, getShip(i)->getSize(), horizontal ,realStart)){
                if(horizontal) getShip(i)->setPos(row, realStart, horizontal);
                else getShip(i)->setPos(realStart, col, horizontal);
            }else continue;
        }
        i++;
    }
}

void AIPlayer::makeMove(Player *opponent)
{
    int row, col;
    bool validPick = false;
    //1. try to get a target form the queue:
    while (!pendingTarget.empty())
    {
        std::pair<int,int> target = pendingTarget.front();
        pendingTarget.pop();//remove forom queue.
        //verify we havne shot there already, dup's could be in queue.
        char cell = opponent->getGrid().getCell(row,col);
        if(cell != 'X' && cell != 'M')
        {
            validPick = true;
            break;
        }
    }
    //2.if queue was empty or all was previuosly shot at, pick at random:
    if(!validPick)
    {
        //keep picking until found a point we havent shot yet:
        do
        {
            row = getRandomCoordinate();
            col = getRandomCoordinate();
            char cell = opponent->getGrid().getCell(row,col);
            if(cell != 'X' && cell != 'M') validPick = true;
        } while (!validPick);
        
    }
    //3. fire: recieve attack returns true if hit a ship:
    bool isHit = opponent->recieveAttack(row,col);
    if(isHit)
    {
        std::cout << "AI TARGETING SYSTEMS ACTIVATED AT " << row << " " << col << std::endl;
        queueNeighbours(row, col, opponent->getGrid());
    }
    std::cout << this->getPlayerName() << "'s Grid: " << std::endl;
    grid.printGrid();
    std::cout << opponent->getPlayerName() << "'s Grid:" << std::endl;
    opponent->getGrid().printGrid();
    return;
}
