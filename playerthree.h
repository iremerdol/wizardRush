#ifndef PLAYERTHREE_H
#define PLAYERTHREE_H

#include <QTimer>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QGraphicsScene>
#include "player.h"

class PlayerThree: public Player{
    Q_OBJECT
public:
    PlayerThree(Player *parent = 0);
};

#endif // PLAYERTHREE_H
