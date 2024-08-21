#include "ghost.h"
#include <cstdlib>
#include <ctime>

void ghost::move(){
    if(check)
    {

    /*
    int moveNum = rand()%4;
    if(data[row][column]==-2){
        row=7;
        column=25;
        srand(time(NULL));
    }

    if(data[row][column]==-3){
        row=7;
        column=0;
        srand(time(NULL));
    }

    if (moveNum==0 && data[row - 1][column] != -1){
                row--;
                srand(time(NULL));

    }
    else if (moveNum==1 && data[row + 1][column] != -1){
                        row++;
                        srand(time(NULL));

           }

    else if (moveNum==2 && data[row][column + 1] != -1){
            column++;
            srand(time(NULL));

        }

    else if (moveNum==3 && data[row][column - 1] != -1){
                     column--;
                     srand(time(NULL));

    }


    setPos(50+50*column, 50+50*row);

   */

        Ghost_location = data[row][column];
        Player_location = data[Player_address->getRow()][Player_address->getColumn()];
        paths = dijkstra(graph, Player_location);
        if (data[row-1][column] == (paths[Ghost_location][1]))
            {
                row--;
            }
        else if (data[row+1][column] == (paths[Ghost_location][1]))

            {
                row++;
            }
        else if (data[row][column+1] == (paths[Ghost_location][1]))
            {
                column++;
                    if (data[row][column+1] == -3)
                    column = 1;
            }
        else if (data[row][column-1] == (paths[Ghost_location][1]))
            {
                column--;
                    if (data[row][column-1] == -2)
                    column = 24;
            }
        setPos(50+50*column, 50+50*row);

   // QTimer::singleShot(240, this, SLOT(move()));

    }
}



int ghost::getInitialRow(){
    return initial_row;
}
int ghost::getInitialColumn(){
    return initual_column;
}
int ghost::getId(){
    return id;
}

void ghost::setCheck(bool x){
    check=x;
}

bool ghost::getCheck(){
    return check;
}

ghost::ghost(int Graph[146][146])
{
    for(int i=0; i<146 ; i++)
        for(int j=0; j<146; j++)
            graph[i][j] = Graph[i][j];
    timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(240);
}

