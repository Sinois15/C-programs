#include <stdio.h>

int main(){
    int count = 0;
    char fruit[10];
    FILE *fptr;
    fptr = fopen("fruits.txt","r");
    if(fptr == NULL){
        printf("Could not open file\n");
    }
    else{
        while (!feof(fptr)){
            printf("%s\n", fruit);
            fscanf(fptr,"%s",fruit);
            
            count++;
        }
        printf("Number of fruits: %d\n", count);
        fclose(fptr);
    }
    return 0;
}