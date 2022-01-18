#include<stdio.h>
#include<conio.h>
#include <ctype.h>

char spot[9];
char coord[3];
int gameStat = 1;

void draw()
{
    int counter = 1;
    //system("CLS");
    printf("    A   B   C\n");
    printf("  + - + - + - +\n%d ", counter);
    counter++;
    for(int i = 0; i < 9; i++)
    {
        printf("| ");
        printf("%c ", spot[i]);
        if((i+1)%3 == 0)
        {
            printf("|\n");
            if(counter <= 3)
            {
                printf("  + - + - + - +\n%d ", counter);
                counter++;
            }
            else
            {
                printf("  + - + - + - +\n");
            }
            
        }
    }
}

int process(char letter, char num)
{
    switch(letter)
    {
        case('a'): 
            if(num == '1')
            {
                if(spot[0] != 'X'){
                    spot[0] = 'X';
                }
                else{
                    return 2;
                }
            }
            else if(num == '2')
            {
                if(spot[3] != 'X')
                    spot[3] = 'X';
                else 
                    return 2;
            }
            else
            {
                if(spot[6] != 'X')
                    spot[6] = 'X';
                else
                    return 2;
            }
            return 1;
            break;
        case('b'):
            if(num == '1')
                spot[1] = 'X';
            else if(num == '2')
                spot[4] = 'X';
            else if(num == '3')
                spot[7] = 'X';
            return 1;
        case('c'):
            if(num == '1')
                spot[2] = 'X';
            else if(num == '2')
                spot[5] = 'X';
            else if(num == '3')
                spot[8] = 'X';
            return 1;
        default: return 0;
    }    
}

int validate(char coord[3])
{
    char letter;
    char num;

    if((isalpha(coord[0]) && isdigit(coord[1])) || (isalpha(coord[1]) && isdigit(coord[0])))
    {
        if(isalpha(coord[0]))
        {
            letter = tolower(coord[0]);
            num = coord[1];
        }
        else
        {
            letter = tolower(coord[1]);
            num = coord[0];
        }
        if(process(letter, num) == 1)
            return 1;
        else if(process(letter, num) == 2)
            return 2;
        else
            return 0;
        
    }
    else
        return 0;
}

int main()

{
    for (int i = 0; i<9; i++){
        spot[i] = ' ';
    }   
    while(gameStat != -1)
    {
        draw();
        do{
            printf("Enter co-ordinate: ");
            scanf("%s", &coord);
            if(validate(coord) == 0)
                printf("Invalid co-ordinate.\n");
            else if(validate(coord) == 2)
                printf("Slot is not empty.\n");
        } while(validate(coord) == 0 || validate(coord) == 2);
    }
}