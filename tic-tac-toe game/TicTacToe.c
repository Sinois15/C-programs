#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
char grid[9];
int result = -1, move, countO, countX, turn = 0;

void displayGrid(){
    printf("  %c | %c | %c\n", grid[0], grid[1], grid[2]);
    printf(" -- + - + -- \n");
    printf("  %c | %c | %c\n", grid[3], grid[4], grid[5]);
    printf(" -- + - + -- \n");
    printf("  %c | %c | %c\n", grid[6], grid[7], grid[8]);
}

void moveInfo(){
    printf("Below is shown each number input corresponding where you can play :)\n");
    printf("  %d | %d | %d\n", 1 , 2, 3);
    printf(" -- + - + -- \n");
    printf("  %d | %d | %d\n", 4, 5, 6);
    printf(" -- + - + -- \n");
    printf("  %d | %d | %d\n", 7, 8, 9);
}

void playerMove(){
    int valid;
    do{
        printf("Enter a move: ");
        scanf("%d", &move);
        if (grid[move-1] == ' ' && move<10 && move>0){
            grid[move-1] = 'O';  
            valid = 1;
        }
        else if (move<1 || move>9 ){
            printf("Invalid move (/_<')\n");
            valid = 0;
        }
        else if (grid[move-1] != ' '){
            valid = 0;
            printf("There is already an %c in that spot (/_<')\n", grid[move-1]);
        }
        
    }while(valid == 0);
}

int decide(int x, int y, int z){
    
    int block, done;
    printf("deciding...\n");
    do{
        
        srand(time(NULL)); //sets new seed
        block = rand() % 3;//generates random num from 0-2
        //block is assigned 1 of the 3 values passed as 
        //parameter based on random num generated
        if (block == 0){
            block = x;
        }
        else if(block == 1){
            block = y;
        }
        else if(block == 2){
            block = z;
        }
        //checking if any of slot numbers passed as parameter are free
        if (grid[x] != ' ' || grid[y] != ' ' || grid[z] != ' '){
            block = rand() % 9;//generates a random num between 0 and 8
                                //and assign it to block
        }
        //checking if the slot number generated is free
        if(grid[block] == ' '){
            done = 1;//slot is free
        }
        else{
            done = 0;//not free
        }
    }while(done == 0);
    
    
    return block;
}

//places the AI's symbol in the slot number passed as parameter
void place(int pos){ 
    grid[pos] = 'X';
    printf("CPU placed in slot %d\n", pos+1);
}

//decides what move will the AI make based on last player move
void cpuMove(){ 
    int block, done;
    // switch..case statement to decide AI move based on last player move
    switch(move){
        case 1: place(decide(1, 3, 4));break;
        case 2: place(decide(0, 2, 4));break;
        case 3: place(decide(1, 4, 5));break;
        case 4: place(decide(0, 4, 6));break;
        case 5://if middle, decide any surrounding free slot
            do{
                block = rand() % 10;
                if (grid[block] == ' '){
                    place(block);
                    done = 1;
                }
                else{
                    done = 0;
                }
            }while(done == 0);
            break;
        case 6: place(decide(2, 4, 8));break;
        case 7: place(decide(3, 4, 7));break;
        case 8: place(decide(4, 6, 8));break;
        case 9: place(decide(4, 5, 7));break;
    }
}

void checkSlot(int i){
    if (grid[i] == 'O'){
        countO++;
    }
    else if(grid[i] == 'X'){
        countX++;
    }
}

void checkWin(){
    if (countO == 3){
        result = 1;
    }
    else if (countX == 3){
        result = 0;
    }

    else{
        countO = 0;
        countX = 0;
    }
}

void check(){
    if (turn >= 3){
        //checking horizontally
        for (int i = 0; i<9 && result == -1; i++){
            checkSlot(i);
            //checks if player or cpu won after going through a line
            if (i%3 == 2){
                checkWin();
            }
        }
        //checking vertically if there was no win horizontally
        if (result == -1){
            for (int c = 0; c<3 && result == -1; c++){
                for (int r = c; r<=c+6; r+=3 ){
                checkSlot(r);
                    //checks if player or cpu won after going through a line
                    if (r >= 6){
                        checkWin();
                    }
                }
            }
        }
        //checking right diagonal if no vertical win
        if (result == -1){
            for (int i = 0; i<9; i+=4){
                checkSlot(i);
                if (i == 8){
                    checkWin();
                }
            }
        }
        //checking left diagonal if there is still no win
        if (result == -1){
            for (int i = 2; i<=6; i+=2){
                checkSlot(i);
                if (i == 6){
                    checkWin();
                }
            }
        }
    }
    
}


int main(){
    char start;
    system("cls");
    srand(time(0));
    for (int i = 0; i<9; i++){
        grid[i] = ' ';
    }
    moveInfo();
    printf("Press any key to start. Good luck (o^v^o)\n");
    start = getch();
    displayGrid();
    do{
        turn++;
        playerMove();
        displayGrid();
        check();
        if (turn != 5){
            if (result == 1){
                printf("CPU: WAITTTT!!! Lemme think...\n");
                Sleep(800);
                printf("CPU: Who am i kidding...I give up (T-T)\n");
                Sleep(500);
            }
            else{
                cpuMove();
                check();
                Sleep(500);
                displayGrid();
            }
        }
        printf("\n");
    }while(result == -1 && turn < 5);
    if (result == 1){
        printf("You win  \\(^v^)/!!!\n");
    }
    else if(result == 0){
        printf("CPU Wins (/_<')!!!\n");
    }
    else if (turn == 5){
        printf("Its a Tie (-_-)\n");
    }
    return 0;

}
