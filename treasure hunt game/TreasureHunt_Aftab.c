#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int size, i, j, count = 0, treasures, x = 1, y = 1, a, b;
char ch, cont;
time_t start_t, end_t;
double diff_t, tLimit;

void render(int size, char map[][size])	// function for printing out the map
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
	do{ //loops until a correct amount of treasures is entered
		printf("Enter the number of treasures to be buried: ");
		scanf("%d", &treasures);
		if(treasures > (int)pow(size-2,2) ){ 
			//error message if there are more treasures then the map can contain
			printf("Too treasures. Don't be greedy oii!!\n"); 
		}
		if(treasures < 0){
			//error message for -ve amount
			printf("Cmon...there cannot be -ve treasures -_-\n");
		}
	}while(treasures > (int)pow(size-2,2) || treasures < 0);
	
	tLimit = treasures + 5;
	
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
		if(treasureMap[b][a] == '@' || treasureMap[b][a] == 'X'){ //checking whether a treasure is already at the generated location
																  //or if it is the player's starting point
			continue;
		}
		else{
			treasureMap[b][a] = '@'; //burying the treasure using randomized coordinates
			break;
		}
		}
	}

	printf("Press Any Key twice to start\n "); 
	cont = getch();

	system("cls");
	time(&start_t);	// stores current pc time
	while(1)
	{
		//series of if statements for the movement of the player
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
		system("cls");
		printf("Number of treasures collected: %d\n", count);
		printf("Time Limit: %.1fs\n", tLimit);
		printf("Use arrow keys to move. :)\n");
		render(size, treasureMap); //displays the current map
		if(count==treasures) 
		{
			break; //exits the loop if the players found all the treasures
		}
	}
	time(&end_t); //stores current pc time
	diff_t = difftime(end_t, start_t); //calculates the amount of time played
	if (diff_t <= tLimit){ //checking if the player finished within the time limit 
		printf("You Won!!\n"); // prompts the player he won
	}
	else{
		printf("You Lose. You took too much time!!\n"); // prompts the player he won
	}
	printf("\nExecution time = %.1fs\n", diff_t); //shows the player how much time he took

	return 0;
}