#include <stdio.h>

int main(){
    char fruit[10];
    FILE *fptr;
    fptr = fopen("fruits.txt","w");
    if (fptr==NULL){
        printf("File could not be opened");
    }
    else{
        while(!feof(stdin)){
            printf("Enter a fruit: ");
            scanf("%s", &fruit);
            if (!feof(stdin)){
               fprintf(fptr, "%s\n", fruit); 
            }
            
        }
        fclose(fptr);
    }

}