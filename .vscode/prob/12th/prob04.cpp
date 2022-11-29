//테스트 데이터 통과
#include <stdio.h>
#include<stdbool.h>

#define MAX 1000
int count = 0;
int floor(int *data, int begin, int end, int K);
int ceiling(int *data, int begin, int end, int K);
int main(){
    int data[MAX];
    int N,K;
    scanf("%d", &N);
    for(int i = 0 ; i < N; i++){
        scanf("%d",&data[i]);
    }
    scanf("%d", &K);
    int begin = 0;
    int end = N-1;
    floor(data, begin,end, K);
    ceiling(data, begin, end, K);
    return 0;
}

    int floor(int *data, int begin, int end, int K){
        if(begin>end){
            printf("-1\n");
            return -1;
        }
        else{
            if(data[end]<=K){
            printf("%d\n",data[ end]);
            return 0;
            }
            else{
                return floor(data, begin, end-1, K);
            }
        }
    }
            

int ceiling(int *data, int begin, int end, int K){
        if(begin>end){
            printf("-1\n");
            return -1;
        }
        else{
            if (data[begin]>=K){
            printf("%d",data[begin]);
            return 0;
        }
         else{
            return ceiling(data, begin+1,end, K);
        }
        }
    }