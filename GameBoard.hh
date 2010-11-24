/*
 *  GameBoard.h
 *  Tic Tac Toe
 *
 *  Created by Jon Trent on 11/22/10.
 *  Copyright 2010 S3nator Studios. All rights reserved.
 *
 */

#ifndef WF_GAMEBOARD_HH
#define WF_GAMEBOARD_HH

#include <iostream>

using namespace std;

struct GameSquare
{
    char    marker;
    bool    isUsed;
};

class GameBoard
{
  public:
                GameBoard();
    void        markSquare(int square, char mark);
    bool        checkForWin();
    void        print();

  private:
    GameSquare  gameBoard[9];
    void        initializeBoard();
    bool        checkPath(int square1, int square2, int square3);
};

#endif