#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

int size, i, j, count = 0, treasures, x = 4, y = 4, a, b, arr[100][2];
char ch;
time_t start_t, end_t;
double diff_t;
COORD coord = { 0, 0 };	// global variable

char treasureMap[60][60];	// 2D array to store the elements
void gotoxy(int x, int y)
{
 coord.X = x;
 coord.Y = y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void render()	// function for printing out the characters inside the 2D array
{
 for(i=0; i<size; i++)
 {
  for(j=0; j<size; j++)
  {
   printf("%c ", treasureMap[i][j]);
  }

  printf("\n");
 }
}

int random()
{
  a = rand() % (size-2)+1;
  b = rand() % (size-2)+1;
  arr[i][0]=a;
  arr[i][1]=b;
  return 0;
}

int main()
{
 for(i=0; i<60; i++)	// Outermost Loop for size number of iterations
 {
  for(j=0; j<60; j++)	// Outermost Loop for size number of iterations
  {
   treasureMap[i][j] = '.';
  }
 }

 printf("Enter the rows for the map:\n");	// Size, the number of rows for the map
 scanf("%d", &size);
 printf("Enter the number of treasures to be buried:\n");
 scanf("%d", &treasures);
 printf("\n");

 for(i=0; i<size; i++)
 {
  treasureMap[i][0] = '#';	// 1st row elements become #
  treasureMap[i][size - 1] = '#';	// (size-1)th row elements become #
  if(i==0 || i==size-1)	// Loop for 1st and (size)th row
  {
   for(j=0; j<(size); j++)	// logic for printing #
   {
    treasureMap[i][j] = '#';
   }
  }
 }

 treasureMap[y][x] = 'X';

 srand(time(0));
 for(i=0; i<treasures; i++)
 {
  random();
  for(int j=0;j<i;j++)
  {
   if((arr[j][0]==a)&&(arr[j][1]==b))
   {
    random();
    break;
   }
  }
  if((a==x) &&(b==y))
  {
   random();
  }
  //printf("%d %d %d\n",i,arr[i][0],arr[i][1]);
  treasureMap[a][b] = '@';
 }
 printf("Press Any Key to start\n");

 time(&start_t);	// begins the timer
 
 while(1)
 {
  gotoxy(0,6);	// start position
  ch = getch();	// asks user input (key press)
  if(ch==0 || ch==224)	// other ASCII codes
  {
   ch = getch();
  }

  if(ch==72)	// 72 is ASCII for UP Arrow
  {
   if(treasureMap[y-1][x]=='@')
   {
    count++;
   }

   if(treasureMap[y-1][x]=='#')
   {
    continue;
   }

   treasureMap[y][x] = '.';
   y--;
   treasureMap[y][x] = 'X';
  }
  else if(ch==80)	// 80 is ASCII for DOWN Arrow
  {
   if(treasureMap[y+1][x]=='@')
   {
    count++;
   }

   if(treasureMap[y+1][x]=='#')
   {
    continue;
   }

   treasureMap[y][x] = '.';
   ++y;
   treasureMap[y][x] = 'X';
  }
  else if(ch==77)	// 77 is ASCII for RIGHT Arrow
  {
   if(treasureMap[y][x+1]=='@')
   {
    count++;
   }

   if(treasureMap[y][x+1]=='#')
   {
    continue;
   }

   treasureMap[y][x] = '.';
   x++;
   treasureMap[y][x] = 'X';
  }
  else if(ch==75)	// 75 is ASCII for LEFT Arrow
  {
   if(treasureMap[y][x-1]=='@')
   {
    count++;
   }

   if(treasureMap[y][x-1]=='#')
   {
    continue;
   }

   treasureMap[y][x] = '.';
   x--;
   treasureMap[y][x] = 'X';
  }

  printf("Number of treasures collected:%d\n", count);
  treasureMap[y][x] == 'X';
  render();
  if(count==treasures)
  {
   gotoxy(5,10+size);
   printf(" You Won!!\n");
   Sleep(200);
   break;
  }
 }

 time(&end_t);
 diff_t = difftime(end_t, start_t);
 printf("\nExecution time = %.1fs\n", diff_t);

 return 0;
}