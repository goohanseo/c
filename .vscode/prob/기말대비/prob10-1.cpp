#include <stdio.h>
#include <string/h>
#include <stdbool.h>
#define BUFFER_SIZE 100

bool is_palindrome(char *word, int length, int stack);

int main(){
    char word[BUFFER_SIZE];
    scanf("%s", word);
    int length = strlen(word);
    int tmp = 0;
    is_palindrome(word, length, tmp);
    return 0;
}

bool is_palindrome(char* word, int length, int tmp){
    if(word[0+tmp] != word[length - tmp -1]){
        printf("No");
        return false;
    }
    else if (tmp > length -tmp -1){
        printf("yes");
        return true;
    }
    else {
        return is_palindrome(word,length,tmp + 1);
    }
}