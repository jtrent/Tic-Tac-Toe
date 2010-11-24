/*
 *  Player.h
 *  Tic Tac Toe
 *
 *  Created by Jon Trent on 11/22/10.
 *  Copyright 2010 S3nator Studios. All rights reserved.
 *
 */


#ifndef WF_PLAYER_HH
#define WF_PLAYER_HH

#include <string>

using namespace std;

class Player
{
  public:
    // Constructer for Player class.  The player's name (ie 'X' or 'O') as well
    // as the marker used are supplied.
    //Player(string aName, char aMarker);
    string  getName();
    void    setName(string aName);
    char    getMarker();
    void    setMarker(char aMarker);
    
  private:
    string  name;
    char    marker;
};

#endif