#include <stdio.h>

int main(){
    int prodNo;
    float quan,total = 0;

    do{
        printf("enter the product number(-1 to stop): ");
        scanf("%d", &prodNo);
        if (prodNo != -1){
            printf("Enter the quantity: ");
            scanf("%f", &quan);
            switch(prodNo){
                case 1: 
                    total += quan*2.98;
                    break;
                case 2:
                    total += quan*4.50;
                    break;
                case 3:
                    total += quan*9.98;
                    break;
                case 4:
                    total += quan*4.49;
                    break;
                case 5: 
                    total += quan*6.87;
                    break;
            }
        }
    }while (prodNo != -1);
    printf("Total retail value: $%.2f", total);

    return 0;
}

