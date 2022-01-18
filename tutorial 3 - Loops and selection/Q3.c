#include <stdio.h>

int main(){
    int x, fac = 1;

    printf("Please enter an integer: ");
    scanf("%d", &x);
    for(int i = 1; i<=x ; i++){
        fac = fac * i;
        printf("The factorial of %d is %d\n",i,fac);

    }
    return 0;

}