//테스트 데이터 통과
#include <stdio.h>

int main (void){
int n;
printf("하나의 양의 정수를 입력하시오: ");
scanf("%d",&n);
while(n>0){
n /= 2;
  printf("%d ",n);
}
return 0;
}