void ghost::removeFear(){
    if(id == 1){
        ghostImage.load("D:/QT/pacman1/Assets/Ghosts/Ghost1/normal/ghost1 - front.png");
        ghostImage = ghostImage.scaledToWidth(50);
        ghostImage = ghostImage.scaledToHeight(50);
        setPixmap(ghostImage);
    }
    if(id == 2){
        ghostImage.load("D:/QT/pacman1/Assets/Ghosts/Ghost2/normal/ghost2 - front.png");
        ghostImage = ghostImage.scaledToWidth(50);
        ghostImage = ghostImage.scaledToHeight(50);
        setPixmap(ghostImage);
    }
    if(id == 3){
        ghostImage.load("D:/QT/pacman1/Assets/Ghosts/Ghost3/normal/ghost3 - front.png");
        ghostImage = ghostImage.scaledToWidth(50);
        ghostImage = ghostImage.scaledToHeight(50);
        setPixmap(ghostImage);
    }
    if(id == 4){
        ghostImage.load("D:/QT/pacman1/Assets/Ghosts/Ghost4/normal/ghost4 - front.png");
        ghostImage = ghostImage.scaledToWidth(50);
        ghostImage = ghostImage.scaledToHeight(50);
        setPixmap(ghostImage);
    }
            setCheck(true);
}
void ghost::fear(){
    if(id == 1){
        ghostImage.load("D:/QT/pacman1/Assets/Ghosts/feared.png");
        ghostImage = ghostImage.scaledToWidth(50);
        ghostImage = ghostImage.scaledToHeight(50);
        setPixmap(ghostImage);
    }
    if(id == 2){
        ghostImage.load("D:/QT/pacman1/Assets/Ghosts/feared.png");
        ghostImage = ghostImage.scaledToWidth(50);
        ghostImage = ghostImage.scaledToHeight(50);
        setPixmap(ghostImage);
    }
    if(id == 3){
        ghostImage.load("D:/QT/pacman1/Assets/Ghosts/feared.png");
        ghostImage = ghostImage.scaledToWidth(50);
        ghostImage = ghostImage.scaledToHeight(50);
        setPixmap(ghostImage);
    }
    if(id == 4){
        ghostImage.load("D:/QT/pacman1/Assets/Ghosts/feared.png");
        ghostImage = ghostImage.scaledToWidth(50);
        ghostImage = ghostImage.scaledToHeight(50);
        setPixmap(ghostImage);
    }
}
void ghost::createGhost(int row, int column, int type, int data[][26]){
    if(type == 1){
        ghostImage.load("D:/QT/pacman1/Assets/Ghosts/Ghost1/normal/ghost1 - front.png");
        ghostImage = ghostImage.scaledToWidth(50);
        ghostImage = ghostImage.scaledToHeight(50);
        setPixmap(ghostImage);
        this->row = row;
        this->column = column;
        initial_row = row;
        initual_column = column;
        id = type;
        srand(time(NULL));
            for(int i = 0; i < 16; i++)
                for(int j = 0; j < 26; j++)
                    this->data[i][j] = data[i][j];
        setPos(50 + 50 * column, 50 + 50 * row );
        move();
    }
    else if(type == 2){
        ghostImage.load("D:/QT/pacman1/Assets/Ghosts/Ghost2/normal/ghost2 - front.png");
        ghostImage = ghostImage.scaledToWidth(50);
        ghostImage = ghostImage.scaledToHeight(50);
        setPixmap(ghostImage);
        this->row = row;
        this->column = column;
        initial_row = row;
        initual_column = column;
        id = type;
        srand(time(NULL));
        for(int i = 0; i < 16; i++)
            for(int j = 0; j < 26; j++)
                this->data[i][j] = data[i][j];
        setPos(50 + 50 * column, 50 + 50 * row );
        move();
    }
    else if(type == 3){
        ghostImage.load("D:/QT/pacman1/Assets/Ghosts/Ghost3/normal/ghost3 - front.png");
        ghostImage = ghostImage.scaledToWidth(50);
        ghostImage = ghostImage.scaledToHeight(50);
        setPixmap(ghostImage);
        this->row = row;
        this->column = column;
        initial_row = row;
        initual_column = column;
        id = type;
        srand(time(NULL));
        for(int i = 0; i < 16; i++)
            for(int j = 0; j < 26; j++)
                this->data[i][j] = data[i][j];
        setPos(50 + 50 * column, 50 + 50 * row );
        move();
    }
    else if(type == 4){
        ghostImage.load("D:/QT/pacman1/Assets/Ghosts/Ghost4/normal/ghost4 - front.png");
        ghostImage = ghostImage.scaledToWidth(50);
        ghostImage = ghostImage.scaledToHeight(50);
        setPixmap(ghostImage);
        this->row = row;
        this->column = column;
        initial_row = row;
        initual_column = column;
        id = type;
        srand(time(NULL));
        for(int i = 0; i < 16; i++)
            for(int j = 0; j < 26; j++)
                this->data[i][j] = data[i][j];
        setPos(50 + 50 * column, 50 + 50 * row );
        move();
    }
}

std::vector<std::vector<int>> ghost::dijkstra(int graph[][146], int startNode)
{
    int temp[146][146], costs[146], previous[146];
        for (int i = 0; i < 146; i++)
            for (int j = 0; j < 146; j++)
            {
                temp[i][j] = graph[i][j];
            }
        bool visited[146];
        // costs, previous, and visited
        for (int i = 0; i < 146; i++)
        {
            costs[i] = temp[startNode][i];
            previous[i] = startNode;
            visited[i] = false;
        }
        // startNode
        costs[startNode] = 0;
        visited[startNode] = true;

        int count = 1, nextNode, minimumCost;
        while (count < 146)
        {
            // Find the minimum cost in order to visit a node.
            minimumCost = inf;
            for (int i = 0; i < 146; i++)
                if ((costs[i] < minimumCost) && (visited[i] == false))
                {
                    minimumCost = costs[i];
                    nextNode = i;
                }
            // Visit the node.
            visited[nextNode] = true;
            // Update the costs of the children of the visited node.
            for (int i = 0; i < 146; i++)
                if ((minimumCost + temp[nextNode][i] < costs[i]) && (visited[i] == false))
                {
                    costs[i] = minimumCost + temp[nextNode][i];
                    previous[i] = nextNode;
                }
            count++;
        }
        // Fill the paths.
        int j;
        std::vector<std::vector<int>> paths;
        paths.resize(146);
        for (int i = 0; i < 146; i++)
        {
            paths[i].push_back(std::move(i));
            if (i != startNode)
            {
                j = i;
                do
                {
                    j = previous[j];
                    paths[i].push_back(std::move(j));
                } while (j != startNode);
            }
        }
        return paths;
}
void ghost::connection(player* address)
{
 Player_address = address;
}

