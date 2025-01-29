#include "Moves.h"
#include <iostream>
using namespace std;

Moves::Moves()
{
    move = " ";
}

//validates the player's move
bool Moves::validatePlayerMoves(Board* b, int GAME_MOVE)
{
    //game move is the column+1 (since board column shows a 1 instead of 0)
    _col = GAME_MOVE;

    //cycles through each row with given column until an empty grid appears or
    for (int r = b->getRow()-1; r > 0; r--)
    {
        //checks for the first column since it's a different string |_|
        if (_col == 1)
        {
            //if the column is empty at the bottom row, it's a valid move
            if (b->getValueInBoard(r, _col-1) == "|_|")
            {
                valid = true;
                _row = r;
            } 
            else 
            {
                valid = false;
            }
        }
        //checks the other type of string _| for empty columns
        else
        {
            if (b->getValueInBoard(r, _col-1) == "_|")
            {
                valid = true;
                _row = r;
            }
            else
            {
                valid = false;
            }
        }
        if (valid == true)
        {
            break;
        }
    }

    //if it's a valid move, return move as a string of Row + Column to set the Board in Board.cpp
    if (valid == true)
    {
        move = to_string(_row) + to_string(_col-1);
        return true;
    }
    else 
    {
        return false;
    }
}

//gets the player's move (as string Row+Column)
string Moves::getPlayerMove()
{
    return move;
}
