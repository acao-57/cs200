#ifndef BOARD_H
#define BOARD_H

#include "Token.h"
#include <string>
#include <fstream>

class Board
{
    public: 
        Board();
        ~Board();
        std::string** setBoard(const char, const std::string);
        std::string getValueInBoard(const int, const int);
        void printBoard(std::ostream&);
        bool checkFullBoard();
        int getRow() const;
        int getCol() const;

    private:
        std::string** _board;
        char tokenType;
        int const _ROWSIZE = 7;
        int const _COLUMNSIZE = 7;
        std::string const _EMPTYFULL = "|_|";
        std::string const _EMPTYSIDE = "_|";
        std::string const _XFULL = "|X|";
        std::string const _XSIDE = "X|";
        std::string const _OFULL = "|O|";
        std::string const _OSIDE = "O|";

};

#endif