#include "player.h"
#include "playerone.h"

/// creating player1.
PlayerOne::PlayerOne(Player *parent) :Player(parent){
    parent->changeChar(1);
}



