#include <stdio.h>

int total = 0;

void collectionAmount(int age){
    if (age <= 12){
        total = total + 5;
    }
    else if(age >= 60){
        total = total + 10;
    }
    else if(age > 0){
        total = total + 20;
    }
}

int main(){
    int yob, age, invalid = 0;
    do{
        invalid = 0;
        printf("Enter the year of birth: ");
        scanf("%d", &yob);
        age = 2020 - yob;
        if (age < 0 || yob < -1 || age > 120){
           invalid = 1;
           printf("invalid year of birth.\n");
        }
        else{
            collectionAmount(age);
        }
    }while( yob != -1 );
    printf("the total amount collected is RM%d\n", total);
    return 0;
}