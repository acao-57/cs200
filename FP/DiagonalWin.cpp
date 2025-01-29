#include "DiagonalWin.h"

using namespace std;

bool DiagonalWin::validate(Board* b)
{
    win = false;
    // '/' diagonal side check
    for (int r = 6; r>3; r--)
    {
        for (int c = 0; c<4; c++)
        { 
            //choecks the first column since it's a different string |_| than the rest of the board _|
            if (c==0)
            {
                //tests for X token win
                //tests the first column and if the token matches the next diagonal in a row
                if (b->getValueInBoard(r, c) == "|X|" && b->getValueInBoard(r-1,c+1) == "X|")
                {
                    //tests if there are matching tokens in the board in four in a row '/' diagonally
                    if (b->getValueInBoard(r-1,c+1) == b->getValueInBoard(r-2,c+2) && b->getValueInBoard(r-1,c+1) == b->getValueInBoard(r-3,c+3))
                    {
                        win = true;
                        return win;
                    }
                }
                //tests for O token win
                //tests the first column and if the token matches the next diagonal in a row
                if (b->getValueInBoard(r, c) == "|O|" && b->getValueInBoard(r-1,c+1) == "O|")
                {
                    //tests if there are matching tokens in the board in four in a row '/' diagonally
                    if (b->getValueInBoard(r-1,c+1) == b->getValueInBoard(r-2,c+2) && b->getValueInBoard(r-1,c+1) == b->getValueInBoard(r-3,c+3))
                    {
                        win = true;
                        return win;
                    }
                }
            }
            //tests diagonals that start not in the first column
            else
            {
                //tests X token type
                //tests for two in a row diagonally
                if (b->getValueInBoard(r, c) == "X|" && b->getValueInBoard(r-1,c+1) == "X|")
                {
                    //tests if there are matching tokens in the board in four in a row '/' diagonally
                    if (b->getValueInBoard(r-1,c+1) == b->getValueInBoard(r-2,c+2) && b->getValueInBoard(r-1,c+1) == b->getValueInBoard(r-3,c+3))
                    {
                        win = true;
                        return win;
                    }
                }
                //tests O token type
                //tests for two in a row diagonally
                if (b->getValueInBoard(r, c) == "O|" && b->getValueInBoard(r-1,c+1) == "O|")
                {
                    //tests if there are matching tokens in the board in four in a row '/' diagonally
                    if (b->getValueInBoard(r-1,c+1) == b->getValueInBoard(r-2,c+2) && b->getValueInBoard(r-1,c+1) == b->getValueInBoard(r-3,c+3))
                    {
                        win = true;
                        return win;
                    }
                }
            }
        }
    }

    // '\' side check
    for (int r = 3; r > 0; r--)
    {
        for (int c = 0; c<4; c++)
        {
            //tests for first column since it's a different string type
            if (c==0)
            {
                //checks X token type
                //tests if the first column matches with the next column
                if (b->getValueInBoard(r, c) == "|X|" && b->getValueInBoard(r+1,c+1) == "X|")
                {
                    //tests if there are matching tokens in the board in four in a row '\' diagonally
                    if (b->getValueInBoard(r+1,c+1) == b->getValueInBoard(r+2,c+2) && b->getValueInBoard(r+1,c+1) == b->getValueInBoard(r+3,c+3))
                    {
                        win = true;
                        return win;
                    }
                }
                //checks O token type
                //tests if the first column matches with the next column
                if (b->getValueInBoard(r, c) == "|O|" && b->getValueInBoard(r+1,c+1) == "O|")
                {
                    //tests if there are matching tokens in the board in four in a row '\' diagonally
                    if (b->getValueInBoard(r+1,c+1) == b->getValueInBoard(r+2,c+2) && b->getValueInBoard(r+1,c+1) == b->getValueInBoard(r+3,c+3))
                    {
                        win = true;
                        return win;
                    }
                }
            }

            //checks for a diagonal win that doesn't start in the first column
            else
            {
                //tests for matching x tokens
                if (b->getValueInBoard(r, c) == "X|" && b->getValueInBoard(r+1,c+1) == "X|")
                {
                    //tests if there are matching tokens in the board in four in a row '\' diagonally
                    if (b->getValueInBoard(r+1,c+1) == b->getValueInBoard(r+2,c+2) && b->getValueInBoard(r+1,c+1) == b->getValueInBoard(r+3,c+3))
                    {
                        win = true;
                        return win;
                    }
                }
                //tests for matching o tokens
                if (b->getValueInBoard(r, c) == "O|" && b->getValueInBoard(r+1,c+1) == "O|")
                {
                    //tests if there are matching tokens in the board in four in a row '\' diagonally
                    if (b->getValueInBoard(r+1,c+1) == b->getValueInBoard(r+2,c+2) && b->getValueInBoard(r+1,c+1) == b->getValueInBoard(r+3,c+3))
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