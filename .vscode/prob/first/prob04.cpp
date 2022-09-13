//테스트 데이터 통과
#include <stdio.h>
#include <cmath>

int main(void){
    int n;
    int k;
    int i;
    int t;
    printf("입력될 정수의 개수(n<=100)를 입력하시오 ");
    scanf("%d",&n);
    int list[n];
    for(i = 0; i<n; i++){
        scanf("%d",&list[i]); //list[i]값 입력 받음
    }
    for(i = 0; i<n; i++){
        printf("%d",list[i]); //list[i] 한 번 출력해줌
    }
    printf("\n하나의 정수 k를 입력하시오");
    scanf("%d", &k);
    int mim = list[0]-k; //list[0]과k의 차이값을 mim으로 임의로 지정

    for(i=0; i<n; i++)
        if (abs(list[i]-k)<abs(mim)){ //abs를 이용해서 절대값 구해서 비교
    int mim = list[i]-k;
        t =list[i];}
    printf("%d",t);
    return 0;
}