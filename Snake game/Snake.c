#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#define size 15 
#define limit 7

char board[15][15];
char prev;
int goingOut = 1, ateBody, speed, score = 0;;
//int xpt[limit], ypt[limit], dirArr[limit], count = -1;

struct Part{
    int x;// x-coord
    int y;// y-coord
    char symbol;
    int curDir; // 1- up, 2- right, 3- down, 4- left
    int turnX;// turning point x-coord
    int turnY;// turning point y-coord
};

struct Snake{
    struct Part head;
    struct Part body[30];
    int length;
}snake;

void initSnake(){
    snake.length = 5;
    snake.head.symbol = 'S';
    snake.head.curDir = 2;
    //snake.body = malloc(snake.length * sizeof(char));
    for (int i = 0; i<snake.length; i++){
        snake.body[i].symbol = 'X';
        snake.body[i].curDir = 2;
    } 
    snake.head.curDir = 2;
    snake.body[0].curDir = 2;
}

void initBoard(){
    int x = 0;
    for (int i = 0; i<size; i++){
        for(int j = 0; j<size; j++){
            board[i][j] = '.';
        }
    }
    for (int i = 8; i>3; i--){
        
        board[7][i] = snake.body[x].symbol;
        snake.body[x].y = 7;
        snake.body[x].x = i;
        x++;
    }
    snake.head.y = 7;
    snake.head.x = 9;
    board[7][9] = snake.head.symbol;
}

void displayBoard(){
    for (int i = 0; i<(size+2); i++){
        printf("# ");
    }
    printf("\n");
    for (int i = 0; i<size; i++){
        printf("# ");
        for (int j = 0; j < size; j++){
            printf("%c ", board[i][j]);
        }
        printf("#\n");
    }
    for (int i = 0; i<(size+2); i++){
        printf("# ");
    }
    printf("\n\nScore: %d\n", score);

}

int withinLimit(){ //to check if the head is on the border
    int yes = 1;
    int dir = snake.head.curDir;
    int sx = snake.head.x;
    int sy = snake.head.y;
    if (sx<=0 &&  dir==4){
        yes = 0;
    }
    else if(sx>=14 && dir==2){
        yes = 0;
    }
    else if(sy>=14 && dir==3){
        yes = 0;
    }
    else if(sy<=0 && dir==1){
        yes = 0;
    }
    return yes;
}

void selfEaten(){ //to check if the snake bumped into itself
    if (board[snake.head.y][snake.head.x] == 'X'){
        ateBody = 1;
    }
    else{
        ateBody = 0;
    }
}

void spawnFood(){ //to generate the food
    srand(time(0));
    int x,y;
    do{
        x = rand() % 15;
        y = rand() % 15;
        if(board[y][x] == '.'){
            board[y][x] = '@';
        }
        /*if (board[y][x] == 'X' || board[y][x] == 'S'){
            continue;
        }
        else{
            board[y][x] = '@';
        }*/
    }while(board[y][x] != '@');
    printf("food coord: %d %d\n", x, y);
}

int tailCornerCheck(int x){ //to check if the last body part is on a corner when growing
    int yes = 0;
    int last = snake.length-1;
    int sx = snake.body[snake.length - 2].x;
    int sy = snake.body[snake.length - 2].y;
    if (x == 1){
        if (sx >= 14 && sy <=0){//upper right coner
            snake.body[last].x = sx;
            snake.body[last].y = sy + 1;
            yes = 1;
        }
        if (sx <= 0 && sy <=0){//upper left coner
            snake.body[last].x = sx + 1;
            snake.body[last].y = sy;
            yes = 1;
        }
        if (sx >= 14 && sy >= 14){//lower right coner
            snake.body[last].x = sx - 1;
            snake.body[last].y = sy;
            yes = 1;
        }
        if (sx <= 0 && sy >= 14){//lower left coner
            snake.body[last].x = sx;
            snake.body[last].y = sy - 1;
            yes = 1;
        }
    }
    
    return yes;
}

