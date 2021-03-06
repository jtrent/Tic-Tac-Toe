Copyright (c) 2010 Jon Trent
For usage information see COPYING for copyright and license information.

README -- Tic Tac Toe
================

This Tic Tac Toe game is designed to measure how well children play with each other. As children take their turns, they are given a choice to switch to the next player, or to continue selecting squares. When a child makes a move, a log file is updated that details what move they have made and if they are moving out of turn or not. The log is also noted when a player wins, and if there is a draw.

* A note on the code *
Because I couldn't get the buttons to display images programmatically, I had to find a way around that. I even tried compiling classmates programs that did work, and the images would not display right. Since I am developing this program on a Mac for another system, I had to find another way to develop it in a way that I knew would work on both systems. My workaround was to use a button per state, per square. This way I could use Qt Creator to manually put the images on the buttons. Then the buttons were hidden depending on who's square it was, who's turn it was, and so on. It is not the most efficient way to do this and resulted in me not being able to use arrays of buttons and other conventions that would have made the code look better.

CONTENTS
------------------

COPYING
images/B.bmp
images/Background.bmp
images/drawgame.bmp
images/nextplayer.bmp
images/O.bmp
images/playero.bmp
images/playerowins.bmp
images/playerx.bmp
images/playerxwins.bmp
images/X.bmp
main.cpp
mainwindow.cpp
mainwindow.h
mainwindow.ui
README
TicTacToe.qrc
ttt.pro
ttt.pro.user

INSTALL
-------

To install on a linux computer, cd to ttt/. Run qmake-qt4 ttt.pro, then qmake to generate the makefile. Then run make to compile the program to produce the "ttt" executable.

USAGE
-----

Run the executable. The game starts with a blank board and player X is the first player to play. The player presses the next button to switch to the next player, player O. The players continue to mark their squares until a player wins, or the there is a draw. The players are prompted that someone won, or that there was a draw, and clicking anywhere on the screen will begin a new game.
