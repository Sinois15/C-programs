#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ans;

int decision(int num){
    if (num > ans){
        printf("Too high\n");
        return 0;
    }
    else if(num < ans){
        printf("Too low\n");
        return 0;
    }
    else{
        printf("You guessed right!!!\n");
        return 1;
    }
}

int main(){
    int guess;
    srand(time(0));
    ans = rand() % (1000 -1 + 1) + 1;
    printf("I have a number between 1 and 1000.\nCan you guess my number?\n");
    do{
        printf("Enter your guess: ");
        scanf("%d", &guess);
    }while(decision(guess) == 0);
    return 0;

}