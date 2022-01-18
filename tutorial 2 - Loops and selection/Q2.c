#include <stdio.h>

int main(){
    float hRate, salary;
    int nHours;
    do{
        
            printf("enter the number of hours worked (-1to end): ");
            scanf("%d", &nHours);
        if (nHours > 0){
            printf("Enter hourly rate of the worker($00.00): ");
            scanf("%f", hRate);
            if (nHours < 40){
                salary = hRate * nHours;
                printf("the salary is $%.2f", salary);
            }
            else {
                salary = (hRate * nHours) + ((nHours - 40) * 1.5*hRate);
                printf("the salary is $%.2f", salary);
            }
        }
        else {
            printf("Please enter a positive value!\n");
        }

    }while (nHours != -1);
    printf("process ended\n");
    return 0;
}