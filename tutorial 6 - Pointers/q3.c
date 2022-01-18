#include <stdio.h>

double add(double x, double y);
double subtract(double x, double y);
double multiply(double x, double y);
double divide(double x, double y);

double (*calc[4])(double x, double y) = {add, subtract, multiply, divide};

int main(){
    int option;
    double x,y;
    printf("Select a calculation(1: +, 2: -, 3: *, 4: / ): ");
    scanf("%d", &option);
    printf("Enter 2 double number: ");
    scanf("%lf %lf", &x, &y);
    switch(option){
        case 1: (*calc[0])(x,y);break;
        case 2: (*calc[1])(x,y);break;
        case 3: (*calc[2])(x,y);break;
        case 4: (*calc[3])(x,y);break;
        default: printf("Invalid option");break;
    }

    return 0;
}

double add(double x, double y){
    double result;
    result = x + y;
    printf("%.1lf + %.1lf = %.1lf", x,y,result);
}
double subtract(double x, double y){
    double result;
    result = x - y;
    printf("%.1lf - %.1lf = %.1lf", x,y,result);
}
double multiply(double x, double y){
    double result;
    result = x * y;
    printf("%.1lf X %.1lf = %.1lf", x,y,result);
}
double divide(double x, double y){
    double result;
    result = x/y;
    printf("%.1lf/%.1lf = %.1lf", x,y,result);
}