void grow(){ //to add another body part when food is eaten
    speed -= 20; //increases the game speed when food is eaten
    snake.length = snake.length + 1;
    //snake.body = realloc(snake.body, snake.length*sizeof(char));
    snake.body[snake.length-1].curDir = snake.body[snake.length - 2].curDir;
    snake.body[snake.length-1].symbol = 'X';
    int sx = snake.body[snake.length - 2].x;
    int sy = snake.body[snake.length - 2].y;
    switch(snake.body[snake.length - 2].curDir){
        case 1:
            if (tailCornerCheck(0) == 1){
                tailCornerCheck(1);
            }
            else if(sy >= 14){
                snake.body[snake.length-1].x = sx - 1;
                snake.body[snake.length-1].y = sy;
            }
            else{
                snake.body[snake.length-1].x = sx;
                snake.body[snake.length-1].y = sy + 1;
            }
            break;
        case 2:
            if (tailCornerCheck(0) == 1){
                tailCornerCheck(1);
            }
            else if(sx <= 0){
                snake.body[snake.length-1].x = sx;
                snake.body[snake.length-1].y = sy + 1;
            }
            else{
                snake.body[snake.length-1].x = sx - 1;
                snake.body[snake.length-1].y = sy;
            }
            break;
        case 3:
            if (tailCornerCheck(0) == 1){
                tailCornerCheck(1);
            }
            else if(sy <= 0){
                snake.body[snake.length-1].x = sx - 1;
                snake.body[snake.length-1].y = sy;
            }
            else{
                snake.body[snake.length-1].x = sx;
                snake.body[snake.length-1].y = sy - 1;
            }
            break;
        case 4:
            if (tailCornerCheck(0) == 1){
                tailCornerCheck(1);
            }
            else if(sx >= 14){
                snake.body[snake.length-1].x = sx;
                snake.body[snake.length-1].y = sy + 1;
            }
            else{
                snake.body[snake.length-1].x = sx + 1;
                snake.body[snake.length-1].y = sy;
            }
            break;

    }
}

void moveHead(int *head, int dir){//to update the position of the head
    *head = *head + dir;
    if (board[snake.head.y][snake.head.x] == '@'){
        grow();
        spawnFood();
        score += 100;
    }
    selfEaten();
    board[snake.head.y][snake.head.x] = snake.head.symbol;
}

void moveBody(){//to update position of body parts
    int tx, ty;
    board[snake.body[snake.length -1].y][snake.body[snake.length -1].x] = '.';
    for (int i = snake.length-1; i>0; i--){
        snake.body[i].x = snake.body[i-1].x;
        snake.body[i].y = snake.body[i-1].y;
        board[snake.body[i].y][snake.body[i].x] = snake.body[i].symbol;
    }
    snake.body[0].x = snake.head.x;
    snake.body[0].y = snake.head.y;
    board[snake.body[0].y][snake.body[0].x] = snake.body[0].symbol;
}

void changeHeadDir(){ //to change the direction of the head when an arrow key is pressed
    int dir = snake.head.curDir;
    int sx = snake.head.x;
    int sy = snake.head.y;
    char key = getch(); 
    switch(key){
        case 72:
            if (sy <= 0 &&  (dir==1 || dir==2 || dir==4) ){
                printf("YOU SHALL NOT GO UP!!!\n");
                goingOut = 1;
            }
            else{
                snake.head.curDir = 1;
                goingOut = 0;
            }
            break;
        case 77:
            if (sx >= 14 &&  (dir==2 || dir==1 || dir==3) ){
                printf("YOU SHALL NOT GO RIGHT!!!\n");
                goingOut = 1;
            }
            else{
                snake.head.curDir = 2;
                goingOut = 0;
            }
            break;
        case 80:
            if (sy >= 14 &&  (dir==3 || dir==2 || dir==4) ){
                printf("YOU SHALL NOT GO DOWN!!!\n");
                goingOut = 1;
            }
            else{
                snake.head.curDir = 3;
                goingOut = 0;
            }
            break;
        case 75:
            if (sx <= 0 &&  (dir==4 || dir==1 || dir==3) ){
                printf("YOU SHALL NOT GO LEFT!!!\n");
                goingOut = 1;
            }
            else{
                snake.head.curDir = 4;
                goingOut = 0;
            }
            break; 
        case 'p': 
            printf("Game Paused.\nPress an arrow key to continue.\n");
            key = getch();
            break;
    }
}

void crawl(){// method that handles the whole snake movement
    if (kbhit() || withinLimit() == 0){
        goingOut = 1;
        do{
            changeHeadDir();
        }while(goingOut == 1);
    
    }
    moveBody();
    //updates the other body parts turn pts and direction
    switch(snake.head.curDir){
        case 1: moveHead(&snake.head.y, -1);break;
        case 2: moveHead(&snake.head.x, 1);break;
        case 3: moveHead(&snake.head.y, 1);break;
        case 4: moveHead(&snake.head.x, -1);break;
    }
}

int main(){
    speed = 600;
    initSnake();
    initBoard();
    displayBoard();
    printf("Press any key to start\n");
    int start = getch();
    spawnFood();
    displayBoard();
    while(ateBody == 0){
        crawl();
        printf("\n");
        for(int i = 0; i<snake.length; i++){
            printf("%d ",snake.body[i].curDir);
        }
        printf("\n");
        Sleep(speed);
        system("CLS");
        displayBoard();
    }
    if (ateBody == 1){
        printf("Aiyaa you ate yourself. You lose :p\n");
    }
    return 0;
}