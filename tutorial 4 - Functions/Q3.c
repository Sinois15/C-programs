#include <stdio.h>

void largest(){
    float num, largest = 0;
    for (int i = 0; i<4; i++){
        printf("Enter a float number: ");
        scanf("%f", &num);
        if (num > largest){
            largest = num;
        }
    }
    printf("The largest float is %.2f", largest);
}

int main(){
    largest();
    return 0;
}