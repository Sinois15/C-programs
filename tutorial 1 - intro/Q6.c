#include <stdio.h>

int main(){
    float bmi, h, w;

    printf("Please enter your height (m): ");
    scanf("%f", &h);
    printf("Please enter your weight (kg): ");
    scanf("%f", &w);
    bmi = w/(h*h);
    printf("bmi is %f\n",bmi);
    if (bmi < 18.5){
        printf("underweight");
    }
    if (bmi > 18.5 && bmi < 24.9){
        printf("normal");
    }
    if (bmi > 25 && bmi < 29.9){
        printf("overweight");
    }
    if (bmi > 30){
        printf("obese");
    }
    return 0;
}