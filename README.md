# ConnectFour
CSCI200 - Foundational Programming Concepts &amp; Design Final Project

A terminal-based implementation of the Connect Four game for two players, written in C++. This program features a dynamic game board, win condition checking, and persistent game state logging to a file.

## Features
*   **Two-Player Gameplay:** Play against another person on the same machine.
*   **Token Selection:** Player One chooses to be 'X' or 'O' at the start.
*   **Win Condition Detection:** Accurately detects horizontal, vertical, and diagonal wins
*   **Draw Detection:** Identifies when the board is full with no winner.
*   **Input Validation:** Handles invalid moves, prompting the user to try again.
*   **Game Logging:** Automatically generates and updates a `Game.txt` file with the board state after every move.

## How to Run
1.  **Compile:** Use the provided Makefile.
    ```bash
    make
    ```
    This will compile the program with the target `main`.

2.  **Execute:** Run the generated executable.
    ```bash
    ./main
    ```

3.  **Play:**
    *   Player One will be prompted to choose 'X' or 'O'.
    *   Players take turns typing the column number (displayed in Game.txt) where they wish to drop their token.
    *   The game continues until a player gets four in a row or the board is full.

## Project Structure & Class Overview
The project focuses on object-oriented principles.

| Class | Description |
| :--- | :--- |
| **`Board`** | The core of the game. Manages the 2D array representing the game grid, updates moves, checks if the board is full, and provides getter functions. |
| **`Token`** | Represents the player tokens ('X' and 'O'). Handles the logic for getting and setting the current token type. |
| **`Win`** | Abstract base class that defines the interface for checking win conditions. |
| `HorizontalWin` | Child class of `Win` that checks for four consecutive tokens in a row. |
| `VerticalWin` | Child class of `Win` that checks for four consecutive tokens in a column. |
| `DiagonalWin` | Child class of `Win` that checks for four consecutive tokens in a diagonal direction (both `\` and `/`). |
| **`Move`** | Validates player moves (ensuring columns are not full) and generates a string representation of the move's location for use in other classes. |

## Data Structures & Techniques

*   **2D Array:** Used as the data structure for the game board for access and manipulation of grid cells.
*   **Polymorphism:** The `Win` class hierarchy allows for win condition checking.
*   **File I/O (`ostream`):** The game state is written to `Game.txt` after each move, providing a persistent record of the game.

## Reflection & Learnings

*   **Planning:** Moving forward, I will spend more time in pseudocode and planning hierarchies before writing code to avoid backtracking and getting confused over where functions and methods belong.
*   **Incremental Testing:** Testing small pieces of functionality as they are being built is far more efficient and convenient than leaving it all at the end.

The project solidified my knowledge of foundational C++ concepts, including:
  *   Pointers.
  *   Abstract classes and polymorphism.
  *   Array manipulation, loops, and edge-cases.
  *   Object-oriented programming.
  *   Error catching

## Future Improvements

*   Keep track of wins, losses, and ties across multiple sessions.
*   Implement an AI opponent for single-player mode (currently only two-player mode)
*   Create a graphical user interface instead of a terminal-based one.
