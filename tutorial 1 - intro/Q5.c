#include <stdio.h>

int main(){
    char num[10] = "nnnnn";
    //to input a string without declaring a char array first:
    //scanf("%[^\n]%*c", s)
    printf("please enter a five digit number: ");
    scanf("%s", &num);
    for (int i = 0; i<5; i++){
        printf("%c   ", num[i]);
    }
    return 0;
}