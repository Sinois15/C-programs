#include <stdio.h>

char c[5] = {'A','B','C','D','E'};
char *letters[5] = {&c[0], &c[1], &c[2], &c[3], &c[4]};

void shift(char *letter[5]){
    char temp;
    temp = *letter[0];
    for (int i = 0; i<4; i++){
        *letter[i] = *letter[i+1];
    }
    *letter[4] = temp;
    for (int i = 0; i<5; i++){
        printf("%c ", *letter[i]);
    }printf("\n");

}

int main(){
    for(int i = 0; i<5; i++){
        shift(letters);
    }
    return 0;
}