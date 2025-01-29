#ifndef TOKEN_H
#define TOKEN_H

#include "Board.h"
#include <string>
#include <vector>

class Token
{
    public:
        Token();
        char setToken(int const);
        char getToken();

    private:
        int const P_ONE = 1;
        int const P_TWO = 2;
        char _tokenType;
};

#endif