#include "score.h"

/// constructor of the score class.
/// defining the base factors of the score object
Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // initialize the score to 0
    score = 0;

    // draw the text
    setPlainText(QString("Score: ") + QString::number(score)); // Score: 0
    setDefaultTextColor(Qt::white);
    setFont(QFont("Algerian", 16, QFont::Bold));
}

/// increasing and updating the value of score.
void Score::increase(){
    //increasing the score and updating the score on text
    score++;
    setPlainText(QString("Score: ") + QString::number(score)); // Score: 1
}

/// decreasing and updating the value of health.
int Score::getScore(){
    return score;
}

/// resetting the value of health to the initial value when game is restarted.
void Score::resetScore(){
    //reseting the score for restarting the game
    score = 0;
    setPlainText(QString("Score: ") + QString::number(score));
}
