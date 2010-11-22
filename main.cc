/*
 * Copyright [c] Jon Trent, please see COPYING for MIT License details.
 */

#include <iostream>
#include <string>

using namespace std;

// Various game states.
// The state for the game during the game over condition.
enum WinState {
    XWINS,
    OWINS,
    DRAW
};

// The state to mark if the path is still winable or not.
enum PathState {
    CLEAN,
    DIRTY
};

// The states of the game.
enum GameState {
    MAINMENU,
    GAME,
    GAMEOVER
};

// State for which player's turn it is.
enum Player {
    X,
    O
};

void
switchPlayer(Player currentPlayer);

void
printGameBoard(char gameBoard[3][3]);

int
main(int argc, char * const argv[]) {
    GameState gameState = MAINMENU;
    Player currentPlayer = X;
    string input;
    char gameBoard[3][3];
    int i;
    int j;
    int number;
    int square;
    
    // Initialize gameBoard.
    number = 49;
    
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            gameBoard[i][j] = (char)number;
            number++;
        }
    }
    
    while (input != "q") {
        if (gameState == MAINMENU) {
            cout << "Welcome to Tic Tac Toe" << endl;
            cout << "Type [s] to start" << endl;
            cout << "Type [q] to quit" << endl;
            
            cin >> input;
            
            // If s is typed, we need to change the state to GAME to start playing.
            if (input == "s") {
                gameState = GAME;
            }
        } else if (gameState == GAME) {
            cout << "Player ";
            
            if (currentPlayer == X) {
                cout << "X";
            } else {
                cout << "O";
            }
            
            cout << endl;
            cout << "Please type a number [1..9] to select your square." << endl;
            cout << "Then type \"n\" to switch to the next player." << endl;
            
            printGameBoard(gameBoard);
            
            // int square = atoi(input.c_str());
            cin >> input;
            
        }
    }
    
    cout << "Goodbye" << endl;
    
    return 0;
}

void
switchPlayer(Player currentPlayer) {
    if (currentPlayer == X) {
        currentPlayer = O;
    } else {
        currentPlayer = X;
    }
}

void
printGameBoard(char gameBoard[3][3]) {
    cout << gameBoard[0][0] << "|" << gameBoard[0][1] << "|" << gameBoard[0][2] << endl;
    cout << "-" << "|" << "-" << "|" << "-" << endl;
    cout << gameBoard[1][0] << "|" << gameBoard[1][1] << "|" << gameBoard[1][2] << endl;
    cout << "-" << "|" << "-" << "|" << "-" << endl;
    cout << gameBoard[2][0] << "|" << gameBoard[2][1] << "|" << gameBoard[2][2] << endl;
}