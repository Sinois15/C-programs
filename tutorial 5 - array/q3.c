#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int num[12];

void initArray(){
    srand(time(0));
    for (int i = 0; i<12; i++){
        num[i] = rand() % 1000;
    }
}

void displayArray(){
    printf("Numbers\n");
    for(int i = 0; i<10; i++){
        printf("%d\n", num[i]);
    }
}

int findMin(){
    int min = 100000;
    for (int i = 0; i<12; i++){
        if (num[i] < min){
            min = num[i];
        }
    }
    return min;
}

int main(){
    initArray();
    displayArray();
    printf("The smallest number is %d.", findMin());
    return 0;
}