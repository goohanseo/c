//테스트 데이터 성공
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(void){
    int N; //정수 N값 int값으로 선언
    double t=0;
    printf("몇번 던질지 N값을 입력하시오:");
    scanf("%d",&N);
    int count[6] = {0,}; //주사위 기능 1~6까지의 난수 생성
    srand((unsigned int) time(NULL)); //srand 난수 생성을 통해 반복문 실행시마다 새로운 난수 받아옴
    for(int i=0; i<1000000;i++){ //큰수의 법칙을 위한 1000000번 실행
        for(int i =0; i< N; i++){ //N값만큼 주사위를 던짐
            count[rand() % 6]++;
    }
    printf("%d\n",count[0]); //N번 던질 때마다 1이 몇 번 나오는지 표시
    if (count[0]<N/6){
    t++; //1이 k번보다 작게 나올 때 마다 t값 1씩 추가
    }
    count[0]=0;
    }
    printf("%f",1-(t/1000000)); //t값을 이용해 전체 확률 구함
return 0;
}