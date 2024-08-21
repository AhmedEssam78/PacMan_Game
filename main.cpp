#include "mainwindow.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <QGraphicsPixmapItem>
#include "player.h"
#include "food.h"
#include "ghost.h"
//#include <QBrush>

int main(int argc, char *argv[])
{
    //Create the view and scene
    QApplication a(argc, argv);
    QGraphicsView view;
    view.setFixedSize(1400,900);
    view.setBackgroundBrush(QBrush(Qt::black));
    QGraphicsScene game;
    view.setScene(&game);
    view.show();

    //Read board data from text file
    QFile board("D:/QT/pacman1/Text File Data/board2.txt");
    board.open(QIODevice::ReadOnly);
    int boardData[16][26];
    QTextStream board_stream(&board);
    for(int i = 0; i < 16; i++){
        QString temp;
        for(int j = 0; j < 26; j++){
            board_stream >> temp;
            boardData[i][j] = temp.toInt();
        }
    }
    //draw the board graphics
    QPixmap bricksImage("D:/QT/pacman1/Assets/Terrain/bricks1.png");
    bricksImage = bricksImage.scaledToWidth(50);
    bricksImage = bricksImage.scaledToHeight(50);
    QPixmap waterImage("D:/QT/pacman1/Assets/Terrain/water2.png");
    waterImage = waterImage.scaledToWidth(50);
    waterImage = waterImage.scaledToHeight(50);
    QGraphicsPixmapItem boardImages[16][26];
    QString temp;
    for(int i = 0; i < 16; i++){

        for(int j = 0; j < 26; j++){
            if(boardData[i][j] == -1){
                boardImages[i][j].setPixmap(bricksImage);
            }
            else{
                boardImages[i][j].setPixmap(waterImage);
            }
            boardImages[i][j].setPos(50 * j + 50, 50 * i + 50);
            game.addItem(&boardImages[i][j]);
        }
    }


    /*//////////////////// Creating game objects ////////////////////////*/

    // Create the player obj
    player player1(boardData);
    game.addItem(&player1);
    player1.setFlag(QGraphicsPixmapItem::ItemIsFocusable);
    player1.setFocus();


    //Creating Food Objects

    food* Allfood = new food[150]; //Creating multiple food objects
    QFile food_folder("D:/QT/pacman1/Text File Data/food.txt");//<--
    food_folder.open(QIODevice::ReadOnly);                       //^
    // Reading the food objects position on the map from a file ^^^^
    int boardData2[16][26];
    QTextStream food_stream(&food_folder);
    for(int i = 0; i < 16; i++){
        QString temp;
        for(int j = 0; j < 26; j++){
            food_stream >> temp;
            boardData2[i][j] = temp.toInt();
        }

    }

    // Initializing the food
    int k = 0;
    for(int i = 0; i < 16; i++){
        for(int j = 0; j < 26; j++){
             if(boardData2[i][j] == 33){

               Allfood[k].createFood(i,j);
               game.addItem(&Allfood[k]);
               k++;
            }
             // Initializing the super food
             else if(boardData2[i][j] == 44){
                 Allfood[k].createFood(i,j);
                 Allfood[k].makeSuper();
                 game.addItem(&Allfood[k]);
                 k++;

             }
        }

    }

    // Create Score Object
    QGraphicsTextItem* score_label = game.addText("Score: " + QString::number(player1.getScore()));
    score_label->setDefaultTextColor(QColor(Qt::white));
    score_label->setPos(100, 1);
    QFont serifFont("Times", 22, QFont::Bold);
    score_label->setFont(serifFont);
    player1.setScoreLabel(score_label);


    // Create Window Object
    QGraphicsTextItem* window = game.addText("Welcome To PAC-MAN");
    window->setDefaultTextColor(QColor(Qt::yellow));
    window->setPos(550, 1);
    QFont welcomeFont("Calibri", 25, QFont::Bold);
    window->setFont(welcomeFont);
    player1.setWindow(window);

    // Create Lives Object
    QGraphicsPixmapItem livesObj[3];
    QPixmap livesImage("D:/QT/pacman1/Assets/Sprite1/sprite_right.png");
    livesImage.scaledToWidth(50);
    livesImage.scaledToHeight(50);
    player1.setLivesObj();

    const int COUNT = 146;
        int Graph[COUNT][COUNT];
        for (int i = 0; i < 146; i++)
            for (int j = 0 ; j < 146 ; j++)
                Graph[i][j]=inf;
        for (int i = 0; i < 16 - 1; i++)
            for (int j = 0; j < 26 - 1; j++)
            {
                if (boardData[i][j] > -1 ) //a node in the graph
                {
                    if (boardData[i][j + 1] > -1)
                    {
                        Graph[(boardData[i][j])][(boardData[i][j + 1])] = 1;
                        Graph[(boardData[i][j + 1])][(boardData[i][j])] = 1;
                    }

                    if (boardData[i + 1][j] > -1)
                    {
                        Graph[(boardData[i][j])][(boardData[i + 1][j])] = 1;
                        Graph[(boardData[i + 1][j])][(boardData[i][j])] = 1;
                    }
                }
            }
        Graph[56][69]=1;
        Graph[69][56]=1;

    // Create Ghosts
    ghost** AllGhosts = new ghost*[4]; //Creating multiple ghost objects
    for(int i = 0;i<4;i++)
        AllGhosts[i]=new ghost(Graph);
    QFile ghost_folder("D:/QT/pacman1/Text File Data/ghosts.txt");//<--
    ghost_folder.open(QIODevice::ReadOnly);                       //^
    // Reading the ghost objects position on the map from a file ^^^^
    int boardData3[16][26];
    QTextStream ghost_stream(&ghost_folder);
    for(int i = 0; i < 16; i++){
        QString temp;
        for(int j = 0; j < 26; j++){
            ghost_stream >> temp;
            boardData3[i][j] = temp.toInt();
        }

    }

    // Initializing the ghosts
    int l = 0;
    for(int i = 0; i < 16; i++){
        for(int j = 0; j < 26; j++){
             if(boardData3[i][j] == 1){

               AllGhosts[l]->createGhost(i,j, 1, boardData);
               game.addItem(AllGhosts[l]);
               l++;
            }
             else if(boardData3[i][j] == 2){
                 AllGhosts[l]->createGhost(i,j, 2, boardData);
                 game.addItem(AllGhosts[l]);
                 l++;
             }
             else if(boardData3[i][j] == 3){
                 AllGhosts[l]->createGhost(i,j, 3, boardData);
                 game.addItem(AllGhosts[l]);
                 l++;
             }
             else if(boardData3[i][j] == 4){
                 AllGhosts[l]->createGhost(i,j, 4, boardData);
                 game.addItem(AllGhosts[l]);
                 l++;
             }
        }

    }
    for (int i = 0; i < 4; i++)
    {
        AllGhosts[i] ->connection(&player1);
    }


    view.show();      //show the view (last step)

    return a.exec();
}

