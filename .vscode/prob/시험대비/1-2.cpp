#include <stdio.h>
#define BUFFER_SIZE 100
int main(){
    int n;
    int arr[BUFFER_SIZE];
    int mim;
    int second;
    scanf("%d",&n);
    
    for(int i =0; i<n; i++){
        scanf("%d",&arr[i]);
    }

    if (arr[0] < arr[1]){ //두개의 최솟값 구할 경우 두 인자 지정해주는데
    mim = arr[0];         //대소비교해서 인자 지정해주기
    second = arr[1];
    }
    else {
        mim = arr[1];
        second = arr[0];
    }

    for(int i = 0; i<n; i++){ //최솟값보다 작으면 최솟값과 세컨드 한칸씩 미루기
        if (arr[i] <= mim){ //값 두개기 때문에 = 있어야됨
        second = mim;
        mim = arr[i];
        }
        else if (arr[i]<second){ //최솟값보다 크고 세컨드보다 작으면 세컨드만 한칸 미루기
            second = arr[i];
        }
    }
    printf("%d %d",mim, second);
}