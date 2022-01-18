#include <stdio.h>

int isEven(int num){
    int even;
    if (num%2 == 0){
        even = 1;
    }
    else {
        even = 0;
    }
    return even;
}

void massIsEven(){
    int num;
    for (int i = 0; i<5; i++){
        printf("Enter an integer: ");
        scanf("%d", &num);
        if (isEven(num) == 1){
            printf("%d is even.\n", num);
        }
        else {
            printf("%d is odd.\n", num);
        }
    }
}

int main(){
    massIsEven();
    return 0;
}