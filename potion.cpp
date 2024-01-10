#include "potion.h"
#include "game.h"

extern Game * game;

/// constructor of the potion class.
/// defining the base factors of the potion object
Potion::Potion(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    //setting potion spesificly for player3
    if(game->isPlayer3){
        setPos(650,420);
        QPixmap imageSecond (":/assets/potion.png");
        setPixmap(imageSecond.scaled(100,100, Qt::KeepAspectRatio));
        setTransformOriginPoint(50,50);

        // make/connect a timer to move() the potion every so often
        timerP = new QTimer(this);
        connect(timerP,SIGNAL(timeout()),this,SLOT(movePotion()));

        // start the timer
        int randomSpeed = (rand() % 15) + 9;
        timerP->start(10 + randomSpeed);
    }
}

/// calculating the potions' moving speed.
/// every potion's speed differs randomly
void Potion::movePotion(){
    // move potion
    int randSpeed = (rand() % 9) + 5;
    setPos(x()-randSpeed,y());

    // get a list of all the items currently colliding with this potion
    QList<QGraphicsItem *> colliding_items = collidingItems();

    // if one of the colliding items is the Player, destroy the potion
    for(int i = 0, n = colliding_items.size(); i < n; ++i){
        if(typeid(*(colliding_items[i])) == typeid(Player)){
            //increase the health
            game->health->increase();
            delete this;
            return;
        }
    }

    // destroy potion when it goes out of the screen
    if(pos().x() + 80 < 0){
        scene()->removeItem(this);
        delete this;
    }
}

