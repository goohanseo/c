//데이터 테스트 통과
#include <stdio.h>
#define BUFFER_SIZE 100

int arr[BUFFER_SIZE];
int n;
int k;
int main(void){
    printf("N값을 입력하시오:");
    scanf("%d",&n);
    printf("배열을 입력하시오:");
    for(int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }
    for(int i = 0; i < n-1; i++){
        for(int j = i + 1; j < n; j++){
            if (arr[i]>arr[j]){
                k++;
            }
        }
    }
    printf("%d",k);
}