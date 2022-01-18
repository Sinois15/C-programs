#include <stdio.h>
#include <time.h>

typedef struct HealthProfile{
    char fName[10];
    char lName[10];
    char gender[6];
    int yob;
}HP;
HP p1; 

int main(){
    printf("Enter your first name: ");
    scanf("%s", &p1.fName);
    printf("Enter your last name: ");
    scanf("%s", &p1.lName);
    printf("Enter your gender: ");
    scanf("%s", &p1.gender);
    printf("Enter your year of birth: ");
    scanf("%s", &p1.fName);
    printf("First Name\tLast Name\tGender\tYear of Birth\tAge\n");
    printf("%s\t%s\t%s\t%d\t%d\n",p1.fName, p1.lName, p1.gender, p1.yob, 2020-p1.yob);
    return 0;
}