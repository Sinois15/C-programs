#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

int size, i, j, count = 0, treasures, x = 1, y = 1, a, b;
char ch;
time_t start_t, end_t;
double diff_t;

void render(int size, char map[size][size])	// function for printing out the map
{
	for(i=0; i<size; i++)
	{
		for(j=0; j<size; j++)
		{
			printf("%c ", map[i][j]);
		}

		printf("\n");
	}
}

int main()
{
	system("cls"); //clear the screen
	printf("Enter the rows for the map: ");	// Prompting to enter number of rows of map
	scanf("%d", &size);
	char treasureMap[size][size];	//creating 2D array to store the elements and make up the map per the entered size
	printf("Enter the number of treasures to be buried: ");
	scanf("%d", &treasures);
	
	//nested loop to format the map
	for(i=0; i<size; i++)
	{
		for(j=0; j<size; j++)
		{
			if (j == 0 || j == size-1 || i == 0 || i == size -1){ // condition for the border
				treasureMap[i][j] = '#';
			}
			else{
				treasureMap[i][j] = '.';
			}	
		}
	}

	treasureMap[y][x] = 'X'; //putting the player at the upper left corner

	srand(time(0));
	for(i=0; i<treasures; i++) //loop for how many treaures were buried
	{
		while(1){
		a = (rand() % (size-2))+1; //randomizing the x-coordinate
		b = (rand() % (size-2))+1; //randomzing the y-coordinate
		//printf("%d %d\n", a, b);
		if(treasureMap[b][a] == '@'){ //checking whether a treasure is already at the generated location
			continue;
		}
		else{
			treasureMap[b][a] = '@'; //burying the treasure using randomized coordinates
			break;
		}
		}
	}

	 printf("Press Any Key to start\n ");

	//system("cls");
	time(&start_t);	// stores current pc time
	while(1)
	{
		ch = getch();	// takes in the key pressed as input in the form of ASCII code
		if(ch==0 || ch==224)	// other ASCII codes
		{
			ch = getch();
		}

		if(ch==72)	// 72 is ASCII for UP Arrow
		{
			if(treasureMap[y-1][x]=='@')
			{
				count++; // if treasure found, increment counter
			}

			if(treasureMap[y-1][x]=='#')
			{
				continue; //ignores if the user tries to move beyond the border
			}

			treasureMap[y][x] = '.'; //sets the previous player position back to a dot
			y--;
			treasureMap[y][x] = 'X'; //puts the player in the new position
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
			y++;
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

		printf("Number of treasures collected: %d\n", count);
		system("cls");
		render(size, treasureMap);
		if(count==treasures) //exits the loop if the players found all the treasures
		{
			printf("You Won!!\n"); // prompts the player he won
			break;
		}
	}
	time(&end_t); //stores current pc time
	diff_t = difftime(end_t, start_t); //calculates the amount of time played
	printf("\nExecution time = %.1fs\n", diff_t);

	return 0;
}