#ifndef PLAYERONE_H
#define PLAYERONE_H

#include <QTimer>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QGraphicsScene>
#include "player.h"

class PlayerOne: public Player{
    Q_OBJECT
public:
    PlayerOne(Player *parent = 0);
};

#endif // PLAYERONE_H
