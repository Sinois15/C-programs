#include <stdio.h>

int main(){
    int x, num[50], lowest = 100000, highest = 0;
    for(int i = 0; i<50; i++){
        printf("Enter a number(-1 to end): ");
        scanf("%d", &x);
        num[i] = x;
        if(x == -1){
            break;
        }
        else if(x<lowest){
            lowest = x;
        }
        else if(x>highest){
            highest = x;
        }
    }
    printf("Highest number = %d\n", highest);
    printf("lowest number = %d\n", lowest);
    return 0;
}