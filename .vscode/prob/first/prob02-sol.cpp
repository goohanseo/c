#include <stdio.h>

int main (void){
    int n;
    int num[100]; //c언어에서 배열의 길이 변수로 지정 못 함

    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%d",&num[i]);
}
int theMin; //초기화 하는것이 중요
int theSecond;
if(num[0] <= num[1]){
    theMin = num[0]; //두 개의 초기화값이 필요하다면 배열의 두 개의 대소 비교 후 입력
    theSecond = num[1];
}
else {
    theMin = num[1];
    theSecond = num[0];
}
for (int i=0; i<n; i++){
    if (num[i] < theMin){
        theSecond = theMin;
        theMin = num[i];}
    else if (num[i] < theSecond){
        theSecond = num[i];
    }
}
printf("%d %d\n", theMin, theSecond);
return 0;
}