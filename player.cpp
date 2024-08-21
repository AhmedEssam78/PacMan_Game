#include "player.h"

player::player(int data[][26])
{
    QPixmap playerImage("D:/QT/pacman1/Assets/Sprite1/sprite_right.png");
    playerImage.load("D:/QT/pacman1/Assets/Sprite1/sprite_right.png");
    playerImage = playerImage.scaledToWidth(50);
    playerImage = playerImage.scaledToHeight(50);
    setPixmap(playerImage);
    row = 7;
    column = 1;
    score = 0;
    setPos(50 + 50 * column, 50 + 50 * row );

    for(int i = 0; i < 16; i++){
        for(int j = 0; j < 26; j++){
            this->data[i][j] = data[i][j];
        }
    }


}
void player::setRow(int row){
    this->row = row;
}
void player::setColumn(int column){
    this->column = column;
}
int player::getRow(){
    return row;
}
int player::getColumn(){
    return column;
}
int player::getScore(){
    return score;
}
int o=0;
void player::keyPressEvent(QKeyEvent *event){
    setFlag(QGraphicsPixmapItem::ItemIsFocusable);
    setFocus();
    QList<QGraphicsItem*> items = scene()->items();
    for(int i = 0; i < items.size(); i++){
        if(typeid (*items[i]) == typeid (ghost) && o==0){
            windowNum=2;
            player::updateWindow(window);
            ghost* ghost1 = dynamic_cast<ghost*>(items[i]);
            ghost1->setCheck(true);
            ghost1->move();
        }
    }
    o+=1;
    timer = new QTimer(this);
    QEventLoop loop;
    if(FoodNum<0){
        windowNum=5;
        player::updateWindow(window);
        lives=0;
        QList<QGraphicsItem*> items = scene()->items();
        for(int i = 0; i < items.size(); i++){
            if(typeid (*items[i]) == typeid (ghost)){
                ghost* ghost1 = dynamic_cast<ghost*>(items[i]);
                ghost1->setCheck(false);
            }}

    }
    if(lives>0)
    {

        if(event->key() == Qt::Key_Left && row == 7 && column == 0){
            row = 7, column = 26;

        }
        if(event->key() == Qt::Key_Right && row == 7  && column == 25){
            row = 7, column = -1;}
    if(event->key() == Qt::Key_Up && data[row - 1][column] != -1){
        row--;
        playerImage.load("D:/QT/pacman1/Assets/Sprite1/sprite_back.png");
        playerImage = playerImage.scaledToWidth(49);
        playerImage = playerImage.scaledToHeight(49);
        setPixmap(playerImage);
        key = 'U';

    }
    if(event->key() == Qt::Key_Down && data[row + 1][column] != -1){
        row++;
        playerImage.load("D:/QT/pacman1/Assets/Sprite1/sprite_front.png");
        playerImage = playerImage.scaledToWidth(49);
        playerImage = playerImage.scaledToHeight(49);
        setPixmap(playerImage);
        key='D';


    }
    if(event->key() == Qt::Key_Right && data[row][column + 1] != -1){
        column++;
        playerImage.load("D:/QT/pacman1/Assets/Sprite1/sprite_right.png");
        playerImage = playerImage.scaledToWidth(49);
        playerImage = playerImage.scaledToHeight(49);
        setPixmap(playerImage);
        key='R';


    }
    if(event->key() == Qt::Key_Left && data[row][column - 1] != -1){
        column--;
        playerImage.load("D:/QT/pacman1/Assets/Sprite1/sprite_left.png");
        playerImage = playerImage.scaledToWidth(49);
        playerImage = playerImage.scaledToHeight(49);
        setPixmap(playerImage);
        key='L';

    }

    if (event->key() != Qt::Key_Up && key == 'U')
    {
        if(data[row - 1][column] != -1)
        {
            row--;
            playerImage.load("D:/QT/pacman1/Assets/Sprite1/sprite_back.png");
            playerImage = playerImage.scaledToWidth(49);
            playerImage = playerImage.scaledToHeight(49);
            setPixmap(playerImage);
            key = 'U';
        }
    }
    if (event->key() != Qt::Key_Down && key == 'D')
    {
        if(data[row + 1][column] != -1)
        {
            row++;
            playerImage.load("D:/QT/pacman1/Assets/Sprite1/sprite_front.png");
            playerImage = playerImage.scaledToWidth(49);
            playerImage = playerImage.scaledToHeight(49);
            setPixmap(playerImage);
            key = 'D';
        }
    }

    if (event->key() != Qt::Key_Right && key == 'R')
    {
        if(data[row][column +1] != -1)
        {
            column++;
            playerImage.load("D:/QT/pacman1/Assets/Sprite1/sprite_right.png");
            playerImage = playerImage.scaledToWidth(49);
            playerImage = playerImage.scaledToHeight(49);
            setPixmap(playerImage);
            key = 'R';
        }
    }

    if (event->key() != Qt::Key_Left && key == 'L')
    {
        if(data[row][column-1] != -1)
        {
            column--;
            playerImage.load("D:/QT/pacman1/Assets/Sprite1/sprite_left.png");
            playerImage = playerImage.scaledToWidth(49);
            playerImage = playerImage.scaledToHeight(49);
            setPixmap(playerImage);
            key = 'L';
        }
    }



    }

    setPos(50+50*column, 50+50*row);




    //detecting collision

    QString score_text;
    items = collidingItems();


    for(int i = 0; i < items.size(); i++){
        if(typeid (*items[i]) == typeid (food)){
            FoodNum--;
            scene()->removeItem(items[i]);
            food* food1 = dynamic_cast<food*>(items[i]);
            if(food1->getIsSuper()){
                score += 70;
                makeSuper();
            }
            else
                score += 30;
            updateScore(score_label);

        }
        if(typeid (*items[i]) == typeid (ghost)){
            // Upon coliding with ghost
            ghost* ghost1 = dynamic_cast<ghost*>(items[i]);
            if(super){
                score += 300;
                scene()->removeItem(ghost1);
                ghost1->setCheck(false);
                ghost1->createGhost(ghost1->getInitialRow(), ghost1->getInitialColumn(), ghost1->getId(), data);
                scene()->addItem(ghost1);


            }
            else{
                removeLive(lives-1);
                lives--;
                if(lives <=0)
                {
                    scene()->removeItem(ghost1);
                    windowNum=3;
                    player::updateWindow(window);
                    QList<QGraphicsItem*> items = scene()->items();
                    for(int i = 0; i < items.size(); i++){
                        if(typeid (*items[i]) == typeid (ghost)){
                            ghost* ghost1 = dynamic_cast<ghost*>(items[i]);
                            ghost1->setCheck(false);
                        }}
                }

                else
                {
                    windowNum=4;
                    player::updateWindow(window);
                    o=0;
                    QList<QGraphicsItem*> items = scene()->items();
                    for(int i = 0; i < items.size(); i++){
                        if(typeid (*items[i]) == typeid (ghost)){
                            ghost* ghost1 = dynamic_cast<ghost*>(items[i]);
                            scene()->removeItem(ghost1);
                            ghost1->setCheck(false);
                            ghost1->createGhost(ghost1->getInitialRow(), ghost1->getInitialColumn(), ghost1->getId(), data);
                            scene()->addItem(ghost1);
                        }}
                    for(int i = 0; i < items.size(); i++){
                        if(typeid (*items[i]) == typeid (player)){
                            player* pacman = dynamic_cast<player*>(items[i]);
                            pacman->setRow(7);
                            pacman->setColumn(1);
                            QPixmap playerImage("D:/QT/pacman1/Assets/Sprite1/sprite_right.png");
                            playerImage.load("D:/QT/pacman1/Assets/Sprite1/sprite_right.png");
                            playerImage = playerImage.scaledToWidth(49);
                            playerImage = playerImage.scaledToHeight(49);
                            pacman->setPixmap(playerImage);
                            scene()->addItem(pacman);
                            setPos(50+50*column, 50+50*row);
                           }}
        loop.exec();
                }}

        }}

    try {
        connect(timer, SIGNAL(timeout()), &loop, SLOT(quit()));
        timer->start(170);
        loop.exec();
        delete timer;
        keyPressEvent(event);

    } catch (std::exception& e) {
        score_label->setPlainText(e.what());
        score_label->update();
    }
}

