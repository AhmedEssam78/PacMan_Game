#include "food.h"

food::food(){
    foodImage.load("D:/QT/pacman1/Assets/Items/rare candy.png");
    foodImage = foodImage.scaledToWidth(23);
    foodImage = foodImage.scaledToHeight(23);

}


void food::setRow(int row){
    this->row = row;
}
void food::setColumn(int column){
    this->column = column;
}
void food::createFood(int row, int column){
    foodImage.load("D:/QT/pacman1/Assets/Items/rare candy - dark green.png");
    foodImage = foodImage.scaledToWidth(23);
    foodImage = foodImage.scaledToHeight(23);
    setPixmap(foodImage);
    setOffset(13,13);
    this->row = row;
    this->column = column;
    setPos(50 + 50 * column, 50 + 50 * row );
}
void food::makeSuper(){
    foodImage.load("D:/QT/pacman1/Assets/Items/super rare candy - red.png");
    foodImage = foodImage.scaledToWidth(40);
    foodImage = foodImage.scaledToHeight(40);
    setOffset(6,6);
    setPixmap(foodImage);
    isSuper = true;
}
bool food::getIsSuper(){
    return isSuper;
}
