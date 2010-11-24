/*
 *  GameController.cpp
 *  Tic Tac Toe
 *
 *  Created by Jon Trent on 11/22/10.
 *  Copyright 2010 S3nator Studios. All rights reserved.
 *
 */

#include "GameController.hh"

GameController::GameController()
{
    players[0].setName("Player X");
    players[0].setMarker('X');
    players[1].setName("Player O");
    players[1].setMarker('O');
    
    gameState = MAINMENU;
    isRunning = true;
}

bool
GameController::running()
{
    return isRunning;
}

void
GameController::update(string input)
{
    int square;
    
    if (gameState == MAINMENU) {
        if (input == "q") {
            isRunning = false;
            gameState = QUIT;
        } else if (input == "s") {
            gameState = GAME;
        }
    } else if (gameState == GAME) {
        if (input == "q") {
            isRunning = false;
            gameState = QUIT;
        } else if (input == "n") {
            switchPlayer();
        } else {
            square = atoi(input.c_str()) - 1;
            gameBoard.markSquare(square, players[currentPlayer].getMarker());
        }
    }
}

void
GameController::print()
{
    if (gameState == MAINMENU) {
        printMainMenu();
    } else if (gameState == GAME) {
        printGame();
    } else if (gameState == GAMEOVER) {
        
    } else if (gameState == QUIT) {
        cout << "Quiting" << endl;
    }
}

void
GameController::switchPlayer()
{
    if (currentPlayer == X) {
        currentPlayer = O;
    } else {
        currentPlayer = X;
    }
}

void
GameController::printMainMenu()
{
    cout << "***********************" << endl;
    cout << "Welcom to Tic-Tac-Toe!!" << endl;
    cout << "***********************" << endl;
    cout << endl;
    cout << "Press \"s\" to start." << endl;
    cout << "Press \"q\" to quit." << endl;
}

void
GameController::printGame()
{
    cout << players[currentPlayer].getName() << endl;
    gameBoard.print();
}

void
GameController::printGameOver()
{
}