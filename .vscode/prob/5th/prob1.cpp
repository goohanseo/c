//데이터 테스트 통과
#include <stdio.h>
#include <string.h>
#include <iostream>
#define BUFFER_SIZE 100

char sentence[BUFFER_SIZE];
int arr[BUFFER_SIZE];
int n;
void longest();
void maximum();
int max_len;
int num;
int tmp;

int main(void){
    printf("문자열을 입력하시오:");
    scanf("%s",sentence);
    n = strlen(sentence);
    //printf("문자열의 갯수 : %d\n",n);
    longest();
    maximum();
    int tmp = num + max_len ;
    for(int i = num ; i < tmp; i++){
        printf("%c", sentence[i]);
    }
    
    return 0;
}

void longest(){
    for(int i = 0; i < n; i++){
        int j = i;
        tmp = 0;
    while(sentence[j] != 'a' && sentence[j] != 'e' && sentence[j] != 'i' 
    && sentence[j] != 'o'  && sentence[j] != 'u' && j < n){
        tmp = tmp +1;
        j++;
    }
    arr[i] = tmp;
    tmp = 0;
    j=0;
    //printf("%d,%d\n",i,arr[i]);
    }
}
void maximum(){
    max_len = arr[0];
    for(int i = 0; i<n; i++){
        if(max_len < arr[i]){
        max_len = arr[i];
        num = i;}
        //printf("연속된 자음의 최대 길이:%d,%d,%d\n",max_len,i,arr[i]);
    }
//printf("연속된 자음의 최대 길이:%d,시작 주소%d\n",max_len,num);
}
