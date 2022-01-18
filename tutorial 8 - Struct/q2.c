#include <stdio.h>

struct Student{
    int age;
    float weight;
    float height;
};
struct Student students[3];

void displayInfo(){
    printf("Age\tWeight\tHeight");
    for (int i = 0; i<3; i++){
        printf("%d\t%.2f\t%.2f", students[i].age, students[i].weight, students[i].height);
    }
}

int main(){
    
    for (int i = 0; i<3; i++){
        printf("Enter the age of student %d: ", i+1);
        scanf("%d", &students[i].age);
        printf("Enter the weight of student %d: ", i+1);
        scanf("%f", &students[i].weight);
        printf("Enter the height of student %d: ", i+1);
        scanf("%f", &students[i].height);
    }
    displayInfo();
    return 0;
}