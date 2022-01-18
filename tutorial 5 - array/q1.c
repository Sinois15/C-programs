#include <stdio.h>
#include <stdlib.h>

int marks[10];

void enterMarks(){
    int mark, valid = 0;
    for (int i = 0; i<10; i++){
        system("cls");
        do{
            printf("Enter the mark of student %d: ", i+1);
            scanf("%d", &mark);
            if(mark<0 || mark>100){
                printf("Invalid mark!\n");
                valid = 0;
            }
            else{
                marks[i] = mark;
                valid = 1;
            }
        }while(valid == 0);
    }
}

void displayMarks(){
    printf("Student\tMarks\n");
    for (int i = 0; i<10; i++){
        printf("%d\t%d",i+1,marks[i]);
        printf("\n");
    }
}

int main(){
    enterMarks();
    displayMarks();
    return 0;
}