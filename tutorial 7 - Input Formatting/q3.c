#include <stdio.h>

int main(){

    int fahrenheit = 0;
    float celsius;
    while (fahrenheit <= 212){
        celsius = 5.0/9.0 * (fahrenheit - 32);
        printf("%10d|%+10.1lf\n", fahrenheit, celsius);
        fahrenheit++;
    }
    
    return 0;

}