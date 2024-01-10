#ifndef POTION_H
#define POTION_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <iostream>
#include <QDebug>
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>

class Potion: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Potion(QGraphicsItem * parent=0);
    QTimer *timerP;
public slots:
    void movePotion();
};

#endif // POTION_H
