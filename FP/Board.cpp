#include "Board.h"
#include <iostream>
using namespace std;

Board::Board()
{
    //creates the board of row and column size
    _board = new string*[_ROWSIZE];
    for (int i = 0; i < _ROWSIZE; i++)
    {
        _board[i] = new string[_COLUMNSIZE];
    }

    //initialize all the vectors to make the empty board
    char number = 49; //gets the ascii table values of the numbers
    int firstRow = 0;

    //first row is the numbers for each column
    for (int c = 0; c < _COLUMNSIZE; c++)
    {
        string s(1, number);
        _board[firstRow][c] = " " + s;
        number++;
    }

    //for the rest of the grid, make it look like an empty grid, first column is |_|, rest are _|
    for (int r = 1; r < _ROWSIZE; r++)
    {
        for (int c = 0; c < _COLUMNSIZE; c++)
        {
            if(c == 0)
            _board[r][c] = _EMPTYFULL;

            else
            _board[r][c] = _EMPTYSIDE;
        }
    }

}

//destructor
Board::~Board()
{
    for (int i = 0; i < _ROWSIZE; i++)
    {
        delete[] _board[i];
    }
    delete[] _board;
}

//sets the value in the board
string** Board::setBoard(const char c, const string MOVE)
{
    //c is the token type so the board can set the move to either X or O
    tokenType = c;
    
    //move is a string consisting of function playerMove in Moves.cpp, which is a string
    //first letter in MOVE is the row, second letter in MOVE is the column
    //converts the letters to their equivalent int value from the ascii table 
    int row = MOVE.at(0) - 48;
    int col = MOVE.at(1) - 48;

    if (tokenType == 'X')
    {
         if(col == 0)
        _board[row][col] = _XFULL;

        else
        _board[row][col] = _XSIDE;
    }

    if (tokenType == 'O')
    {
         if(col == 0)
        _board[row][col] = _OFULL;

        else
        _board[row][col] = _OSIDE;
    }

    return _board;
}

//using R and C as parameters, get the value in the board at that row and column
string Board::getValueInBoard(int const R, int const C)
{
    int row = R;
    int col = C;
    return _board[row][col];
}

//prints to file the board
void Board::printBoard(ostream& fout)
{
        for (int i = 0; i < _ROWSIZE; i++) 
        {
        for (int j = 0; j < _COLUMNSIZE; j++) 
        {
            fout << _board[i][j];
        }
        fout << "\n";
        }
}

//checks if the board is completely full by checking if there are any empty grids
bool Board::checkFullBoard()
{
    for (int r = 1; r < _ROWSIZE; r++)
    {
        for (int c = 0; c < _COLUMNSIZE; c++)
        {
            if (_board[r][c] == _EMPTYFULL || _board[r][c] == _EMPTYSIDE )
            {
                return false;
            }
        }
    }
    return true;
}

//gets the row size
int Board::getRow() const
{
    return _ROWSIZE;
}

//gets the column size
int Board::getCol() const
{
    return _COLUMNSIZE;
}



