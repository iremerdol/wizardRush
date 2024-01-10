#include "player.h"
#include "playertwo.h"

/// creating player2.
PlayerTwo::PlayerTwo(Player *parent) :Player(parent){
    parent->changeChar(2);
}

