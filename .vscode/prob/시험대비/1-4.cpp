#include <stdio.h>
#define BUFFER_SIZE 100

int abs(int a){ //절댓값 반환 해주는 함수
    if (a < 0){
        return -a;
    }
    return a;
}

int main(){

    int num[BUFFER_SIZE];
    int n, k;
    scanf("%d",&n);
    for(int i =0 ; i <n; i++){
        scanf("%d", &num[i]);
    }
    scanf("%d",&k);
    int index_min_diff = 0;
    for(int i = 1; i < n; i++){
        if (abs(num[i]-k) < abs(num[index_min_diff]-k)){
            num[index_min_diff] = num[i];
        }
    }
    printf("%d",num[index_min_diff]);
}