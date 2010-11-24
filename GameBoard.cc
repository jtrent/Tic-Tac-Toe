/*
 *  GameBoard.cc
 *  Tic Tac Toe
 *
 *  Created by Jon Trent on 11/22/10.
 *  Copyright 2010 S3nator Studios. All rights reserved.
 *
 */

#include "GameBoard.hh"

GameBoard::GameBoard()
{
    initializeBoard();
}

void
GameBoard::markSquare(int square, char mark)
{
    gameBoard[square].marker = mark;
}

void
GameBoard::print()
{
    cout << "*****" << endl;
    cout << gameBoard[0].marker << "|" << gameBoard[1].marker << "|" << gameBoard[2].marker << endl;
    cout << "-|-|-" << endl;
    cout << gameBoard[3].marker << "|" << gameBoard[4].marker << "|" << gameBoard[5].marker << endl;
    cout << "-|-|-" << endl;
    cout << gameBoard[6].marker << "|" << gameBoard[7].marker << "|" << gameBoard[8].marker << endl;
    cout << "*****" << endl;
}

void
GameBoard::initializeBoard()
{
    int i;
    int count;
    
    count = 49;
    
    for (i = 0; i < 9; i++) {
        gameBoard[i].marker = (char)count;
        gameBoard[i].isUsed = false;
        
        count++;
    }
}

bool
GameBoard::checkForWin()
{
    // Check all 8 ways of winning.
    // If all the characters of any of these paths have the same characters, we
    // have a win.  If all of these have one of each marker in them, then we 
    // have a draw.
    
    // check 0, 1, 2
    if (checkPath(0, 1, 2)) {
        return true;
    }
    // check 3, 4, 5
    else if (checkPath(3, 4, 5)) {
        return true;
    }
    // check 6, 7, 8
    else if (checkPath(6, 7, 8)) {
        return true;
    }
    // check 0, 3, 6
    else if (checkPath(0, 3, 6)) {
        return true;
    }
    // check 1, 4, 7
    else if (checkPath(1, 4, 7)) {
        return true;
    }
    // check 2, 5, 8
    else if (checkPath(2, 5, 8)) {
        return true;
    }
    // check 0, 4, 7
    else if (checkPath(0, 4, 8)) {
        return true;
    }
    // check 6, 4, 2
    else if (checkPath(6, 4, 2)) {
        return true;
    } else {
        return false;
    }
}

bool
GameBoard::checkPath(int square1, int square2, int square3)
{
    if ((gameBoard[square1].marker == gameBoard[square2].marker) &&
        (gameBoard[square1].marker == gameBoard[square3].marker)) {
        return true;
    } else {
        return false;
    }
}