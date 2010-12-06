/*
 * Copyright (c) 2010 Jon Trent
 * For usage information see COPYING for copyright and usage information.
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow)
{
    // Set game count to 1 since this is the first game.
    gameCount =     1;

    // Since no one has played yet, set hasPlayed to false;
    hasPlayed =     false;

    // Starting the game log.
    log =           "Game number ";
    log +=          intToString(gameCount);
    log +=          "\n";

    // The first player is X, or 1.
    currentPlayer = 1;
    initializeGameBoard();

    ui->setupUi(this);

    // X is first, so we hide the Player O label.
    ui->playero->hide();

    // Hiding the win prompt buttons.
    ui->buttonDraw->hide();
    ui->buttonPlayerOWins->hide();
    ui->buttonPlayerXWins->hide();

    // We need to hide squares with values on them so only blank ones show.
    ui->button0o->hide();
    ui->button0x->hide();
    ui->button1o->hide();
    ui->button1x->hide();
    ui->button2o->hide();
    ui->button2x->hide();
    ui->button3o->hide();
    ui->button3x->hide();
    ui->button4o->hide();
    ui->button4x->hide();
    ui->button5o->hide();
    ui->button5x->hide();
    ui->button6o->hide();
    ui->button6x->hide();
    ui->button7o->hide();
    ui->button7x->hide();
    ui->button8o->hide();
    ui->button8x->hide();

    // Make connection for next button.
    connect(ui->buttonNext, SIGNAL(clicked()), this, SLOT(changePlayer()));

    // Make connections for win condition buttons.
    connect(ui->buttonDraw, SIGNAL(clicked()), this, SLOT(drawGame()));
    connect(ui->buttonPlayerOWins, SIGNAL(clicked()),
            this, SLOT(playerOWins()));
    connect(ui->buttonPlayerXWins, SIGNAL(clicked()),
            this, SLOT(playerXWins()));

    // Make connections for the game tile buttons.
    // Square 0
    connect(ui->button0b, SIGNAL(clicked()), this, SLOT(changeButton0()));
    connect(ui->button0o, SIGNAL(clicked()), this, SLOT(changeButton0()));
    connect(ui->button0x, SIGNAL(clicked()), this, SLOT(changeButton0()));
    // Square 1
    connect(ui->button1b, SIGNAL(clicked()), this, SLOT(changeButton1()));
    connect(ui->button1o, SIGNAL(clicked()), this, SLOT(changeButton1()));
    connect(ui->button1x, SIGNAL(clicked()), this, SLOT(changeButton1()));
    // Square 2
    connect(ui->button2b, SIGNAL(clicked()), this, SLOT(changeButton2()));
    connect(ui->button2o, SIGNAL(clicked()), this, SLOT(changeButton2()));
    connect(ui->button2x, SIGNAL(clicked()), this, SLOT(changeButton2()));
    // Square 3
    connect(ui->button3b, SIGNAL(clicked()), this, SLOT(changeButton3()));
    connect(ui->button3o, SIGNAL(clicked()), this, SLOT(changeButton3()));
    connect(ui->button3x, SIGNAL(clicked()), this, SLOT(changeButton3()));
    // Square 4
    connect(ui->button4b, SIGNAL(clicked()), this, SLOT(changeButton4()));
    connect(ui->button4o, SIGNAL(clicked()), this, SLOT(changeButton4()));
    connect(ui->button4x, SIGNAL(clicked()), this, SLOT(changeButton4()));
    // Square 5
    connect(ui->button5b, SIGNAL(clicked()), this, SLOT(changeButton5()));
    connect(ui->button5o, SIGNAL(clicked()), this, SLOT(changeButton5()));
    connect(ui->button5x, SIGNAL(clicked()), this, SLOT(changeButton5()));
    // Square 6
    connect(ui->button6b, SIGNAL(clicked()), this, SLOT(changeButton6()));
    connect(ui->button6o, SIGNAL(clicked()), this, SLOT(changeButton6()));
    connect(ui->button6x, SIGNAL(clicked()), this, SLOT(changeButton6()));
    // Square 7
    connect(ui->button7b, SIGNAL(clicked()), this, SLOT(changeButton7()));
    connect(ui->button7o, SIGNAL(clicked()), this, SLOT(changeButton7()));
    connect(ui->button7x, SIGNAL(clicked()), this, SLOT(changeButton7()));
    // Square 8
    connect(ui->button8b, SIGNAL(clicked()), this, SLOT(changeButton8()));
    connect(ui->button8o, SIGNAL(clicked()), this, SLOT(changeButton8()));
    connect(ui->button8x, SIGNAL(clicked()), this, SLOT(changeButton8()));
}

MainWindow::~MainWindow()
{
    saveLog();
    delete ui;
}

std::string
MainWindow::intToString(int number)
{
    std::stringstream    out;

    out << number;

    return out.str();
}

void
MainWindow::initializeGameBoard()
{
    int i;
    int j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            gameBoard[i][j] =   0;
        }
    }
}

void
MainWindow::saveLog()
{
    std::ofstream   outFile;

    outFile.open("ttt-log.txt");
    outFile << log;
    outFile.close();
}

void
MainWindow::checkForWin()
{
    int     i;
    int     square;
    bool    isWon;

    isWon = false;

    // Check rows.
    for (i = 0; i < 3; i++) {
        square =    gameBoard[i][0];

        if (square != 0) {
            if ((gameBoard[i][1] == square) && (gameBoard[i][2] == square)) {
                isWon = true;
            }
        }
    }

    // Check columns.
    for (i = 0; i < 3; i++) {
        square =    gameBoard[0][i];

        if (square != 0) {
            if ((gameBoard[1][i] == square) && (gameBoard[2][i] == square)) {
                isWon = true;
            }
        }
    }

    // Check diagonal.
    square =    gameBoard[0][0];

    if (square != 0) {
        if ((gameBoard[1][1] == square) && (gameBoard[2][2] == square)) {
            isWon = true;
        }
    }

    // Reverse diagonal.
    square =    gameBoard[0][2];

    if (square != 0) {
        if ((gameBoard[1][1] == square) && (gameBoard[2][0] == square)) {
            isWon = true;
        }
    }

    // We check to see if isWon is true, then call announceWinner().
    if (isWon) {
        announceWinner();
    }
}

void
MainWindow::checkForDraw()
{
    int         i;
    int         j;
    int         zeroCount;
    bool        isDraw;

    isDraw =        true;

    // Check rows.
    // If any rows are blank, we can still play.
    for (i = 0; i < 3; i++) {
        zeroCount = 0;

        for (j = 0; j < 3; j++) {
            if (gameBoard[i][j] == 0) {
                zeroCount++;
            }
        }

        if (zeroCount >= 2) {
            isDraw =    false;
        }
    }

    // If any rows have only the same symbol, we can still play
    for (i = 0; i < 3; i++) {
        if (((gameBoard[i][0] == gameBoard[i][1]) &&
             (gameBoard[i][2] == 0)) ||
            ((gameBoard[i][0] == gameBoard[i][2]) &&
             (gameBoard[i][1] == 0)) ||
            ((gameBoard[i][1] == gameBoard[i][2]) &&
             (gameBoard[i][0] == 0))) {
            isDraw =    false;
        }
    }

    // Check columns.
    // If any columns are blank, we can still play.
    for (i = 0; i < 3; i++) {
        zeroCount = 0;

        for (j = 0; j < 3; j++) {
            if (gameBoard[j][i] == 0) {
                zeroCount++;
            }

            if (zeroCount >= 2) {
                isDraw =    false;
            }
        }
    }

    // If any columns have only the same symbol, we can still play
    for (i = 0; i < 3; i++) {
        if (((gameBoard[0][i] == gameBoard[1][i]) &&
             (gameBoard[2][i] == 0)) ||
            ((gameBoard[0][i] == gameBoard[2][i]) &&
             (gameBoard[1][i] == 0)) ||
            ((gameBoard[1][i] == gameBoard[2][i]) &&
             (gameBoard[0][i] == 0))) {
            isDraw =    false;
        }
    }

    // Check diagonal.
    // If the diagonal is blank, we can still play.
    zeroCount = 0;
    for (i = 0; i < 3; i++) {
        if (gameBoard[i][i] == 0) {
            zeroCount++;
        }
    }

    if (zeroCount >= 2) {
        isDraw =    false;
    }

    // If the diagonal have only the same symbol, we can still play
    if (((gameBoard[0][0] == gameBoard[1][1]) && (gameBoard[2][2] == 0)) ||
        ((gameBoard[0][0] == gameBoard[2][2]) && (gameBoard[1][1] == 0)) ||
        ((gameBoard[1][1] == gameBoard[2][2]) && (gameBoard[0][0] == 0))) {
        isDraw =    false;
    }

    // Check reverse diagonal.
    // If the reverse diagonal is blank, we can still play.
    zeroCount = 0;
    for (i = 0; i < 3; i++) {
        for (j = 2; j > -1; j--) {
            if (gameBoard[i][j] == 0) {
                zeroCount++;
            }
        }
    }

    if (zeroCount >= 2) {
        isDraw =    false;
    }

    // If the reverse diagonal have only the same symbol, we can still play
    if (((gameBoard[0][2] == gameBoard[1][1]) && (gameBoard[2][0] == 0)) ||
        ((gameBoard[0][2] == gameBoard[2][0]) && (gameBoard[1][1] == 0)) ||
        ((gameBoard[1][1] == gameBoard[2][0]) && (gameBoard[0][2] == 0))) {
        isDraw =    false;
    }

    if (isDraw) {
        announceDraw();
    }
}

void
MainWindow::announceWinner()
{
    if (currentPlayer == 1) {
        ui->buttonPlayerXWins->show();

        log +=  "Player X wins.\n";
    } else {
        ui->buttonPlayerOWins->show();

        log +=  "Player O wins.\n";
    }

    resetGame();
}

void
MainWindow::announceDraw()
{
    ui->buttonDraw->show();

    log +=  "Draw game.\n";

    resetGame();
}

void
MainWindow::resetGame()
{
    // Hide X, O buttons.
    // Button 0.
    ui->button0o->hide();
    ui->button0x->hide();
    // Button 1.
    ui->button1o->hide();
    ui->button1x->hide();
    // Button 2.
    ui->button2o->hide();
    ui->button2x->hide();
    // Button 3.
    ui->button3o->hide();
    ui->button3x->hide();
    // Button 4.
    ui->button4o->hide();
    ui->button4x->hide();
    // Button 5.
    ui->button5o->hide();
    ui->button5x->hide();
    // Button 6.
    ui->button6o->hide();
    ui->button6x->hide();
    // Button 7.
    ui->button7o->hide();
    ui->button7x->hide();
    // Button 8.
    ui->button8o->hide();
    ui->button8x->hide();

    // Show blank buttons.
    // Button 0.
    ui->button0b->show();
    // Button 1.
    ui->button1b->show();
    // Button 2.
    ui->button2b->show();
    // Button 3.
    ui->button3b->show();
    // Button 4.
    ui->button4b->show();
    // Button 5.
    ui->button5b->show();
    // Button 6.
    ui->button6b->show();
    // Button 7.
    ui->button7b->show();
    // Button 8.
    ui->button8b->show();

    // Reset currentPlayer and gameBoard.
    currentPlayer = 1;
    initializeGameBoard();
    ui->playero->hide();
    ui->playerx->show();

    // Save log.
    saveLog();

    // Update gameCount and log.
    gameCount++;
    log += "Game number ";
    log += intToString(gameCount);
    log += "\n";
}

void
MainWindow::changeButton0()
{
    // Check to see which player is clicking the button.
    if (currentPlayer == 1) {
        // Check to see if the square is blank or not.
        if (gameBoard[0][0] == 0) {
            // If hasPlayed is true, update log player is going twice.
            if (hasPlayed) {
                log +=  "Player X has gone twice.\n";
            }

            ui->button0b->hide();
            ui->button0x->show();

            gameBoard[0][0] =   1;
            hasPlayed =         true;

            // Note log that X is going and what he is marking.
            log +=              "Player X has selected square 1.\n";

            checkForWin();
            checkForDraw();
        } else {
            ui->button0b->show();
            ui->button0o->hide();
            ui->button0x->hide();

            gameBoard[0][0] =   0;

            // Note log that X has cleared a square.
            log +=              "Player X has cleared square 1.\n";
        }
    } else {
        // Check to see if the square is blank or not.
        if (gameBoard[0][0] == 0) {
            // If hasPlayed is true, update log player is going twice.
            if (hasPlayed) {
                log +=  "Player O has gone twice.\n";
            }

            ui->button0b->hide();
            ui->button0o->show();

            gameBoard[0][0] =   2;
            hasPlayed =         true;

            // Note log that O is going and what he is marking.
            log +=              "Player O has selected square 1.\n";

            checkForWin();
            checkForDraw();
        } else {
            ui->button0b->show();
            ui->button0o->hide();
            ui->button0x->hide();

            gameBoard[0][0] =   0;

            // Note log that O has cleared a square.
            log +=              "Player O has cleared square 1.\n";
        }
    }
}

void
MainWindow::changeButton1()
{
    // Check to see which player is clicking the button.
    if (currentPlayer == 1) {
        // Check to see if the square is blank or not.
        if (gameBoard[0][1] == 0) {
            // If hasPlayed is true, update log player is going twice.
            if (hasPlayed) {
                log +=  "Player X has gone twice.\n";
            }

            ui->button1b->hide();
            ui->button1x->show();

            gameBoard[0][1] =   1;
            hasPlayed =         true;

            // Note log that X is going and what he is marking.
            log +=              "Player X has selected square 2.\n";

            checkForWin();
            checkForDraw();
        } else {
            ui->button1b->show();
            ui->button1o->hide();
            ui->button1x->hide();

            gameBoard[0][1] =   0;

            // Note log that X has cleared a square.
            log +=              "Player X has cleared square 2.\n";
        }
    } else {
        // Check to see if the square is blank or not.
        if (gameBoard[0][1] == 0) {
            // If hasPlayed is true, update log player is going twice.
            if (hasPlayed) {
                log +=  "Player O has gone twice.\n";
            }

            ui->button1b->hide();
            ui->button1o->show();

            gameBoard[0][1] =   2;
            hasPlayed =         true;

            // Note log that O is going and what he is marking.
            log +=              "Player O has selected square 2.\n";

            checkForWin();
            checkForDraw();
        } else {
            ui->button1b->show();
            ui->button1o->hide();
            ui->button1x->hide();

            gameBoard[0][1] =   0;

            // Note log that O has cleared a square.
            log +=              "Player O has cleared square 2.\n";
        }
    }
}

void
MainWindow::changeButton2()
{
    // Check to see which player is clicking the button.
    if (currentPlayer == 1) {
        // Check to see if the square is blank or not.
        if (gameBoard[0][2] == 0) {
            // If hasPlayed is true, update log player is going twice.
            if (hasPlayed) {
                log +=  "Player X has gone twice.\n";
            }

            ui->button2b->hide();
            ui->button2x->show();

            gameBoard[0][2] =   1;
            hasPlayed =         true;

            // Note log that X is going and what he is marking.
            log +=              "Player X has selected square 3.\n";

            checkForWin();
            checkForDraw();
        } else {
            ui->button2b->show();
            ui->button2o->hide();
            ui->button2x->hide();

            gameBoard[0][2] =   0;

            // Note log that X has cleared a square.
            log +=              "Player X has cleared square 3.\n";
        }
    } else {
        // Check to see if the square is blank or not.
        if (gameBoard[0][2] == 0) {
            // If hasPlayed is true, update log player is going twice.
            if (hasPlayed) {
                log +=  "Player O has gone twice.\n";
            }

            ui->button2b->hide();
            ui->button2o->show();

            gameBoard[0][2] =   2;
            hasPlayed =         true;

            // Note log that O is going and what he is marking.
            log +=              "Player O has selected square 3.\n";

            checkForWin();
            checkForDraw();
        } else {
            ui->button2b->show();
            ui->button2o->hide();
            ui->button2x->hide();

            gameBoard[0][2] =   0;

            // Note log that O has cleared a square.
            log +=              "Player O has cleared square 3.\n";
        }
    }
}

void
MainWindow::changeButton3()
{
    // Check to see which player is clicking the button.
    if (currentPlayer == 1) {
        // Check to see if the square is blank or not.
        if (gameBoard[1][0] == 0) {
            // If hasPlayed is true, update log player is going twice.
            if (hasPlayed) {
                log +=  "Player X has gone twice.\n";
            }

            ui->button3b->hide();
            ui->button3x->show();

            gameBoard[1][0] =   1;
            hasPlayed =         true;

            // Note log that X is going and what he is marking.
            log +=              "Player X has selected square 4.\n";

            checkForWin();
            checkForDraw();
        } else {
            ui->button3b->show();
            ui->button3o->hide();
            ui->button3x->hide();

            gameBoard[1][0] =   0;

            // Note log that X has cleared a square.
            log +=              "Player X has cleared square 4.\n";
        }
    } else {
        // Check to see if the square is blank or not.
        if (gameBoard[1][0] == 0) {
            // If hasPlayed is true, update log player is going twice.
            if (hasPlayed) {
                log +=  "Player O has gone twice.\n";
            }

            ui->button3b->hide();
            ui->button3o->show();

            gameBoard[1][0] =   2;
            hasPlayed =         true;

            // Note log that O is going and what he is marking.
            log +=              "Player O has selected square 4.\n";

            checkForWin();
            checkForDraw();
        } else {
            ui->button3b->show();
            ui->button3o->hide();
            ui->button3x->hide();

            gameBoard[1][0] =   0;

            // Note log that O has cleared a square.
            log +=              "Player O has cleared square 4.\n";
        }
    }
}

void
MainWindow::changeButton4()
{
    // Check to see which player is clicking the button.
    if (currentPlayer == 1) {
        // Check to see if the square is blank or not.
        if (gameBoard[1][1] == 0) {
            // If hasPlayed is true, update log player is going twice.
            if (hasPlayed) {
                log +=  "Player X has gone twice.\n";
            }

            ui->button4b->hide();
            ui->button4x->show();

            gameBoard[1][1] =   1;
            hasPlayed =         true;

            // Note log that X is going and what he is marking.
            log +=              "Player X has selected square 5.\n";

            checkForWin();
            checkForDraw();
        } else {
            ui->button4b->show();
            ui->button4o->hide();
            ui->button4x->hide();

            gameBoard[1][1] =   0;

            // Note log that X has cleared a square.
            log +=              "Player X has cleared square 5.\n";
        }
    } else {
        // Check to see if the square is blank or not.
        if (gameBoard[1][1] == 0) {
            // If hasPlayed is true, update log player is going twice.
            if (hasPlayed) {
                log +=  "Player O has gone twice.\n";
            }

            ui->button4b->hide();
            ui->button4o->show();

            gameBoard[1][1] =   2;
            hasPlayed =         true;

            // Note log that O is going and what he is marking.
            log +=              "Player O has selected square 5.\n";

            checkForWin();
            checkForDraw();
        } else {
            ui->button4b->show();
            ui->button4o->hide();
            ui->button4x->hide();

            gameBoard[1][1] =   0;

            // Note log that O has cleared a square.
            log +=              "Player O has cleared square 5.\n";
        }
    }
}

void
MainWindow::changeButton5()
{
    // Check to see which player is clicking the button.
    if (currentPlayer == 1) {
        // Check to see if the square is blank or not.
        if (gameBoard[1][2] == 0) {
            // If hasPlayed is true, update log player is going twice.
            if (hasPlayed) {
                log +=  "Player X has gone twice.\n";
            }

            ui->button5b->hide();
            ui->button5x->show();

            gameBoard[1][2] =   1;
            hasPlayed =         true;

            // Note log that X is going and what he is marking.
            log +=              "Player X has selected square 6.\n";

            checkForWin();
            checkForDraw();
        } else {
            ui->button5b->show();
            ui->button5o->hide();
            ui->button5x->hide();

            gameBoard[1][2] =   0;

            // Note log that X has cleared a square.
            log +=              "Player X has cleared square 6.\n";
        }
    } else {
        // Check to see if the square is blank or not.
        if (gameBoard[1][2] == 0) {
            // If hasPlayed is true, update log player is going twice.
            if (hasPlayed) {
                log +=  "Player O has gone twice.\n";
            }

            ui->button5b->hide();
            ui->button5o->show();

            gameBoard[1][2] =   2;
            hasPlayed =         true;

            // Note log that O is going and what he is marking.
            log +=              "Player O has selected square 6.\n";

            checkForWin();
            checkForDraw();
        } else {
            ui->button5b->show();
            ui->button5o->hide();
            ui->button5x->hide();

            gameBoard[1][2] =   0;

            // Note log that O has cleared a square.
            log +=              "Player O has cleared square 6.\n";
        }
    }
}

void
MainWindow::changeButton6()
{
    // Check to see which player is clicking the button.
    if (currentPlayer == 1) {
        // Check to see if the square is blank or not.
        if (gameBoard[2][0] == 0) {
            // If hasPlayed is true, update log player is going twice.
            if (hasPlayed) {
                log +=  "Player X has gone twice.\n";
            }

            ui->button6b->hide();
            ui->button6x->show();

            gameBoard[2][0] =   1;
            hasPlayed =         true;

            // Note log that X is going and what he is marking.
            log +=              "Player X has selected square 7.\n";

            checkForWin();
            checkForDraw();
        } else {
            ui->button6b->show();
            ui->button6o->hide();
            ui->button6x->hide();

            gameBoard[2][0] =   0;

            // Note log that X has cleared a square.
            log +=              "Player X has cleared square 7.\n";
        }
    } else {
        // Check to see if the square is blank or not.
        if (gameBoard[2][0] == 0) {
            // If hasPlayed is true, update log player is going twice.
            if (hasPlayed) {
                log +=  "Player O has gone twice.\n";
            }

            ui->button6b->hide();
            ui->button6o->show();

            gameBoard[2][0] =   2;
            hasPlayed =         true;

            // Note log that O is going and what he is marking.
            log +=              "Player O has selected square 7.\n";

            checkForWin();
            checkForDraw();
        } else {
            ui->button6b->show();
            ui->button6o->hide();
            ui->button6x->hide();

            gameBoard[2][0] =   0;

            // Note log that O has cleared a square.
            log +=              "Player O has cleared square 7.\n";
        }
    }
}

void
MainWindow::changeButton7()
{
    // Check to see which player is clicking the button.
    if (currentPlayer == 1) {
        // Check to see if the square is blank or not.
        if (gameBoard[2][1] == 0) {
            // If hasPlayed is true, update log player is going twice.
            if (hasPlayed) {
                log +=  "Player X has gone twice.\n";
            }

            ui->button7b->hide();
            ui->button7x->show();

            gameBoard[2][1] =   1;
            hasPlayed =         true;

            // Note log that X is going and what he is marking.
            log +=              "Player X has selected square 8.\n";

            checkForWin();
            checkForDraw();
        } else {
            ui->button7b->show();
            ui->button7o->hide();
            ui->button7x->hide();

            gameBoard[2][1] =   0;

            // Note log that X has cleared a square.
            log +=              "Player X has cleared square 8.\n";
        }
    } else {
        // Check to see if the square is blank or not.
        if (gameBoard[2][1] == 0) {
            // If hasPlayed is true, update log player is going twice.
            if (hasPlayed) {
                log +=  "Player O has gone twice.\n";
            }

            ui->button7b->hide();
            ui->button7o->show();

            gameBoard[2][1] =   2;
            hasPlayed =         true;

            // Note log that O is going and what he is marking.
            log +=              "Player O has selected square 8.\n";

            checkForWin();
            checkForDraw();
        } else {
            ui->button7b->show();
            ui->button7o->hide();
            ui->button7x->hide();

            gameBoard[2][1] =   0;

            // Note log that O has cleared a square.
            log +=              "Player O has cleared square 8.\n";
        }
    }
}

void
MainWindow::changeButton8()
{
    // Check to see which player is clicking the button.
    if (currentPlayer == 1) {
        // Check to see if the square is blank or not.
        if (gameBoard[2][2] == 0) {
            // If hasPlayed is true, update log player is going twice.
            if (hasPlayed) {
                log +=  "Player X has gone twice.\n";
            }

            ui->button8b->hide();
            ui->button8x->show();

            gameBoard[2][2] =   1;
            hasPlayed =         true;

            // Note log that X is going and what he is marking.
            log +=              "Player X has selected square 9.\n";

            checkForWin();
            checkForDraw();
        } else {
            ui->button8b->show();
            ui->button8o->hide();
            ui->button8x->hide();

            gameBoard[2][2] =   0;

            // Note log that X has cleared a square.
            log +=              "Player X has cleared square 9.\n";
        }
    } else {
        // Check to see if the square is blank or not.
        if (gameBoard[2][2] == 0) {
            // If hasPlayed is true, update log player is going twice.
            if (hasPlayed) {
                log +=  "Player O has gone twice.\n";
            }

            ui->button8b->hide();
            ui->button8o->show();

            gameBoard[2][2] =   2;
            hasPlayed =         true;

            // Note log that O is going and what he is marking.
            log +=              "Player O has selected square 9.\n";

            checkForWin();
            checkForDraw();
        } else {
            ui->button8b->show();
            ui->button8o->hide();
            ui->button8x->hide();

            gameBoard[2][2] =   0;

            // Note log that O has cleared a square.
            log +=              "Player O has cleared square 9.\n";
        }
    }
}

void
MainWindow::changePlayer()
{
    if (currentPlayer == 1) {
        ui->playero->show();
        ui->playerx->hide();

        currentPlayer = 2;
        log +=          "Switching to Player O.\n";
    } else {
        ui->playero->hide();
        ui->playerx->show();

        currentPlayer = 1;
        log +=          "Switching to Player X.\n";
    }

    hasPlayed = false;
}

void
MainWindow::drawGame()
{
    ui->buttonDraw->hide();
}

void
MainWindow::playerOWins()
{
    ui->buttonPlayerOWins->hide();
}

void
MainWindow::playerXWins()
{
    ui->buttonPlayerXWins->hide();
}
