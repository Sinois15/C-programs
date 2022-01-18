#include <stdio.h>

int main(){
    char word[10];
    int count = 0;
    printf("please enter a word: ");
    scanf("%s", &word);
    for (int i = 0; i<10; i++){
        if (word[i] != '\0'){
            count++;
        }
    }
    if (count%2 == 0){
        printf("the word is %s", word);
    }
    return 0;
}