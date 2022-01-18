#include <stdio.h>

struct complex{
    float real;
    float imaginary;
}x1, x2;

int main(){
    printf("Enter 2 complex number(a + bi):\nnum1: ");
    scanf("%f+%fi", &x1.real, &x1.imaginary);
    printf("num2: ");
    scanf("%f+%fi", &x2.real, &x2.imaginary);
    printf("Sum = %.2f + %.2fi", x1.real + x2.real, x1.imaginary + x2.imaginary);
    return 0;

}