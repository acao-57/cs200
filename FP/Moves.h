#ifndef MOVES_H
#define MOVES_H

#include "Board.h"
#include <string>
#include <ostream>
class Moves
{
    public:
        Moves();
        bool validatePlayerMoves(Board*, int);
        std::string getPlayerMove();

    private:
        int  _col;
        int _row;
        std::string move;
        bool valid;
};


#endif