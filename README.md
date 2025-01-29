# cs200
Amy Cao - ConnectFour
CS200 - Foundational Programming Concepts &amp; Design Final Project

Problem Description:
I created a program that lets you play Connect Four with another player as a 2 player game. 
There is a blank board(grid) generated, and player one, who goes first, can pick to be either “X” or “O”
and player two will be the other token type. A Game.txt file will be generated and the terminal will 
ask you to play a move. If invalid, the player must input another value until it is a valid move.
When either player gets four in a row (horizontally, vertically, diagonally) or the board is full with no four in a row,
the game ends.

Program Documentation:
run the Makefile, target is main. Terminal will ask you to type in letter 'X' or 'O' to determine token types,
then generates a Game.txt file where the board and player moves will be generated. In terminal, it'll ask you to 
play a valid move by typing in the column number. Things I didn't do that I originally planned on doing: counting wins, losses,
and ties --> I just didn't have the time to implement them. I also adjusted where some of the functions and classes would go
because I ended up getting confused if the class name didn't match the function name in some form. 

Class Description:
Board --> creates the board from an array of strings where you can update moves. Also has some getter functions to get the values
as needed in other classes. Also has a checkFullBoard function to see if the board is completely full with no wins.
Token --> creates the token types used throughout the game and to be updated in the board in the Board class. Has getter and setter
functions to be used in main.cpp and in other classes.
Win --> interface for different Win child classes
HorizontalWin --> checks the board for horizontal win of either token type, child class of Win
VerticalWin --> checks the board for vertical win of either token type, child class of Win
DiagonalWin --> checks the board for a diagonal win of '\' or '/' types of either token type, child class of Win
Move --> checks if the player's move is placed where there are empty columns starting from the bottom row up, then creates
a string of that row and column to be used in other classes. also has a get method for that string.

All classes were divided how they were to organize the different functions so that it would be easier to know which is which and 
what to use.

List Data Structure: used a 2D array for generating the board --> board was going to be easiest to make with a 2D array,
especially with getting and setting different board values. It's the backbone of the project, otherwise there would be no game.

File I/O: ostream was used to make a game file where you can actually see and play the game from one move to the next.
Having it in the terminal would be inconvinent so the only other way to see and update the game file is through other file, which
would need ostream.

Reflection: I learned a lot about patience and organization from this project. I got a better understanding of how to utilize arrays
and being careful with the bounds of my loops. It strengthened my understanding of pointers and abstract functions, and it ended up
being pretty fun to see it start from scratch to a fully functional project. If I were to do it differently, I would first implement 
pseudocode to layout exactly what functions go where, if it should go in one class or the other, and being mindful to continuously test 
code as I go through the process. I had to move around a lot of functions and I implemented more classes than I originally thought, so I
would try to be more organized and have a solid understanding of where things would go before going into it blindly.
