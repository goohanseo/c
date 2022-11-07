// 2학년 2학기 기준으로 sort 정렬 정도는 알고 있지만
// insertion 정렬에 대해서도 알아놓아야 한다.

//메인 함수를 간결하게 하고 함수를 만들어서 가독성을 높여라

#include <stdio.h>

void insert(int *n, int num[], int k);
int main()
{
    int num[100];
    int n = 0, k;

    while (1)
    { //무한루프
        scanf("%d", &k);
        if (k == -1)
            break;
        insert(&n, num, k); //n은 while 문 밖에서 받아오기때문에 포인터로 해야 값 변경 안 됨
    }

    return 0;
}

void insert(int *n, int num[], int k)
{
    for (int i = 0; i < *n ; i++)
    {
        if (num[i] == k)
        {
            printf("duplicate\n");
            return; //return으로 for문 종료
        }
    }

    int j = *n - 1;
    while (j >= 0 && num[j] > k)
    { // num[j]가 0보다 작아지지 않도록 주의
        num[j + 1] = num[j];
        j--;
    }
    num[j + 1] = k;
    (*n)++;

    for (int i = 0; i < *n; i++)
    {
        printf("%d ", num[i]);
    }
    printf("\n");
}

// bool duplicate = false;
// for (int i =0l i<n; i++){
//     if (num[i] == k){
//         printf("duplicate\n");
//         duplicate = true;
//         break;
//     }
// }
// if (!duplicate){
//     int j = n-1;
//     while(j>=0 && num[j] > k){
//         num[j+1] = num[j]
//         j--;
//     }
//     num[j+1] = k;
//     n++;

//     for (int i =0; i<n; i++)
//     printf("%d ", num[i]);
//     printf("\n");
// }