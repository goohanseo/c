//데이터 테스트 통과
#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 20
#include <set>

int main(void){
    bool not_same1;
    bool not_same2;
    char s1[MAX_LENGTH];
    char s2[MAX_LENGTH];

    printf("문자열 s1을 입력하시오");
    scanf("%s",s1);
    printf("문자열 s2를 입력하시오");
    scanf("%s",s2);
    
    
    for(int i=0; i < strlen(s1); i++){
        not_same1=true;
        for(int j=0; j< strlen(s2); j++){
            if(s1[i]==s2[j]){
                not_same1=false;
            }
            }
            if (not_same1==true){
                printf("no");
                return 0;
                
            }
    }

    
    for(int i=0; i < strlen(s2); i++){
        not_same2=true;
        for(int j=0; j< strlen(s1); j++){
            if(s2[i]==s1[j]){
                not_same2=false;
            }
            }
            if (not_same2==true){
                printf("no");
                break;
            }
    }
    if (not_same1==false && not_same2==false){
    printf("yes");
    }
    return 0;
}