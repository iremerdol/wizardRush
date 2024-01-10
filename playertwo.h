#ifndef PLAYERTWO_H
#define PLAYERTWO_H

#include <QTimer>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QGraphicsScene>
#include "player.h"

class PlayerTwo: public Player{
    Q_OBJECT
public:
    PlayerTwo(Player *parent = 0);
};

#endif // PLAYERTWO_H
