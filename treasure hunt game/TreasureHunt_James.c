#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

void init(int size, char ch[][size]);
void draw(int size, char ch[][size]);
int checkCollision(int orientation, int spacing, int size, char ch[][size]);
void movement(int size, char ch[][size]);

int noOfTreasure = 0,size,collected = 0, x=2,y=2;
char key;

 
int main()
{  
    system("CLS");
    printf("Enter the size of the wall: "); 
    scanf("%d", &size);

    char ch[size][size];
    while(noOfTreasure == 0)
    {
        printf("Enter number of treasure: ");
        scanf("%d", &noOfTreasure);
        if(noOfTreasure >= ((size*size) - (((size-1) * 4) -1) ) || noOfTreasure < 1)
        {   
            printf("Number of Treasure is either too high or less than 1.\n");
            noOfTreasure = 0;
        }
    }
    
    init(size, ch);
    system("CLS");
    draw(size,ch);

    time_t start_t, end_t;
    double diff_t;
    time(&start_t);
    while(collected != noOfTreasure)
    {
        if(_kbhit())
        {
            key=_getch();
            movement(size,ch);
            system("CLS");
            draw(size,ch);
        }
    }
    time(&end_t);
    diff_t = difftime(end_t, start_t);
    printf("Time Taken: %.1fs\n", diff_t);
    if(diff_t < 15.0)
        printf("YOU WIN!\n");
    else
        printf("YOU WASTED TOO MUCH TIME!.... LOSER!\n");
    return 0;
}

void init(int size, char ch[][size])
{
    for(int y = 0; y < size; y++)
    {
        for(int x = 0; x < size; x++)
        {
            ch[y][x] = '.';
        }
    }

    for(int y = 0; y < size; y++)
    {
        ch[0][y] = '#';
        ch[size-1][y] = '#';
        ch[y][0] = '#';
        ch[y][size-1] = '#';
    }

    ch[y][x] = 'X';

    int current = 0, counter = 0, coord;
    srand(time(NULL));
    while(current < noOfTreasure)
    {
        counter = 0;
        coord = (rand() % ((size*size) - (((size - 1) * 4) - 1)));
        printf("%d\n", coord);
        for(int y = 1; y < size - 1; y++)
        {
            for(int x = 1; x < size - 1; x++)
            {
                if(counter == coord)
                {
                    if(ch[y][x] != 'X' && ch[y][x] != '@')
                    {
                        ch[y][x] = '@';
                        current++;
                    }   
                }
                counter++;
            }
        }
    }
}

void draw(int size, char ch[][size])
{
    for(int y = 0; y < size; y++)
    {
        for(int x = 0; x < size; x++)
        {
            printf("%c ", ch[y][x]);
        }
        printf("\n");
    }
    printf("Number of Treasure Collected: %d\n", collected);
}

void movement(int size, char ch[][size])
{
    if(key==72)    
    {                     
        if(checkCollision(1, -1, size, ch) == 0){
            ch[y][x] = '.';
            --y;                        
            ch[y][x] = 'X';   
        }                
    }
    else if(key==80)
    {
        if(checkCollision(1, 1, size, ch) == 0){
            ch[y][x] = '.';
            ++y;
            ch[y][x] = 'X';
        }
    }
    else if(key==77)
    {
        if(checkCollision(2, 1, size, ch) == 0){
            ch[y][x] = '.';
            ++x;
            ch[y][x] = 'X';
        }
    }
    else if(key==75)
    {
        if(checkCollision(2, -1, size, ch) == 0){
            ch[y][x] = '.';
            --x;
            ch[y][x] = 'X';
        }
    }
}

int checkCollision(int orientation, int spacing, int size, char ch[][size])
{
    if(orientation == 1)
    {
        if(ch[y+spacing][x] == '#')
            return 1;
        else if(ch[y+spacing][x] == '@')
        {   
            collected++;
            return 0;
        }
        else
            return 0;
    }
    else if (orientation == 2)
    {
        if(ch[y][x+spacing] == '#')
            return 1;
        else if(ch[y][x+spacing] == '@')
        {
            collected++;
            return 0;
        }
        else
            return 0;
    }
}