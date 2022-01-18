#include <stdio.h>

int main(){
    int x;

    printf("please enter a number: ");
    scanf("%d", &x);
    if (x%2>0){
        printf("%d is odd\n",x);
    }
    else{
        printf("%d is even\n",x);
    }
    return 0;

}