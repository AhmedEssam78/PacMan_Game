#ifndef GAME_H
#define GAME_H
#include "player.h"
#include "food.h"
#include "ghost.h"
#include "food.h"
#include "ghost.h"
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QKeyEvent>
#include <QList>
#include <QGraphicsScene>
#include <QTimer>
#include <QEventLoop>
#include <stdexcept>
class game:public QGraphicsPixmapItem
{
private:

public:
    game();
    //QGraphicsScene TheGame;
    //QGraphicsScene getScene();
};

#endif // GAME_H
