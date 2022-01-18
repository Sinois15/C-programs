#include <stdio.h>

char word[15];

void stringReverse(){
    for (int i = 14; i>=0; i--){
        if (word[i] != NULL){
            printf("%c", word[i]);
        }
    }
}

int main(){
    printf("Enter a word: ");
    scanf("%s", &word);
    printf("Word in reverse order: ");
    stringReverse();
    return 0;
}