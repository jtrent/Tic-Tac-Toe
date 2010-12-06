/*
 * Copyright (c) 2010 Jon Trent
 * For usage information see COPYING for copyright and usage information.
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include <sstream>
#include <fstream>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit        MainWindow(QWidget *parent = 0);
                    ~MainWindow();

private:
    // Qt's main window.
    Ui::MainWindow  *ui;
    // Each value is the state of a square.  0 = blank, 1 = X, and 2 = O.
    int             gameBoard[3][3];
    // Determines who's turn it is.  1 = Player X, and 2 = Player O.
    int             currentPlayer;
    // Field to keep track if the same player has gone twice in a row.
    bool            hasPlayed;
    // This field counts how many games have been played so far.
    int             gameCount;
    std::string     log;

    /**
      * A helper function to convert ints to strings for the log.
      */
    std::string     intToString(int number);
    /**
      * This function is called to save the log to disk when the game is won
      * or a draw.
      */
    void            saveLog();
    /**
      * Initiallized all of the spaces in the game board to 0.
      */
    void            initializeGameBoard();
    /**
      * Checks for win condition by checking every possible way to win.
      */
    void            checkForWin();
    /**
      * Checks for a draw condition.  It checks to make sure that every
      * possible way does not have more than one symbol in it.
      */
    void            checkForDraw();
    /**
      * Displays who the winner is with the correct prompt and resets
      * gameBoard.  It determines who the winner is from the currentPlayer
      * field.
      */
    void            announceWinner();
    /**
      * Displays draw game prompt and reset gameBoard.
      */
    void            announceDraw();
    /**
      * The function called by announceDraw() and announceWinner() to reset
      * gameBoard.
      */
    void            resetGame();

// Private slots are used by Qt's buttons so that they can perform actions.
private slots:
    /**
      * The following changeButton slots change the square on the Tic Tac Toe
      * board.  Calling the button with the appropriate number postfix will
      * determine which square is played.  The function checks to see if the
      * square is currently blank, and sets the square to the current
      * player's symbol.  If the square is not blank, clicking the square
      * causes it to become blank.  The game checks for win and draw
      * conditions after the square has been set to a player's symbol.
      */
    void            changeButton0();
    void            changeButton1();
    void            changeButton2();
    void            changeButton3();
    void            changeButton4();
    void            changeButton5();
    void            changeButton6();
    void            changeButton7();
    void            changeButton8();
    void            changePlayer();
    /**
      * Function that is called when clicking on the draw game prompt.  It
      * hides the prompt so the next game can be started.
      */
    void            drawGame();
    /**
      * Function that is called when clicking on the player 0 wins prompt.
      * It hides the prompt so the next game can be started.
      */
    void            playerOWins();
    /**
      * Function that is called when clicking on the player x wins prompt.
      * It hides the prompt so the next game can be started.
      */
    void            playerXWins();
};

#endif // MAINWINDOW_H
