#include <stdio.h>
#include <stdlib.h>

typedef struct Student{
    int id;
    char name[10];
    int mark;
}student;
student std[30];

int main(){
    int i = -1;
    
    do{
        i++;
        printf("Enter the id of student %d(enter -1 to stop input process): ",i+1);
        scanf("%d", &std[i].id);
        if(std[i].id == -1){
            break;
        }
        printf("Enter the name of student %d: ",i+1);
        scanf("%s", &std[i].name);
        printf("Enter the marks of student %d: ",i+1);
        scanf("%d", &std[i].mark);
    }while(std[i].id != -1);
    printf("ID\tName\tMarks\n");
    for(int x=0; x<i; x++){
        if(std[x].mark>60 && std[x].mark<80){
            printf("%d\t%s\t%d\n", std[x].id, std[x].name, std[x].mark);
        }
    }
    return 0;
}