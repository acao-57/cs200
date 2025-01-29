#include "Token.h"
#include <string>
#include <iostream>

using namespace std;

//creates a token object initialized to a blank token type
Token::Token()
{
    _tokenType = ' ';
}

//player 1 = X, player 2 = O
char Token::setToken(int const PLAYER)
{
    if (PLAYER == P_ONE)
    {
        _tokenType = 'X';
    }
    if (PLAYER == P_TWO)
    {
        _tokenType = 'O';
    }
    return _tokenType;
}

//returns the token type
char Token::getToken()
{
    return _tokenType;
}

