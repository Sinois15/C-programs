#include <stdio.h>      //to import input/output functions
#include <stdlib.h>     //to use rand() and srand(int i) functions
#include <time.h>       //to use time(int i) function
#include <conio.h>		//to use getch() function
#include <ctype.h>		//to use tolower(char c) function

char SnakeMap[20][30];                          // 2d array to represent the map
int r, c;                                      // row and column number for SnakeMap
int f_row, f_col;                             // food r and c location in the map array                  
int length = 0;                              // snakes length
int s_row[20], s_col[30];                   // coordinate of snake, max length is 504
int res = 0;                               // 0:game going-on, 1: player won, 2: player lost by making snake run into itself
char s_ch;								  //stores direction input
int end = 0;	                         //0: game continues, 1: game ends
size_t i;                               // counter variable for loops
int food();                            // generates food at random location
void snake();                         // allows player to control snake
void displayBoard();				 // displays the current snakeMap

int main() 
{
	s_row[0] = 1; // initial snake's row
	s_col[0] = 1; // initial snake's column
	
	// initializing SnakeMap
	for (r = 0; r < 20; r++){
		for (c = 0; c < 30; c++){
			if (c == 0 || c == 29 || r == 0 || r == 19){
				SnakeMap[r][c] = '#'; // the border
			}

			else {
				SnakeMap[r][c] = '.'; // inside of bound
			}
		}
	}
	SnakeMap[s_row[0]][s_col[0]] = 'X'; // set snake's head
	food(); //generates the food's random coordinates
	SnakeMap[f_row][f_col] = '@'; // displaying the food in the map
	// end of initialization

	do{
		displayBoard();    // print the current SnakeMap
		snake();          //Moves the snake according to the user's input
		if (res == 1){ // 1 means that the max length was reached by snake
			puts("\n Congratulations!\n You Won!");
			break;
		}

		if (res == 2){           // res = 2 means snake hit itself
			puts("\nThe snake hit himself.\nGame over! :P");
			break;//exits the loop
		}
		//update snakeMap
		for (r = 0; r < 20; r++){
			for (c = 0; c < 30; c++){
				if (c == 0 || c == 29 || r == 0 || r == 19){
					SnakeMap[r][c] = '#';
				}
				else{
					SnakeMap[r][c] = '.'; //
				}
			}
		}
		SnakeMap[f_row][f_col] = '@'; // stores food in the map array
		for (i = 0; i <= length; i++){
			if (i == 0){
				SnakeMap[s_row[i]][s_col[i]] = 'X'; // print the snake head
			}
			else{
				SnakeMap[s_row[i]][s_col[i]] = 'x'; // print the snake's body parts
			}
		}
		system("cls"); //clear screen
	} while (end == 0);//terminates if the player enters "e"
	displayBoard();
	if(s_ch == 'e'){
		printf("Player exited the game.\n");
	}
	return 0;
}

void displayBoard(){
	printf("Use W,A,S,D keys to move.\n"); // prompting player how to move
	for (r = 0; r < 20; r++)           	// printing the SnakeMap
	{
		for (c = 0; c < 30; c++)
		{
			printf("%c ", SnakeMap[r][c]);
		}
		printf("\n");
	}
	printf("Snake's length is %d\n", length + 1); // shows the length of snake
}

void snake()   // for controlling the snake
{ 
	int t_row = s_row[0], t_col = s_col[0]; // the array location of head is stored in temporary variables
	int bound = 0;    // 0:not on the edge of map. 1:on edge of map
	int valid = 1;    // 0: movement is invalid or snake trying to go out of border
	do{
		s_ch = getch(); //inputs without the need of "enter" to be pressed
		s_ch = tolower(s_ch);//converts every input to lowercase
		switch(s_ch)                             
		{ 
			case 'w':                    // for moving UP
				if (s_row[0] == 1){         // at the top border 
					printf("You can't go up! 0_0'\n");
					bound = 1;
					valid = 0;
				}
				else{           // decrements to the previous row 
					--s_row[0];
					valid = 1;
				}
				break;
			case 'a':                  // for moving LEFT
				if (s_col[0] == 1){     //  at the leftmost end 
					printf("You can't go left! 0_0\n");
					bound = 1;
					valid = 0;
				}
				else{        // decrements to prev col
					--s_col[0];			
					valid = 1;
				}
				break;
			case 's':         // to move down
				if (s_row[0] == 18){// if at the bottom border
					printf("You can't go down! -__-\n");
					bound = 1;
					valid = 0;
				}
				else{
					++s_row[0];	//increments to next row
					valid = 1;
				}                        	
				break;

			case 'd':               // for moving RIGHT
				if (s_col[0] == 28){    //  at rightmost end
					printf("You can't go right! -__-\n");
					bound = 1;
					valid = 0;
				}
				else{        
					++s_col[0];   //increments to next col
					valid = 1;			
				}
				break;
			case 'e': // if player wants to exit game
				end = 1 ;
				printf("Game over!! You exited the game.\n");
				break;
			default: //any other key pressed
				printf("Invalid Key!!\n");
				valid = 0;
		}
	}while(valid == 0);
	

	if (SnakeMap[s_row[0]][s_col[0]] == 'x'){//snake head moves into body part
		res = 2;
	}

	if (s_row[0] == f_row && s_col[0] == f_col){// when food is eaten
		length++;
		food();
		if (length == 504) { // SnakeMap filled by snake
			res = 1;
		}
	}

	if (bound == 0){            // normal condition, when it doesn't hit the boundary
		if (length > 0){
			for (i = length; i > 0; i--){     // loop for changing the array location of the snake 
				if (i == 1){        // for the head, making it equal to temp locations
					s_row[i] = t_row;
					s_col[i] = t_col;
				}
				else{             // changes the array location of snake to the prev location
					s_row[i] = s_row[i - 1];
					s_col[i] = s_col[i - 1];
				}
			}
		}
	}

}

int food()      // generates food at random locations
{ 
	do{
		srand(time(0));
		f_row = (rand() % 19) + 1; //generate random row value
		f_col = (rand() % 29) + 1; //generate random col value
	}while(SnakeMap[f_row][f_col] != '.');

	return 0;
}

