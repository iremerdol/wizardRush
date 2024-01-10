#include "button.h"

/// constructor of the button class.
/// defining the base factors of button object
Button::Button(QString name, QGraphicsItem *parent):QGraphicsRectItem(parent){
    //draw the rect
    setRect(0,0,150,50);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkRed);
    setBrush(brush);

    //draw Text
    text = new QGraphicsTextItem(name,this);
    int xPos = rect().width()/2 - text->boundingRect().width()/2;
    int yPos = rect().height()/2 - text->boundingRect().height()/2;
    setTransformOriginPoint(xPos,yPos);
    text->setPos(xPos,yPos);
    text->setDefaultTextColor(Qt::white);

    //Allow responding to hover
    setAcceptHoverEvents(true);
}

/// controlling if the button is clicked.
void Button::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(event)
        emit clicked();
}

/// controlling if the mouse is on the button and react to that event.
void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
    //change color
    if(event){
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(Qt::red);
        setBrush(brush);
    }
}

/// controlling if the mouse is not on the button anymore and react to that event.
void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    //change color
    if(event){
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(Qt::darkRed);
        setBrush(brush);
    }
}
