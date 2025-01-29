#ifndef DIAGONALWIN_H
#define DIAGONALWIN_H
#include "Win.h"

class DiagonalWin : public Win //child class of Win class
{
    public:
        bool validate(Board*) override; //overrides validate method
};

#endif