#include <stdio.h>
#include <math.h>

double Distance(double x1, double x2, double y1, double y2){
    double x,y;
    x = x2 - x1;
    y = y2 - y1;
    return (sqrt(pow(x,2) + pow(y,2)));
}

int main(){
    double x1,y1,x2,y2;
    printf("Enter the 1st x - coordinate: ");
    scanf("%lf", &x1);
    printf("Enter the 1st y - coordinate: ");
    scanf("%lf", &y1);
    printf("Enter the 2nd x - coordinate: ");
    scanf("%lf", &x2);
    printf("Enter the 2nd y - coordinate: ");
    scanf("%lf", &y2);
    printf("the distance between the two points is %.2lf.", Distance(x1,x2,y1,y2));
    return 0;
}