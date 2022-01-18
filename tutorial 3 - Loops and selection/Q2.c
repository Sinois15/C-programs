#include <stdio.h>

int main(){
    int x, y;

    do{
        printf("input a -ve valur to stop.\n");
        printf("enter an integer: ");
        scanf("%d", &x);
        printf("enter another integer: ");
        scanf("%d", y);
    }while(x > 0 && y > 0);
    puts("end");

    return 0;
}