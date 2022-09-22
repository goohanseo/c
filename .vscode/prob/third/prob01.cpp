//데이터 테스트 통과
#include <stdio.h>
#define BUFFER_SIZE 100

int n;
int data[BUFFER_SIZE];
void max_swap();
int maximum;
int tmp;
int j;
int k;

int main(void){
    printf("정수 n을 입력하시오:\n");
    scanf("%d",&n);
    printf("n개의 배열을 입력하시오:\n");
    
    for(int i =0; i<n; i++){
        scanf("%d",&data[i]);
    }
    
    k = n;
    for(int i = 0; i < k-1; i++){
    max_swap();
    tmp = data[j];
    data[j]=data[n-1];
    data[n-1]= tmp;
    n--;
   
    }
     printf(" ");
    for(int i =0; i<k; i++){
        printf("%d ",data[i]);
    }
    return 0;
}


void max_swap(){
    maximum = data[0];
    for(int i = 0; i < n; i ++){
        if (maximum <= data[i]){
            maximum = data[i];
            j = i;
        }
    }

}
