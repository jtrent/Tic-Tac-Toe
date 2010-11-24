/*
 *  GameController.h
 *  Tic Tac Toe
 *
 *  Created by Jon Trent on 11/22/10.
 *  Copyright 2010 S3nator Studios. All rights reserved.
 *
 */

#ifndef WF_GAMECONTROLLER_HH
#define WF_GAMECONTROLLER_HH

#include <iostream>
#include "GameBoard.hh"
#include "Player.hh"

using namespace std;

// The states of the game.
/*enum GameState
{
    MAINMENU,
    GAME,
    GAMEOVER,
    QUIT
};

enum Players
{
    X,
    O
};*/

class GameController
{
  public:
            GameController();
    string  getLog();
    bool    running();
    void    update(string input);
    void    print();
    enum    GameState {MAINMENU, GAME, GAMEOVER, QUIT};
    enum    Players {X, O};
    
  private:
    GameBoard   gameBoard;
    Player      players[2];
    Players     currentPlayer;
    GameState   gameState;
    Players     winner;
    string      log;
    bool        isRunning;
    void        switchPlayer();
    void        printMainMenu();
    void        printGame();
    void        printGameOver();
};

#endif