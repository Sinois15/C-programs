#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>


int x,tNum, size, tCount, pos = 0, pTime, tLimit; 
char *board;
char ans;
clock_t sTime;

//create the board
void initBoard(){
    printf("Enter the board size(e.g 2 = 2 by 2 ): ");
    scanf("%d", &x);
    size = x*x;
    board = calloc(size, sizeof(char));
    for (int i = 0; i<size; i++){
           *(board + i) = '.';
    }
}

//display the current board
void displayBoard(){
    for (int a = 0; a<x+2; a++){
        printf("#  ");
    }
    printf("\n");
    for (int i = 0; i<x; i++){
        printf("#  ");
        for (int j = 0; j<x; j++){
            printf("%c  ", *(board + (j + i*x)));
        }
        printf("#\n");
    }
    for (int b = 0; b<x+2; b++){
        printf("#  ");
    }
    printf("\n");
    printf("treasure count: %d\n", tCount);
}

//randomize the position of the treasure
int randomize(int n){
    int num;
    num = (rand() % n);
    return num;
}

//input the number of treasures and place them on the board
void buryTreasure(){
    int tPos, buried = 0;
    srand(time(0));
    do{
    printf("how many treasures do u want to bury?: ");
    scanf("%d", &tNum);
    if (tNum > size){
        printf("There is not enough space for that much treasure!!\nDon't be too greedy -_-\n");
    }
    }while (tNum > size);
    //setting the time limit
    tLimit = tNum + 10;
    
    for (int i = 0; i<tNum; i++){
        do{
            tPos = randomize(size);
            if (*(board + tPos) == '.'){
                *(board + tPos) = '@';
                buried = 1;
            }
            else if (*(board + tPos) == '@'){
                tPos = randomize(tNum);
                buried = 0;
            }
        }while(buried == 0);
    }
    printf("%d treaures buried\n", tNum);
    printf("TIME LIMIT : %ds\n", tLimit);
}

//prompting user if they wants to start
int start(){
    int ready = 0;
    char ans;
    printf("Do you want to start the game <y/n> ?: ");
    scanf(" %c", &ans);
    ans = tolower(ans);
    switch (ans){
        case 'y': ready = 1;*(board + 0) = 'X'; sTime = clock(); break;
        case 'n': ready = 0;break;
        default: printf("invalid answer!\n");ready = 0;
    }
    return ready;
}

//checking if a treasure is at the player's position
void checkTreasure(){
    if (*(board + pos) == '@'){
        tCount++;
    }
}

//to move the player
void move(){
    char move;
    int valid = 1;
    do{
        valid = 1;
        printf("Enter next move< A for Left, D for Right, W for up, S for Down>: ");
        move = getch();
        move = tolower(move);
        switch(move){
            case 'a': 
                if (pos%x == 0){
                    printf("Cannot go further right!\n");
                    valid = 0; 
                }
                else{
                    *(board + pos) = '.';
                    pos--;
                    checkTreasure();
                    *(board + pos) = 'X';
                }
                break;
            case 'd': 
                if (pos%x == x - 1){
                    printf("Cannot go further left!\n");
                    valid = 0;
                }
                else{
                    *(board + pos) = '.';
                    pos++;
                    checkTreasure();
                    *(board + pos) = 'X';
                }
                break;
            case 'w': 
                if (pos<x && pos>=0){
                    printf("Cannot go further up!\n");
                    valid = 0;
                }
                else{
                    *(board + pos) = '.';
                    pos = pos - x;
                    checkTreasure();
                    *(board + pos) = 'X';
                }
                break;
            case 's': 
                if (pos>=(size-x+1) && pos<size){
                    printf("Cannot go further down!\n");
                    valid = 0;
                }
                else{
                    *(board + pos) = '.';
                    pos = pos + x;
                    checkTreasure();
                    *(board + pos) = 'X';
                }
                break;
            default:
                printf("invalid move!\n");
                valid = 0;
        }
        
    }while (valid == 0);
}

//checking the play time
void checkTime(){
    //calculates the time difference and converts it to seconds
    pTime = (clock() - sTime)/CLOCKS_PER_SEC; 
}

//checking how much time is left
int timesUp(){
    int tRemain;
    tRemain = tLimit - pTime;
    return tRemain;
}


int main(){
    
    do{
        system("cls");
        initBoard();
        buryTreasure();
        displayBoard();
        checkTreasure();
    }while (start() != 1);
    displayBoard();
    do{
        system("cls");
        displayBoard();
        printf("Time left: %ds\n", (tLimit - pTime));
        move();
        checkTime();

    }while((tCount != tNum));
    system("cls");
    displayBoard();
    if (pTime < tLimit){
        printf("YOU WIN!!!\n");
        printf("Time taken: %ds\n", pTime);
    }
    else {
        printf("YOU LOSE!! TIME'S UP.\n");
        printf("Time taken: %ds\n", pTime);
    }
    
    return 0;
}