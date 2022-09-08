//테스트 데이터 실패
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(void){
    int n;
    int k = (1/6)*n;
    double t=0;
    printf("몇번 던질지 N값을 입력하시오:");
    scanf("%d",&n);
    
    
    int count[6] = {0,};
    
    srand((unsigned int) time(NULL));
    for(int i=0; i<1000000;i++){
    for(int i =0; i< n; i++)
    {
        count[rand() % 6]++;
    }
    printf("%d\n",count[0]);
    if (count[0]<n/6){
    t++;}
    count[0]=0;
    }
    printf("%ld\n",t);
    printf("%f",1-(t/1000000));
return 0;
}