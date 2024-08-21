#ifndef FOOD_H
#define FOOD_H
#include <QGraphicsPixmapItem>
#include <QFile>
#include <QTextStream>
#include <QGraphicsScene>

class food:public QGraphicsPixmapItem
{
private:
    int row;
    int column;
    bool isSuper = false;
    QPixmap foodImage;
public:
    food();
    void setRow(int);
    void setColumn(int);
    void createFood(int, int);
    void makeSuper();
    bool getIsSuper();
};

#endif // FOOD_H
