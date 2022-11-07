#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool check(char s[], char t[]);

int main(){
    char word1[20],word2[20];
    scanf("%s", word1);
    scanf("%s", word2);

    bool result1 = check(word1, word2);
    bool result2 = check(word2, word1);
    if (result1 && result2)
    printf("yes");
    else
    printf("no");
    return 0;
}

bool check(char s[], char t[]) {
    for (int i=0; i<strlen(s); i++){
        // s의 원소가 t에 속하는지
        bool exists = false;
        for(int j=0; j<strlen(t); j++){
            if (s[i] == t[j]){
                exists = true;
                break;
            }
        }
        if (!exists)
        return false;
    }

    return true;
}