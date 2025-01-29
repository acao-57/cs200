#ifndef WIN_H
#define WIN_H

#include <iostream>

#include "Board.h"
class Win
{
    public:
        virtual ~Win() {}; //virtual destructor
        virtual bool validate(Board*) = 0; //abstract function
    protected:
        bool win;
};
#endif