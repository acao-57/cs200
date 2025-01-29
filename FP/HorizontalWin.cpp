#include "HorizontalWin.h"

using namespace std;

bool HorizontalWin::validate(Board* b)
{
    win = false;
    //starting from bottom row, up to the second row (first row is of the numbers, cannot access)
    for (int r = b->getRow()-1; r>0; r--)
    {
        //tests each column in the row until the fourth as the start column (tests three values after that, so it caps at 4th)
        for (int c = 0; c < 4; c++)
        {
            //if it's the first column, it's a different type of string |_|, so compare it to the next column in the row for a match
            if (c == 0)
            {
                //tests X token type
                if (b->getValueInBoard(r, c) == "|X|" && b->getValueInBoard(r,c+1) == "X|")
                {
                    //if there are four in a row from the row in different columns, it's a match
                    if (b->getValueInBoard(r,c+1) == b->getValueInBoard(r,c+2) && b->getValueInBoard(r,c+1) == b->getValueInBoard(r,c+3))
                    {
                        win = true;
                        return win;
                    }

                }
                //tests O token type
                //compares first column to the next column in the row for a match
                if (b->getValueInBoard(r, c) == "|O|" && b->getValueInBoard(r,c+1) == "O|")
                {
                    //if there are four in a row from the row in different columns, it's a match       
                    if (b->getValueInBoard(r,c+1) == b->getValueInBoard(r,c+2) && b->getValueInBoard(r,c+1) == b->getValueInBoard(r,c+3))
                    {
                        win = true;
                        return win;
                    }
                }
            }

            //for every other column type of _|
            else
            {
            if (b->getValueInBoard(r, c) == "X|" && b->getValueInBoard(r,c+1) == "X|")
            {
                if (b->getValueInBoard(r,c+1) == b->getValueInBoard(r,c+2) && b->getValueInBoard(r,c+1) == b->getValueInBoard(r,c+3))
                {
                    win = true;
                    return win;
                }
            }
            if (b->getValueInBoard(r, c) == "O|" && b->getValueInBoard(r,c+1) == "O|")
            {
                if (b->getValueInBoard(r,c+1) == b->getValueInBoard(r,c+2) && b->getValueInBoard(r,c+1) == b->getValueInBoard(r,c+3))
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