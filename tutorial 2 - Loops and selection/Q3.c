#include <stdio.h>

int main(){
    int l = 0;
    printf("Please enter the length of one side of the square:");
    scanf("%d", &l);
    while (l > 20 || l < 1){
        printf("the length should be between 1 and 20!\n");
    }
 
        
        for (int i = 0; i < l; i++){
                for (int j = 0; j < l; j++){
                    printf("*");
                }
                printf("\n");
        }
    
    return 0;
}