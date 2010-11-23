/*
 * Copyright [c] Jon Trent, please see COPYING for MIT License details.
 */

#include <iostream>
#include <string>
#include <time.h>
#include "GameBoard.hh"

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
switchPlayer(Player &currentPlayer);
void
printGameBoard(char gameBoard[9][2]);
string
printTime();
bool
checkWin(char gameBoard[9][2]);
bool
checkPath(char square1, char square2, char square3);
void
game1();

int
main(int argc, char * const argv[]) {
    game1();
    
    cout << "Goodbye" << endl;
    
    return 0;
}

void
switchPlayer(Player &currentPlayer) {
    if (currentPlayer == X) {
        currentPlayer = O;
    } else {
        currentPlayer = X;
    }
}

void
printGameBoard(char gameBoard[9][2]) {
    cout << gameBoard[0][0] << "|" << gameBoard[1][0] << "|" << gameBoard[2][0] << endl;
    cout << "-" << "|" << "-" << "|" << "-" << endl;
    cout << gameBoard[3][0] << "|" << gameBoard[4][0] << "|" << gameBoard[5][0] << endl;
    cout << "-" << "|" << "-" << "|" << "-" << endl;
    cout << gameBoard[6][0] << "|" << gameBoard[7][0] << "|" << gameBoard[8][0] << endl;
}

string
printTime() {
    string  temp;
    time_t  rawtime;
    tm      *timeinfo;
    
    // Get the current time and save it to a string.
    time(&rawtime);
    timeinfo =  localtime(&rawtime);
    temp =      asctime(timeinfo);
    
    // Remove the newline that the asctime function returns.
    temp[temp.size() - 1] = '\0';
    
    return temp;
}

bool
checkWin(char gameBoard[9][2]) {
    // Check all 8 ways of winning.
    // If all the characters of any of these paths have the same characters, we
    // have a win.  If all of these have one of each marker in them, then we 
    // have a draw.
    
    // check 0, 1, 2
    if (checkPath(gameBoard[0][0], gameBoard[1][0], gameBoard[2][0])) {
        return true;
    }
    // check 3, 4, 5
    else if (checkPath(gameBoard[3][0], gameBoard[4][0], gameBoard[5][0])) {
        return true;
    }
    // check 6, 7, 8
    else if (checkPath(gameBoard[6][0], gameBoard[7][0], gameBoard[8][0])) {
        return true;
    }
    // check 0, 3, 6
    else if (checkPath(gameBoard[0][0], gameBoard[3][0], gameBoard[6][0])) {
        return true;
    }
    // check 1, 4, 7
    else if (checkPath(gameBoard[1][0], gameBoard[4][0], gameBoard[7][0])) {
        return true;
    }
    // check 2, 5, 8
    else if (checkPath(gameBoard[2][0], gameBoard[5][0], gameBoard[8][0])) {
        return true;
    }
    // check 0, 4, 7
    else if (checkPath(gameBoard[0][0], gameBoard[4][0], gameBoard[8][0])) {
        return true;
    }
    // check 6, 4, 2
    else if (checkPath(gameBoard[6][0], gameBoard[4][0], gameBoard[2][0])) {
        return true;
    } else {
        return false;
    }
}

bool
checkPath(char square1, char square2, char square3) {
    if ((square1 == square2) && (square1 == square3)) {
        return true;
    } else {
        return false;
    }
}

void
game1() {
    GameState   gameState;
    Player      currentPlayer;
    string      input;
    string      log;
    char        gameBoard[9][2];
    char        marker;
    int         i;
    int         j;
    int         number;
    int         square;
    bool        hasGone;
    
    // Initialize variables.
    gameState =     MAINMENU;
    currentPlayer = X;
    input =         "";
    log =           "";
    i =             0;
    j =             0;
    number =        49;
    square =        0;
    hasGone =       false;
    
    // Initialize gameBoard.
    for (i = 0; i < 9; i++) {
        gameBoard[i][0] = (char)number;
        gameBoard[i][1] = '0';
        number++;
    }
    
    log += printTime();
    log += " Tic-Tac-Toe started\n";
    
    while (input != "q") {
        if (gameState == MAINMENU) {
            cout << "Welcome to Tic Tac Toe" << endl;
            cout << "Type [s] to start" << endl;
            cout << "Type [q] to quit" << endl;
            
            cin >> input;
            
            // If s is typed, we need to change the state to GAME to start playing.
            if (input == "s") {
                log += printTime();
                log += " Game started\n";
                
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
            cout << "Then type [n] to switch to the next player." << endl;
            
            printGameBoard(gameBoard);
            
            // int square = atoi(input.c_str());
            // if input is n, switch to next player
            // else if input is a number...
            //   if number isn't taken, update the square with player's marker.
            //   else, number is taken, try again.
            
            cin >> input;
            
            if (input == "n") {
                switchPlayer(currentPlayer);
                hasGone = false;
            } else if (input != "q") {
                square = atoi(input.c_str()) - 1;
                
                if (gameBoard[square][1] == '0') {
                    if (currentPlayer == X) {
                        marker = 'X';
                    } else {
                        marker = 'O';
                    }
                    
                    gameBoard[square][0] = marker;
                    gameBoard[square][1] = 1;
                    
                    if (!hasGone) {
                        hasGone = true;
                    } else {
                        log += printTime();
                        log += " Player ";
                        
                        if (currentPlayer == X) {
                            log += "X";
                        } else {
                            log += "O";
                        }
                        
                        log += " went again\n";
                    }
                    
                    if (checkWin(gameBoard)) {
                        gameState == GAMEOVER;
                    }
                } else {
                    cout << "Please select an unused square." << endl;
                }
            }
        } else if (gameState == GAMEOVER) {
            cout << "Someone wins!!" << endl;
            input = "q";
        }
    }
    
    log += printTime();
    log += " Tic-Tac-Toe quit.\n";
    
    cout << log << endl;
}