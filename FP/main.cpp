#include "Board.h"
#include "Token.h"
#include "Moves.h"
#include "Win.h"
#include "HorizontalWin.h"
#include "VerticalWin.h"
#include "DiagonalWin.h"

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    Token player_one;
    Token player_two;
    Moves p1;
    Moves p2;
    HorizontalWin hWin;
    VerticalWin vWin;
    DiagonalWin dWin;
    string p1Win = "Player one wins!";
    string p2Win = "Player two wins!";
    string tie = "Board is full, players tie.";

    cout << "Welcome to Connect4! The rules: connect four in a row (horizontally, vertically, diagonally)." << endl;
    cout << "2 Player game: Player one, do you wish to be X or O? (type X or O)" << endl;
    
    //creates and opens a Game.txt file
    string fileName = "Game.txt";
    ofstream game;
    if (game.fail())
    {
        cerr << "Error opening output file";
        return -1;
    }
    else
    {
        game.open(fileName);
    }

    //asks player for their token choice, then sets the token
    bool withinBounds = false;
    int intChoice = 0;
    int otherChoice = 0;
    while (withinBounds == false)
    {
        string choice = " ";
        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "Not an option, try again: ";
        }
        else if (choice.length() > 1)
        {
            cout << "Not an option, try again: ";
        }
        else if (choice == "X" || choice == "x")
        {
            intChoice = 1;
            otherChoice = 2;
            withinBounds = true;
        }
        else if (choice == "O" || choice == "o")
        {
            intChoice = 2;
            otherChoice = 1;
            withinBounds = true;
        }
        else
        {
            cout << "Not an option, try again: ";
        }  
    }

    player_one.setToken(intChoice);
    player_two.setToken(otherChoice);

    cout << "Let's Play! Output is in file named Game.txt. Open it to see the board." << endl;

    //creates a new board and prints it to the file
    Board* board = new Board();
    board->printBoard(game);
    game.close();
    
    bool win = false;
    int move = 0;
    int player = 1;
    string sMove = " ";

    while (win == false)
    {
        //tests player's move
        bool playerBounds = false;
        while (playerBounds == false)
        {
            cout << "Player " << player << ", please play a move: (Type in a column number) ";
            cin >> sMove;
            if (sMove.length()>1)
            {
                cout << "Invalid, try again." << endl;
            }

            else
            {
                sMove = sMove.at(0);
                bool is_ok = false;
                try 
                {
                    move = stoi(sMove);
                    is_ok = true;
                }
                catch(exception)
                {
                    cout << "Invalid, try again." << endl;
                }
                if (is_ok)
                {
                if (move < 1 || move > board->getCol())
                {
                    cout << "Not a valid column, try again." << endl;
                }
                else
                {
                    playerBounds = true;
                }   
                }
            }
        }

        //checks which player is currently moving
        if (player == 1)
        {
            //validating the player's move
            if (p1.validatePlayerMoves(board, move))
            {
                //checks if the board is full, then prints to terminal a tie
                if(board->checkFullBoard() == true)
                {
                    game.open(fileName, ostream::app);
                    game << tie << endl;
                    game.close();
                    win = true;
                }
                //otherwise it sets the player's move to the output file
                else
                {
                board->setBoard(player_one.getToken(), p1.getPlayerMove());
                game.open(fileName);//, ostream::app);
                board->printBoard(game);
                game.close();
                }
            }
            //checks if the column is full
            else
            {
                playerBounds = false;
                cout << "Column is full, cannot make a move there." << endl;
            }
            //checks wins, prints to terminal that the player won
            if (vWin.validate(board))
            {
                win = true;
                game.open(fileName, ostream::app);
                game << p1Win << endl;
                game.close();
            }
            if (hWin.validate(board))
            {
                win = true;
                game.open(fileName, ostream::app);
                game << p1Win << endl;
                game.close();
            }
            if (dWin.validate(board))
            {
                win = true;
                game.open(fileName, ostream::app);
                game << p1Win << endl;
                game.close();
            }
        }  

        //checks player 2's moves
        if (player == 2)
        {
            if (p2.validatePlayerMoves(board, move))
            {
                //if the board is full, it prints to terminal a tie
                if(board->checkFullBoard() == true)
                {
                    game.open(fileName, ostream::app);
                    game << tie << endl;
                    game.close();
                    win = true;
                }
                else
                //otherwise it sets the player move to the board
                {
                board->setBoard(player_two.getToken(), p2.getPlayerMove());
                game.open(fileName);//, ostream::app);
                board->printBoard(game);
                game.close();
                }
            }
            //checks if the column is full
            else
            {
                playerBounds = false;
                cout << "Column is full, cannot make a move there." << endl;
            }
            //checks for wins
            if (vWin.validate(board))
            {
                win = true;
                game.open(fileName, ostream::app);
                game << p2Win << endl;
                game.close();
            }
            if (hWin.validate(board))
            {
                win = true;
                game.open(fileName, ostream::app);
                game << p2Win << endl;
                game.close();
            }
            if (dWin.validate(board))
            {
                win = true;
                game.open(fileName, ostream::app);
                game << p2Win << endl;
                game.close();
            }
        }  

        //alternates between players
        if (playerBounds == true)
        {
            player++;
        }

        if (player>2)
        {
            player=1;
        }

    }

    return 0;
}