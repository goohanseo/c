//테스트 데이터 통과
#include <stdio.h>
int main(void){
    int list[100];
    printf("정수를 입력하시오:");
    for(int i =0; i<100; i++){
        scanf("%d",&list[i]);
        for(int j =0; j<i; j++){
        if (list[j] == list[i])
        {
        printf("duplicate");}
        else
        for (int n = 0; n<=i; n++ ){
        printf("%d ",list[n]);}}
    }
    return 0;
}

