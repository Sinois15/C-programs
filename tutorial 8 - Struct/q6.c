#include <stdio.h>

struct restaurant{
    char name[15];
    char foodType[15];
    float avgCost;
}r[30];

void displayInfo(int i){
    printf("n%-15s n%-15s n%-15d", "Name", "Food Type", "Average cost per head");
    for(int x =0; x<i; x++){
        printf("n%-15s n%-15s n%-15.2f\n", r[x].name, r[x].foodType, r[x].avgCost);
    }
}

int main(){
    int x = -1, cont;
    do{
        x++;
        printf("Enter the restaurant's name: ");
        scanf("%s", &r[x].name);
        printf("Enter the restaurant's food type: ");
        scanf("%s", &r[x].foodType);
        printf("Enter the restaurant's average cost per head: ");
        scanf("%s", &r[x].avgCost);
        printf("Do you want to continue<-1: no, any other num: yes>: ");
        scanf("%d", &cont);
    }while(cont != -1);
    displayInfo(x);
    return 0;
}