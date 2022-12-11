#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define BUFFER_SIZE 100

int compare(char* str1, char* str2);

int main(){
    char word1[BUFFER_SIZE];
    char word2[BUFFER_SIZE];
    scanf("%s", word1);
    scanf("%s", word2);
    int index;
    compare(word1,word2);
    if (compare(word1, word2) == 1) {
        printf("%s\n", word2);
        printf("%s", word1);
        }
    else {
        printf("%s\n", word1);
        printf("%s", word2);
        }
    return 0;
}

int compare(char* str1, char* str2){
    if (str1[0] < str2[0]){
        return -1;
    }
    else if (str1[0] > str2[0]){
        return 1;
    }
    else if(str1[0] == NULL){
        return 0;
    }
    else{
        return compare(str1 +1, str2 + 1);
    }
}