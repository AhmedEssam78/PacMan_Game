#ifndef PLAYER_H
#define PLAYER_H

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
class player: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    QPixmap playerImage, livesImage;
    QGraphicsTextItem* score_label;
    QGraphicsTextItem* window;
    QGraphicsPixmapItem livesObj[3];
    QTimer *timer;
    int windowNum;
    int row;
    char key;
    int FoodNum = 136;
    int column;
    int data[16][26];
    int score = 0;
    int lives = 3;
    bool checker=true;
    bool super = false;
public:
    player(int [][26]);
    void setRow(int);
    void setColumn(int);
    void setScoreLabel(QGraphicsTextItem*);
    void updateScore(QGraphicsTextItem*);
    void setWindow(QGraphicsTextItem*);
    void updateWindow(QGraphicsTextItem*);
    void setLivesObj();
    void removeLive(int);
    void makeSuper();
    bool isSuper();
    int getRow();
    int getColumn();
    int getScore();
    int getLives();

public slots:
    void keyPressEvent(QKeyEvent *event);
    void removeSuper();
};

#endif // PLAYER_H
