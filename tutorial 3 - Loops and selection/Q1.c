#include <stdio.h>

int main(){
    int total;

    for (int i = 7; i<100; i += 7){
        total += i;
    }
    printf("the total is %d\n", total);
    return 0;
}