#include <stdio.h>

int main(){
    int num, i = 1;
    FILE *fptr;
    fptr = fopen("mtable.txt", "w");
    printf("Enter a number: ");
    scanf("%d", &num);
    if (fptr == NULL){
        printf("Could not open file\n");
    }
    else{
        fprintf(fptr, "Multiplication table for %d\n", num);
        while(i != 13){
            fprintf(fptr, "%d x %2d = %3d\n",num, i, num*i);
            i++;
        }
    }
    fclose(fptr);
}