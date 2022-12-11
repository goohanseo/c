#include <stdio.h>
#include <stdbool.h>

#define MAX 1000
int count = 0;
bool twoSum(int *data, int begin, int end, int K);
int main(){
    int data[MAX];
    int N,K;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        sacnf("%d", &data[i]);
    }
    scanf("%d", &K);
    int begin = 0;
    int end = N-1;
    twoSum(data, begin, end, K);
    printf("%d\n", count);
    return 0;
}

bool twoSum(int *data, int begin, int end, int K){
    if (begin>=end){
        return false;
    }
    else{
        if(data[begin] + data[end] == K){
            count++;
            return twoSum(data, begin+1, end-1, K);
        }
        else if (data[begin] + data[end]<K){
            return twoSum(data, begin+1, end, K);
        }
        else{
            return twoSum(data,begin, end-1, K);
        }
    }
}