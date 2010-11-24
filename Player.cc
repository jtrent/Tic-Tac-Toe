/*
 *  Player.cc
 *  Tic Tac Toe
 *
 *  Created by Jon Trent on 11/22/10.
 *  Copyright 2010 S3nator Studios. All rights reserved.
 *
 */

#include "Player.hh"

/*Player::Player(string aName, char aMarker)
{
    name =      aName;
    marker =    aMarker;
}*/

string
Player::getName()
{
    return name;
}

void
Player::setName(string aName)
{
    name = aName;
}

char
Player::getMarker() {
    return marker;
}

void
Player::setMarker(char aMarker)
{
    marker = aMarker;
}