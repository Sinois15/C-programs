#include <stdio.h>

void printRec(int side1, int side2){
    for (int i = 0; i<side1; i++){
        for (int j = 0; j<side2; j++){
            printf("*");
        }
        printf("\n");
    }
}

int main(){
    int h,w;
    printf("Enter the height of the rectangle: ");
    scanf("%d", &h);
    printf("Enter the width of the rectangle: ");
    scanf("%d", &w);
    printRec(h,w);
    return 0;
}