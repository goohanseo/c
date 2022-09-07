#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(void){
    for(int i=0; i<1000000; i++){
        int count[6] = {0,};
    int N;
    printf("몇번 던질지 N값을 입력하시오:");
    scanf("%d",&N);
    srand((unsigned int) time(NULL));
    for(int i =0; i< N; i++)
    {
        count[rand() % 6]++;
    }
    printf("1의 개수 : %d\n",count[0]);
    printf("상수(1~6) k를 입력하시오:");
    int k;
    scanf("%d",&k);
    }
}