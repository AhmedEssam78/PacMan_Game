#ifndef GHOST_H
#define GHOST_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QKeyEvent>
#include <QEventLoop>
#include <QGraphicsScene>
#include <QVector>
#include "player.h"

const int inf = 999;
class player;
class ghost:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    QPixmap ghostImage;
    QTimer *timer;
    QEventLoop loop;
    QList<QGraphicsItem*> items1;
    int row;
    int column;
    int initial_row;
    int initual_column;
    int id;
    int Ghost_location;
    int Player_location;
    player* Player_address;
    bool check=false;
    int moveNum = 0;
    int data[16][26];
    int graph[146][146];
   // QVector<QVector<int>> path;
    std::vector<std::vector<int>> paths;

public:
    ghost(int graph[146][146]);
    int getInitialRow();
    int getInitialColumn();
    int getId();
    void setCheck(bool);
    bool getCheck();
    void fear();
 // void stop();
    void removeFear();
    void createGhost(int, int, int, int data[][26]);
    std::vector<std::vector<int>> dijkstra(int graph[][146], int startNode);
    void connection(player*);
public slots:
    void move();
};

#endif // GHOST_H
