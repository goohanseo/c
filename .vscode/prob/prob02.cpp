//테스트 데이터 통과
#include <stdio.h>
int main(void){
    int n;
    while(1){
    printf("입력될 정수의 개수(2<=n<=100)를 입력하시오: ");
    scanf("%d",&n);
    if (n>=2 && n<=100)
    break;
    else
    printf("제대로 입력하세요\n");
    }
    int s[n];
    for(int i=0; i<n; i++){
    scanf("%d",&s[i]);}
    int f_mim=s[0];
    int s_mim=s[1];
 
    for(int i=0; i<n; i++){
        if (s[i]<f_mim)
        f_mim=s[i];
    }
    for(int i=0; i<n; i++){
        if (s[i]>=f_mim && s[i]<s_mim){
        s_mim=s[i];}
    }
    printf("%d %d",f_mim,s_mim);

    return 0;
}