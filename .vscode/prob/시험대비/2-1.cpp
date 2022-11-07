#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool check(char s[], char t[]);
int main(){
    char word1[20],word2[20];
    scanf("%s",word1);
    scanf("%s",word2);
    
    bool result1 = check(word1, word2);
    bool result2 = check(word2, word1);
    if(result1 && result2) //둘다 true일때만 yes
    printf("yes");
    
    else
        printf("no");
    return 0;
}

bool check(char s[], char t[]){
    for(int i=0; i<strlen(s); i++){ //s[i]가 t[j]안에 속해잇는지 
    bool exists = false;            //이중 for문으로 검사
    for(int j = 0; j<strlen(t); j++){
        if(s[i]==t[j]){
            exists = true;
            break;
        }
    }
    if(!exists)    //For문이 끝났을때 bool함수를 어떻게 끝냈는지로 판명
    return false; //s[i]번 돌면서 한번이라도 t[j]와 같으면 exists true
}

return true;
}