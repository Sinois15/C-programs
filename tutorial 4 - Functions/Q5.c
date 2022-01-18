#include <stdio.h>

float charge[3], total = 0;
int hours[3];

void calculateCharges(int hours, int i){
    
    if (hours > 0 && hours < 3){
        charge[i] = 2.00;
    }
    else if(hours > 3 && hours < 21){
        charge[i] = 2 + (.5 * (hours - 3));
    }
    else if(hours > 21){
        charge[i] = 10;
    }
    total += charge[i];
    
}

int main(){
    int t;
    for (int i = 0; i<3; i++){
        printf("Enter how long car %d was parked: ", i+1);
        scanf("%d", &t);
        hours[i] = t;
        calculateCharges(t, i);
    }
    printf("Car No \t hours \t charge\n");
    for (int j = 0; j<3; j++){
        printf("%d \t %d \t $%.2f\n",j+1, hours[j],charge[j]);
    }
    printf("the total charge is %.2f", total);
    return 0;
}