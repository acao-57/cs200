#ifndef VERTICALWIN_H
#define VERTICALWIN_H
#include "Win.h"

class VerticalWin : public Win //child class of Win class
{
    public:
        bool validate(Board*) override; //overrides the validate function, using board pointer
};
#endif