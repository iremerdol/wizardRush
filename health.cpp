#include "health.h"
#include "game.h"
#include <QApplication>

extern Game *game;

/// constructor of the health class.
/// defining the base factors of the health object
Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // initialize the health to 3
    health = 3;

    // draw the text
    setPlainText(QString("Health: ") + QString::number(health)); // Health: 3
    setDefaultTextColor(Qt::red);
    setFont(QFont("Algerian", 16, QFont::Bold));
}

/// decreasing and updating the value of health.
void Health::decrease(){
    //decreasing the health and updating the saved health value on text
    health--;
    setPlainText(QString("Health: ") + QString::number(health)); // Health: 2

    // if health is 0 then the player must die. I temporarily made it to close the game but
    // this part is going to be pop-up the restart screen
    if(health == 0){
        game->gameOver();
    }
}

/// increasing and updating the value of health.
void Health::increase(){
    //increasing the health and updating the saved health value on text
    health++;
    setPlainText(QString("Health: ") + QString::number(health)); // Health: 2
}

/// getting the value of health as it returns.
int Health::getHealth(){
    return health;
}

/// resetting the value of health to the initial value when game is restarted.
void Health::resetHealth(){
    //this is for restarting the game
    health = 3;
    setPlainText(QString("Health: ") + QString::number(health));
}
