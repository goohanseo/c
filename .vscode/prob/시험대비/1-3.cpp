#include <stdio.h>
#define BUFFER_SIZE 100

void insert(int *n,int num[], int k);

int main(){
    int num[BUFFER_SIZE];
    int n=0;
    int k;
    //scanf("%d",&n); //배열의 크기 지정하면 안 됨. 안에서 알아서 만들어지도록
    while(1){ //반복횟수를 모르니 무한 루프 돌고 그만 둘 조건 입력하기
        scanf("%d",&k);
        if (k == -1)
        break;
        insert(&n,num,k); //지역변수에 매개변수로 넘겨주기 때문에 
    }                     //n의값을 가지고 잇는 주소 *n을 넘겨주어야함
    return 0;
}

void insert(int *n,int num[], int k)
{
    for (int i = 0; i< *n && num[i] <= k ; i++){
        if(num[i] == k) //i에서 끝난거 생각해서 뒤에 코드 개선 해줘도 됨.
        {
            printf("duplicate\n");
            return; //insert 함수 종료
        }
    }
            int j = *n -1; //for(; j>=i; j--)
            while(j>=0 && num[j]>k) //기존 배열이 k보다 크면 뒤로 보내기 j--이니까 0보다 큰거 조심
            {
            num[j+1] = num[j]; //arr배열은 원래 크기가 100이기 때문에 상관없음
            j--;
            }
            num[j+1] = k; //j--로 끝났으니 j+1에 넣어주어야함
            (*n)++;
    
    for ( int i =0; i < *n; i++)
    {
        printf("%d ",num[i]);
    }
    printf("\n");
}