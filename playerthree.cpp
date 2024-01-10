#include "player.h"
#include "playerthree.h"

/// creating player3.
PlayerThree::PlayerThree(Player *parent) :Player(parent){
    parent->changeChar(3);
}
