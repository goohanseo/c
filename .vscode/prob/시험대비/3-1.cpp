#include <stdio.h>

int main(){
    int n;
    int num[100];
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%d",&num[i]);
    }
    

    for(int i=n-1; i>0; i--){
        int max_index = 0; //for문 안에 있어야 매번 최댓값 구함
        for (int j =0; j<=i; j++){
            if(num[j] > num[max_index])
            max_index = j;
        }
        int tmp = num[i]; //가장 마지막 배열인 i
        num[i] = num[max_index];
        num[max_index] = tmp;
    }
    for (int i=0; i<n; i++)
    printf("%d ", num[i]);
    return 0;
}