void player::makeSuper(){
    super = true;
    windowNum=1;
    player::updateWindow(window);
    QList<QGraphicsItem*> items = scene()->items();
    for(int i = 0; i < items.size(); i++){
        if(typeid (*items[i]) == typeid (ghost)){
            ghost* ghost1 = dynamic_cast<ghost*>(items[i]);
            ghost1->fear();
        }

    }
    QTimer::singleShot(6000, this, SLOT(removeSuper()));
}

void player::removeSuper(){
    if(lives>0)
    {
    windowNum=2;
    player::updateWindow(window);
    super = false;
    QList<QGraphicsItem*> items = scene()->items();
    for(int i = 0; i < items.size(); i++){
        if(typeid (*items[i]) == typeid (ghost)){
            ghost* ghost1 = dynamic_cast<ghost*>(items[i]);
            if(ghost1->getCheck()==false){
                ghost1->removeFear();
                ghost1->move();
            }
            else{
                ghost1->removeFear();
            }
        }

    }
    }
}

bool player::isSuper(){
    if(super)
        return true;
    else
        return false;
}

void player::updateScore(QGraphicsTextItem* score_label){
    score_label->setPlainText("Score: " + QString::number(score));
    score_label->update();
}
void player::setScoreLabel(QGraphicsTextItem* score_label){
    this->score_label = score_label;
}

