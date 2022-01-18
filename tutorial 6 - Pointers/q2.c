#include <stdio.h>

int discount;

void calcDiscount(float *price){
    if (*price >= 0 && *price < 10){
        discount = 20;
        *price = *price * 0.8;
    }
    else {
        discount = 30;
        *price = *price * 0.7;
    }
}

int main(){
    float price;
    do{
        printf("Enter the orice of an item(enter -1 to end): $");
        scanf("%f", &price);
        if (price > 0){
            calcDiscount(&price);
            printf("You get a %d%% discount.\nNew Price: $%.1f\n", discount, price);
        }
    }while(price > 0);
    return 0;
}