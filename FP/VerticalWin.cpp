#include "VerticalWin.h"
using namespace std;

bool VerticalWin::validate(Board* b)
{
    win = false;
    //for each column, test each row starting from the bottom row, 
    //moving up to the 4th row (to test using the row as starting row (then tests 3 rows from there))
    for (int c = 0; c < b->getCol(); c++)
    {
        for (int r = b->getRow()-1; r > 3; r--)
        {
            //if the column is o, test the |_| values
            if (c==0)
            {
                //for X token, if the bottom is full, test one row up
                if (b->getValueInBoard(r,c) == "|X|" && b->getValueInBoard(r-1,c) == "|X|")
                {
                    //if there are four of the same string type in a row of four in the column, it's a win
                    if (b->getValueInBoard(r-1,c) == b->getValueInBoard(r-2,c) && b->getValueInBoard(r-1,c) == b->getValueInBoard(r-3,c))
                    {
                        win = true;
                        return win;
                    }
                }
                //for O token, if the bottom is full, test one row up
                if (b->getValueInBoard(r,c) == "|O|" && b->getValueInBoard(r-1,c) == "|O|")
                {
                    //then if there are four of the same string type in a row of four in the column, it's a win
                    if (b->getValueInBoard(r-1,c) == b->getValueInBoard(r-2,c) && b->getValueInBoard(r-1,c) == b->getValueInBoard(r-3,c))
                    {
                        win = true;
                        return win;
                    }
                }
            }
            //tests the other columns of _| type
            if (c>0)
            {
                //for X token, if the bottom and next row up are the same,
                if (b->getValueInBoard(r,c) == "X|" && b->getValueInBoard(r-1,c) == "X|")
                {
                    //tests if there are four in a row of in the column
                    if (b->getValueInBoard(r-1,c) == b->getValueInBoard(r-2,c) && b->getValueInBoard(r-1,c) == b->getValueInBoard(r-3,c))
                    {
                        win = true;
                        return win;
                    }                    
                }
                //for O token, if the bottom and next row up are the same,
                if (b->getValueInBoard(r,c) == "O|" && b->getValueInBoard(r-1,c) == "O|")
                {
                    //tests if there are four in a row in the same column
                    if (b->getValueInBoard(r-1,c) == b->getValueInBoard(r-2,c) && b->getValueInBoard(r-1,c) == b->getValueInBoard(r-3,c))
                    {
                        win = true;
                        return win;
                    }                    
                }
            }        
        }
    }
    return win;

}