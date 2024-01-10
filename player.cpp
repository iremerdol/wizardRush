#include "player.h"
#include "enemy.h"
#include "potion.h"
#include "game.h"

extern Game *game;

/// constructor of the player class.
/// defining the base factors of the player object
Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    // set graphic
    isUp = false;
    isDown = false;
    isLeft = false;
    isRight = false;

    if((game->isPlayer1) == true){
        QPixmap imageOne (":/assets/wizardE.png");
        setPixmap(imageOne.scaled(120,120, Qt::KeepAspectRatio));

        timerOne = new QTimer(this);
        timerTwo = new QTimer(this);
        timerThree = new QTimer(this);

        connect(timerTwo,SIGNAL(timeout()),this,SLOT(fall()));
        timerTwo->start(17);
        timerTwo->stop();
        connect(timerOne,SIGNAL(timeout()),this,SLOT(jump()));
        timerOne->start(10);
        timerOne->stop();
        connect(timerThree,SIGNAL(timeout()),this,SLOT(instaFall()));
        timerThree->start(10);
        timerThree->stop();

    }else if((game->isPlayer2) == true){
        QPixmap imageOne (":/assets/flyingPotter.png");
        setPixmap(imageOne.scaled(120,120, Qt::KeepAspectRatio));

        timerUp = new QTimer(this);
        connect(timerUp, SIGNAL(timeout()),this,SLOT(up()));
        timerUp->start(10);
        timerUp->stop();

        timerDown = new QTimer(this);
        connect(timerDown, SIGNAL(timeout()),this,SLOT(down()));
        timerDown->start(10);
        timerDown->stop();

        timerRight = new QTimer(this);
        connect(timerRight, SIGNAL(timeout()),this,SLOT(right()));
        timerRight->start(10);
        timerRight->stop();

        timerLeft = new QTimer(this);
        connect(timerLeft, SIGNAL(timeout()),this,SLOT(left()));
        timerLeft->start(10);
        timerLeft->stop();

    }else if((game->isPlayer3) == true){
        QPixmap imageOne (":/assets/hermonie.png");
        setPixmap(imageOne.scaled(120,120, Qt::KeepAspectRatio));

        timerOne = new QTimer(this);
        timerTwo = new QTimer(this);
        timerThree = new QTimer(this);

        connect(timerTwo,SIGNAL(timeout()),this,SLOT(fall()));
        timerTwo->start(17);
        timerTwo->stop();
        connect(timerOne,SIGNAL(timeout()),this,SLOT(jump()));
        timerOne->start(10);
        timerOne->stop();
        connect(timerThree,SIGNAL(timeout()),this,SLOT(instaFall()));
        timerThree->start(10);
        timerThree->stop();
    }
}

/// make the player jump when pressed to up-arrow key.
void Player::jump(){
    //jumping for each player
    try{
        if((game->isPlayer1) == true){
            if(pos().y() >= 300){
                setPos(x(),y()-8);
            }else if(pos().y() < 300 && pos().y() >= 250){
                setPos(x(),y()-5);
            }else if(pos().y() < 250 && pos().y() >= 215){
                setPos(x(),y()-4);
            }else if(pos().y() < 215 && pos().y() >= 200){
                setPos(x(),y()-2);
            }
            else{
                timerOne->stop();
                QPixmap imageOne (":/assets/wizardE3.png");
                setPixmap(imageOne.scaled(120,120, Qt::KeepAspectRatio));
                timerTwo->start();
            }
        }
        else if((game->isPlayer3) == true){
            if(pos().y() >= 300){
                setPos(x(),y()-8);
            }else if(pos().y() < 300 && pos().y() >= 250){
                setPos(x(),y()-5);
            }else if(pos().y() < 250 && pos().y() >= 215){
                setPos(x(),y()-4);
            }else if(pos().y() < 215 && pos().y() >= 200){
                setPos(x(),y()-2);
            }
            else{
                timerOne->stop();
                timerTwo->start();
            }
        }
    }
    catch(const std::exception& e){
        qDebug() << "Exception caught in Player::jump(): " << e.what();
    }
    catch(...){
        qDebug() << "Unknown exception caught in Player::jump()";
    }
}

/// make the player fall with some falling animation.
void Player::fall(){
    //falling for each player
    try{
        if((game->isPlayer1) == true){
            if(pos().y() < 215){
                timerOne->stop();
                setPos(x(),y()+3);
            }else if(pos().y() >= 215 && pos().y() < 250){
                setPos(x(),y()+6);
            }else if(pos().y() >= 250 && pos().y() < 300){
                setPos(x(),y()+7);
            }else if(pos().y() >= 300 && pos().y() < 400){
                setPos(x(),y()+10);
            }
            else{
                QPixmap imageOne (":/assets/wizardE.png");
                setPixmap(imageOne.scaled(120,120, Qt::KeepAspectRatio));
                timerTwo->stop();
            }
        }
        else if((game->isPlayer3) == true){
            if(pos().y() < 215){
                timerOne->stop();
                setPos(x(),y()+3);
            }else if(pos().y() >= 215 && pos().y() < 250){
                setPos(x(),y()+6);
            }else if(pos().y() >= 250 && pos().y() < 300){
                setPos(x(),y()+7);
            }else if(pos().y() >= 300 && pos().y() < 400){
                setPos(x(),y()+10);
            }
            else{
                timerTwo->stop();
            }
        }
    }
    catch(const std::exception& e){
        qDebug() << "Exception caught in Player::jump(): " << e.what();
    }
    catch(...){
        qDebug() << "Unknown exception caught in Player::jump()";
    }
}

