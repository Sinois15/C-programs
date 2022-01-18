#include <stdio.h>

int main(){
    int x,y;

    printf("please enter 1st numbers: ");
    scanf("%d", &x);
    printf("please enter 2nd numbers: ");
    scanf("%d", &y);

    printf("the sum is %d\n", x+y);
    printf("the difference is %d\n", abs(x-y));
    printf("the product is %d\n", x*y);
    printf("the quotient is %d\n", x/y);
    return 0;
}