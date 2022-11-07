#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 100


void bubblesort(int n, char *words[]);
int main(){
    char *words[BUFFER_SIZE];
    int n;
    char buf[20];

    scanf("%d",&n);
    for(int i=0; i <n; i++){
        scanf("%s",buf);
        words[i] = strdup(buf); //words[i]가 가르키는 주소에 buf를 복제
    }                            
    bubblesort(n,words);
    for(int i=0; i<n; i++){
        printf("%s\n",words[i]);
}
return 0;
}

void bubblesort(int n, char *words[])
{
    for(int i = n-1; i >0; i--){
        for(int j = 0; j < i; j++){
            if(strlen(words[j])>strlen(words[j+1])|| //문자열이 길거나
            strlen(words[j])==strlen(words[j+1])&& //문자열이 같을때 사전식
                strcmp(words[j],words[j+1])>0){
                char * tmp = words[j];
                words[j] = words[j+1];
                words[j+1] = tmp;
            }
        }
    }
}