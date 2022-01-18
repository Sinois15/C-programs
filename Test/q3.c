#include <stdio.h>

int main(){
    int size, invalid = 0;
    char tri[10];
    do{
        printf("Enter an integer: ");
        scanf("%d", &size);
        if (size < -1){
            printf("invalid input!\n");
            invalid = 1;
        }
        else{
            
            for (int x = 0; x< size; x++){
                tri[x] = ' ';
            }
            for(int i = size -1; i>=0; i--){
                tri[i] = '*';
                printf("%s\n", tri);
            }
            for (int j = 0; j < size; j++){
                tri[j] = ' ';
                printf("%s\n", tri);
            }
        }
     
    }while (size != -1 );
    return 0;

}
