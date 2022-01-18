#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int arr1[10], arr2[10], match[10], total = 0;

void initArrays(){
    srand(time(0));
    for (int i = 0; i<10; i++){
        arr1[i] = rand() % 20;
        arr2[i] = rand() % 20;
    }
}

void displayArrays(){
    printf("Array 1\tArray 2\n");
    for(int i = 0; i<10; i++){
        printf("%d\t%d\n", arr1[i], arr2[i]);
    }
}

void checkMatch(){
    printf("Matching numbers: ");
    for(int i = 0; i<10; i++){
        for (int j = 0; j<10; j++){
            if (arr1[i] == arr2[j]){
                printf("%d ", arr1[i]);
                break;
            }
        }
    }
}

int main(){
    initArrays();
    displayArrays();
    checkMatch();
    return 0;
}