#include "enemy.h"

extern Game * game;

/// constructor of the enemy class.
/// defining the base factors of the enemy object
Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    //set random x position
    if(game->isPlayer1 || game->isPlayer3){
        //setting the initial position of player in the screen
        setPos(650,420);

        // drew the rect
        QPixmap imageSecond (":/assets/enemy.png");
        setPixmap(imageSecond.scaled(100,100, Qt::KeepAspectRatio));
        setTransformOriginPoint(50,50);

        // make/connect a timer to move() the enemy every so often
        QTimer * timer = new QTimer(this);
        connect(timer,SIGNAL(timeout()),this,SLOT(move()));

        // start the timer
        int randomSpeed = (rand() % 14) + 3;
        timer->start(10 + randomSpeed);
    }
    if(game->isPlayer2){
        int randPos = (rand() % 410) + 10;
        setPos(650, randPos);

        QPixmap imageSecond (":/assets/enemy.png");
        setPixmap(imageSecond.scaled(100,100, Qt::KeepAspectRatio));
        setTransformOriginPoint(50,50);

        // make/connect a timer to move() the enemy every so often
        QTimer * timer = new QTimer(this);
        connect(timer,SIGNAL(timeout()),this,SLOT(move()));

        int randomSpeed = (rand() % 15) + 1;
        timer->start(10 + randomSpeed);
    }
}

/// calculating the enemies' moving speed.
/// every enemy's speed differs randomly
void Enemy::move(){
    // move enemy down
    int randSpeed = (rand() % 9) + 5;
    setPos(x()-randSpeed,y());

    // get a list of all the items currently colliding with this enemy
    QList<QGraphicsItem *> colliding_items = collidingItems();

    // if one of the colliding items is the Player, destroy the enemy
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if(!(game->isPotioned)){
            if (typeid(*(colliding_items[i])) == typeid(Player)){
                //decrease the health
                game->health->decrease();

                scene()->removeItem(this);
                delete this;
                return;
            }
        }
    }

    // if for destroying enemy when it goes out of the screen
    if (pos().x() + 80 < 0){
        // increase the score
        game->score->increase();
        scene()->removeItem(this);
        delete this;
    }
}