void player::updateWindow(QGraphicsTextItem* window){
    if(windowNum==1){
    window->setDefaultTextColor(QColor(Qt::white));
    window->setPos(540, 1);
    QFont inFont("cambria", 26, QFont::Bold);
    window->setFont(inFont);
    window->setPlainText("The Invisible Time!");
    window->update();}

    if(windowNum==2){
        window->setPlainText("");
        window->update();}

    if(windowNum==3){
        window->setDefaultTextColor(Qt::yellow);
        window->setPlainText("Game Over !");
        QFont loseFont("Calibri", 28, QFont::Bold);
        window->setFont(loseFont);
        window->setPos(590, 1);
        window->update();}

    if(windowNum==4){
        window->setDefaultTextColor(Qt::yellow);
        window->setPlainText("Oops! Still have a chance.");
        QFont reFont("Calibri", 25, QFont::Bold);
        window->setFont(reFont);
        window->setPos(520, 1);
        window->update();}

    if(windowNum==5){
        window->setDefaultTextColor(Qt::yellow);
        window->setPlainText("Congratulations! You Won!");
        QFont winFont("Calibri", 25, QFont::Bold);
        window->setFont(winFont);
        window->setPos(510, 1);
        window->update();}

}


void player::setWindow(QGraphicsTextItem* window){
    this->window = window;
}

void player::removeLive(int index){
    scene()->removeItem(&livesObj[index]);
}
void player::setLivesObj(){
    livesImage.load("D:/QT/pacman1/Assets/Sprite1/sprite_right.png");
    livesImage = livesImage.scaledToWidth(50);
    livesImage = livesImage.scaledToHeight(50);
    for(int i = 0; i < lives; i++){
        livesObj[i].setPixmap(livesImage);
        livesObj[i].setPos(1120 + ((i + 1) * 50) , 1);
        scene()->addItem(&livesObj[i]);
    }
}
int player::getLives(){
    return lives;
}

