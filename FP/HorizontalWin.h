#ifndef HORIZONTALWIN_H
#define HORIZONTALWIN_H
#include "Win.h"
class HorizontalWin : public Win //child class of Win class
{
    public:
        bool validate(Board*) override; //overrides validate function
};
#endif