/// interrupt the falling process when pressed to down-arrow key.
void Player::instaFall(){
    //interupting the falling process for each player
    try{
        if((game->isPlayer1) == true){
            if(pos().y() < 400){
                timerOne->stop();
                setPos(x(),y()+12);
            }
            else{
                QPixmap imageOne (":/assets/wizardE.png");
                setPixmap(imageOne.scaled(120,120, Qt::KeepAspectRatio));
                timerTwo->stop();
                timerThree->stop();
            }
        }else if((game->isPlayer3) == true){
            if(pos().y() < 400){
                timerOne->stop();
                setPos(x(),y()+12);
            }
            else{
                timerTwo->stop();
                timerThree->stop();
            }
        }
    }
    catch (const std::exception& e){
        qDebug() << "Exception caught in Player::jump(): " << e.what();
    }
    catch (...){
        qDebug() << "Unknown exception caught in Player::jump()";
    }
}

/// initializing the key press event.
/// defining the differs of movements for all the arrow keys.
void Player::keyPressEvent(QKeyEvent *event){
    // move the player left and right
    if((game->isPlayer1) == true){
        if(event->key() == Qt::Key_Down){
            if(pos().y() + 210 < 600){
                QPixmap imageOne (":/assets/wizardE3.png");
                setPixmap(imageOne.scaled(120,120, Qt::KeepAspectRatio));
                timerThree->start();
            }
        }
        else if(event->key() == Qt::Key_Up){
            if (pos().y() > 0){
                QPixmap imageOne (":/assets/wizardE2.png");
                setPixmap(imageOne.scaled(120,120, Qt::KeepAspectRatio));
                timerOne->start();
            }
        }
    }
    if((game->isPlayer2) == true){
        if(event->key() == Qt::Key_Down){
            isDown = true;
                if(isDown){
                    timerDown->start();
                }
        }
        else if(event->key() == Qt::Key_Up){
                isUp = true;
                if(isUp){
                    timerUp->start();
                }
        }
        else if(event->key() == Qt::Key_Right){
            isRight = true;
            if(isRight){
                timerRight->start();
            }
        }
        else if(event->key() == Qt::Key_Left){
            isLeft = true;
            if(isLeft){
                timerLeft->start();
            }
        }
    }
    if((game->isPlayer3) == true){
        if (event->key() == Qt::Key_Down){
            if (pos().y() + 210 < 600){
                timerThree->start();
            }
        }
        else if (event->key() == Qt::Key_Up){
            if (pos().y() > 0){
                timerOne->start();
            }
        }
    }
}

/// initializing key release event.
/// when the pressed key among all the arrow keys has released
void Player::keyReleaseEvent(QKeyEvent *event){
    if(game->isPlayer2){
        if(event -> key() == Qt::Key_Down){
            timerDown->stop();
            isDown = false;
        }else if(event -> key() == Qt::Key_Up){
            timerUp->stop();
            isUp = false;
        }else if(event -> key() == Qt::Key_Right){
            timerRight->stop();
            isRight = false;
        }else if(event -> key() == Qt::Key_Left){
            timerLeft->stop();
            isLeft = false;
        }
    }
}

/// selecting from the three players.
void Player::changeChar(int i){
    switch (i){
        case 1:
            game->isPlayer1 = true;
            game->isPlayer2 = false;
            game->isPlayer3 = false;
        break;
        case 2:
            game->isPlayer1 = false;
            game->isPlayer2 = true;
            game->isPlayer3 = false;
            break;
        case 3:
            game->isPlayer1 = false;
            game->isPlayer2 = false;
            game->isPlayer3 = true;
            break;
        default:
            game->isPlayer1 = true;
            game->isPlayer2 = false;
            game->isPlayer3 = false;
            break;
    }
}

/// spawning the enemies.
void Player::spawn(){
    // create an enemy
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}

/// spawning the potions.
void Player::spawnP(){
    //create a potion spesificly for player3
    Potion * potion = new Potion();
    scene()->addItem(potion);
}

/// up movement for flying.
/// controlled by up-arrow key
void Player::up(){
    //spesific movements for player2
    if((game->isPlayer2) == true){
        if(pos().y() > 0){
            setPos(x(),y()-5);
        }
    }
}

/// down movement for flying.
/// controlled by down-arrow key
void Player::down(){
    //spesific movements for player2
    if((game->isPlayer2) == true){
        if(pos().y() < 495){
            setPos(x(),y()+5);
        }
    }
}

/// right movement for flying.
/// controlled by right-arrow key
void Player::right(){
    //spesific movements for player2
    if((game->isPlayer2) == true){
        if(pos().x() < 680){
            setPos(x()+5,y());
        }
    }
}

/// left movement for flying.
/// controlled by left-arrow key
void Player::left(){
    //spesific movements for player2
    if((game->isPlayer2) == true){
        if(pos().x() > 5){
            setPos(x()-5,y());
        }
    }
}


