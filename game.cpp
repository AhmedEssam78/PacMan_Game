#include "game.h"

game::game()
{
    //Read board data from text file
    QFile board("D:/QT/pacman1/Text File Data/board.txt");
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

            scene()->addItem(&boardImages[i][j]);
        }
    }


    /*//////////////////// Creating game objects ////////////////////////*/

    // Create the player obj
    player player1(boardData);
    scene()->addItem(&player1);
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
               scene()->addItem(&Allfood[k]);
               k++;
            }
             else if(boardData2[i][j] == 44){
                 Allfood[k].createFood(i,j);
                 Allfood[k].makeSuper();
                 scene()->addItem(&Allfood[k]);
                 k++;

             }
        }

    }

    //Creating super food



    // Create Score Object
    QGraphicsTextItem* score_label = scene()->addText(QString::number(player1.getScore()));
    score_label->setDefaultTextColor(QColor(Qt::white));
    score_label->setPos(100, 1);
    QFont serifFont("Times", 20, QFont::Bold);
    score_label->setFont(serifFont);
    player1.setScoreLabel(score_label);

    // Create Lives Object
    QGraphicsPixmapItem livesObj[3];
    QPixmap livesImage("D:/QT/pacman1/Assets/Sprite1/sprite_front.png");
    livesImage.scaledToWidth(50);
    livesImage.scaledToHeight(50);
//    for(int i = 0; i < player1.getLives(); i++){
//        livesObj[i].setPixmap(livesImage);
//        livesObj[i].setPos(400 + ((i + 1) * 20) , 1);
//        scene.addItem(&livesObj[i]);
//    }
    player1.setLivesObj();
    //player1.removeLive(livesObj, 0);
    //player1.createLives();

    // Create Ghosts

    ghost* AllGhosts = new ghost[4]; //Creating multiple food objects
    QFile ghost_folder("D:/QT/pacman1/Text File Data/ghosts.txt");//<--
    ghost_folder.open(QIODevice::ReadOnly);                       //^
    // Reading the food objects position on the map from a file ^^^^
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

               AllGhosts[l].createGhost(i,j, 1, boardData);
               scene()->addItem(&AllGhosts[l]);
               //AllGhosts[l].move();
               l++;
            }
             else if(boardData3[i][j] == 2){
                 AllGhosts[l].createGhost(i,j, 2, boardData);
                 scene()->addItem(&AllGhosts[l]);
                 //AllGhosts[l].move();
                 l++;
             }
             else if(boardData3[i][j] == 3){
                 AllGhosts[l].createGhost(i,j, 3, boardData);
                 scene()->addItem(&AllGhosts[l]);
                 //AllGhosts[l].move();
                 l++;
             }
             else if(boardData3[i][j] == 4){
                 AllGhosts[l].createGhost(i,j, 4, boardData);
                 scene()->addItem(&AllGhosts[l]);
                 //AllGhosts[l].move();
                 l++;
             }
        }

    }





//    for(int i = 0; i < 3; i++){
//        AllGhosts[i].move();
//    }

//    while(scene.isActive()){
//        for(int i = 0; i < 3; i++){
//            AllGhosts[i].pacman_row = player1.getRow();
//            AllGhosts[i].pacman_column = player1.getColumn();

//        }
//    }
}


