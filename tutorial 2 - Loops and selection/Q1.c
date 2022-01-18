#include <stdio.h>

int main(){
    float gSales, salary;
    do{
        printf("Enter sales in dollars(-1 to end): ");
        scanf("%f", &gSales);
        if (gSales > 0) {
            salary = 200 + (0.09 * gSales);
            printf("Salary is $%.2f\n", salary);
        }
        else{
            printf("pleas enter a positive value!\n");
        }
    }while (gSales != -1);
    printf("process ended :)\n");
    return 0;
}