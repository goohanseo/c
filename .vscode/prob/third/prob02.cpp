//데이터 테스트 통과
#include <stdio.h>
#define BUFFER_SIZE 100

int arr1[BUFFER_SIZE];
int arr2[BUFFER_SIZE];

int main(void){
    int n;
    int tmp;
    printf("n값을 입력하시오:");
    scanf("%d",&n);
    
    printf("%d개의 구간의 구간값들을 입력하시오:", n);
    
    //구간값들 입력받기
    for(int i=0; i<n; i++){
        scanf("%d", &arr1[i]);
        scanf("%d", &arr2[i]);
}

printf("-------------\n");

for(int i=0; i<n; i++){
    for(int j=i; j<n; j++){
    if (arr1[i]>arr1[j]){
        tmp = arr1[i];
        arr1[i]=arr1[j];
        arr1[j]=tmp;

        tmp = arr2[i];
        arr2[i]=arr2[j];
        arr2[j]=tmp;
    }
    
    if ( arr1[i] == arr1[j] && arr2[i] > arr2[j]){
        tmp = arr2[i];
        arr2[i]=arr2[j];
        arr2[j]=tmp;
    }

}}

 for(int i=0; i<n; i++){
        printf("%d %d\n",arr1[i], arr2[i]);
 }
return 0;
}