//테스트 데이터 통과
#include <stdio.h>

int main (void){
int num;
printf("하나의 양의 정수를 입력하시오:");
scanf("%d",&num);
while(num>0){
  num = num/2;
  printf("%d ",num);
}
return 0;
}
