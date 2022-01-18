#include <stdio.h>
#include <string.h>
struct food
{
	char name[15];
	int portion_weight;
	int calories;
};


int main(){
    struct food meal[10];
    strcpy(meal[0].name, "apple");
    meal[0].portion_weight = 4;
    meal[0].calories = 200;
    printf("%d", meal[0].calories);
    return 0;
}