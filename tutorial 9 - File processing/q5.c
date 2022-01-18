#include <stdio.h>
#include <string.h>

char *chooseNumber(int x){

}

int main(){
    int digit[7], num;
    FILE *fptr;
    fptr = fopen("TelWord.txt", "w");
    printf("Enter a 7 digit phone number(Do not use 0&1): ");
    scanf("%d", num);
    for (int i = 0; i<7; i++){
        digit[i] = num%10;
        num = num/10;
    }
}