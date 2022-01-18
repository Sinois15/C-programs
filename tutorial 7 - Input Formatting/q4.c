#include <stdio.h>

int main(){
    int x;
    for (int i = 0; i<3; i++){
        printf("  is the integer entered\r"); //carriage return(brings cursor to the beginning of line)
        scanf("%d", &x);
    }
    return 0;
}