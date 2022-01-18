#include <stdio.h>

int highest = 0;

void getHighest(int *num){
    if (*num > highest){
        highest = *num;
    }
}

int main(){
    int num;
    printf("Enter 1st number: ");
    scanf("%d", &num);
    getHighest(&num);
    printf("Enter 2nd number: ");
    scanf("%d", &num);
    getHighest(&num);
    printf("Enter 3rd number: ");
    scanf("%d", &num);
    getHighest(&num);
    printf("Highest: %d", highest);
    return 0;
}