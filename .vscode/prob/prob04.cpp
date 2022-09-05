//테스트 데이터 통과
#include <stdio.h>
#include <cmath>

int main(void){
    int n;
    int k;
    int i;
    int t;
    printf("입력될 정수의 개수(n<=100)를 입력하시오");
    scanf("%d",&n);
    int list[n];
    for(i = 0; i<n; i++){
        scanf("%d",&list[i]);
    }
    for(i = 0; i<n; i++){
        printf("%d",list[i]);
    }
    printf("\n하나의 정수 k를 입력하시오");
    scanf("%d", &k);
    int mim = list[0]-k;
    abs(mim);
    for(i=0; i<n; i++)
        if (abs(list[i]-k)<abs(mim)){
    int mim = list[i]-k;
        t =list[i];}
    printf("%d",t);
    return 0;
}