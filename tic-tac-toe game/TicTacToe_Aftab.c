#include <stdio.h>
#include <stdlib.h>
#include<time.h>

 
char board[3][3]; // The tic tac toe board     
char check_game();
void start_board();
void get_pmove();
void get_cmove();
void board_disp();
void choose_Char();
 
char pSign; // Variable to store the player's chosen sign
 
int main()
{
    char ch;
    int turn = 0;
    printf("Tic Tac Toe\n");
    printf("You shall be playing against the CPU.\n");
    choose_Char();
    ch = ' ';
    start_board();
    do{
        turn++;
        board_disp();
        get_pmove();
        ch = check_game();                                                             
        if(ch!= ' '){
            break;
        }    
        if (turn < 5){
            get_cmove();
            ch = check_game();
        }                                                    
        
                                            
    } while(ch == ' ' && turn<5); // Loop will go on until there is a win or it is pass turn 5
    printf("\n");
    board_disp(); // display the final status of the board          
    printf("\n");               
    if(ch == pSign) // if the player's sign was returned by check_game(), player wins
         printf("You won!  ~(T-T)~  \n\n");
    else if (ch == 'O'){ // if O was returned by check_game(), CPU wins
        printf("You lose xD!!!!\n\n");
    }
    else if (turn >= 5){ // if the board has been filled without a winner, it is a tie
        printf("Its a tie -_-\n");
    }
                                 
    return 0;
}
 
/* Initialize the board. */
void start_board()
{
   int i, j;
   for(i=0; i<3; i++)
   { for(j=0; j<3; j++)
      board[i][j] = ' ';
   }
}
 
/* Get a player's move. */
void get_pmove()
{
   int x, y, done;
   do{
        printf("Enter X,Y coordinates for your move (ex: 1,3 (row 1, col 3)): ");
        scanf("%d,%d", &x, &y);
        x--; y--;
        if(x<0 || x>2 || y<0 || y>2 || board[x][y]!= ' '){ // checks if the input is greater than the array's bounds
                                                           // or if there already is something at that slot
            printf("Invalid move, try again.\n");
            done = 0;
        }
        else{ 
            board[x][y] = pSign;
            done = 1;
        }
            
   }while(done == 0);
   
}
 
/* Get a move from the computer. */
void get_cmove()
{  int i, j, done;
    srand(time(0)); // initializes the random seed
    do{
        //rndomizes the coordinates of the cpu's play
        i = rand() % 3;
        j = rand() % 3;
        if(board[i][j] == ' '){ // checks if there is nothing at the generated slot
            board[i][j] = 'O';
            done = 1;
        }
        else{ // if there is, sets done to zero to loop until a free slot is found
            done = 0;
        }
    }while(done == 0);
}


 
/* Function for choosing characters, can use switch for different characters like (*, ^, !, #) instead of "X"  */
 
void choose_Char()
{
        int choice;
        char chplay[] = {'*','^','!','#','X'};
        printf("What character you want to play as? \nEnter move number: (* -1, ^ -2, ! -3, # -4, X -5)\n");
        scanf("%d", &choice);
        //switch case to set the player's sign based on the number input
        switch(choice)
        {
                case 1: printf("The Character you're choosing is * \n");
                        pSign = chplay[0];
                        break;
                case 2: printf("The Character you're choosing is ^ \n");
                        pSign = chplay[1];
                        break;
                case 3: printf("The Character you're choosing is ! \n");
                        pSign = chplay[2];
                        break;
                case 4: printf("The Character you're choosing is # \n");
                        pSign = chplay[3];
                        break;
                case 5: printf("The Character you're choosing is X \n");
                        pSign = chplay[4];
                        break;
                default: printf("Move number invalid, try again :)\n");
                         choose_Char();
        }      
}
 
 
// Display the board on the screen. 
void board_disp()
{
  int t;
  for(t=0; t<3; t++)
  {
    printf(" %c | %c | %c ", board[t][0],board[t][1], board [t][2]);
    if(t!=2)
         printf("\n---|---|---\n");
  }
  printf("\n");
}
 
/* See if there is a winner. */
char check_game()
{
    int i;
    for(i=0; i<3; i++)//checks each row and compares each element in it to see if they are the same
    {
        if(board[i][0]==board[i][1] && board[i][0]== board[i][2])
        return board[i][0];//if all elements in a row are the same, that charactered is returned
    }
    for(i=0; i<3; i++) /* check coloumns */
    {
            if(board[0][i]==board[1][i] && board[0][i]== board[2][i])
        return board[0][i];
    }
    /* test diagonals */
    if(board[0][0]== board[1][1] && board[1][1]==board[2][2]) // left diagonal
        { return board[0][0]; }                                        
    if(board[0][2]==board[1][1] && board[1][1]==board[2][0])  // right diagonal
        { return board[0][2]; }
    return ' '; // returns blank if none of the conditions are fulfilled, meaning there is no win yet
}