#include<stdio.h>
#include<stdbool.h>

void insertsort(int arr[], int n){
    int i, k, j;
    for (i = 1; i<n; i++){
        k = arr[i];
        j = i -1;

        while (j >= 0 && arr[j] > k){
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j + 1] = k;
    }
}


bool isDuplicate(int arr[], int count, int input){
    for (int i = 0; i<count; i++){
        if(arr[i] == input){
            return true;
        }
    }
    return false;
}

int main() {
    int MAX_SIZE = 100;
    int input, count = 0;
    int num[MAX_SIZE];
    printf("정수 입력");

    while (true) {
        scanf("%d", &input); 
        if (input == -1){
            break;
        }

        if (isDuplicate(num, count, input)){
            printf("duplicate\n");
        } else {
            num[count++] = input;
            insertsort(num, count);

            for(int i = 0; i< count; i++){
                printf("%d", num[i]);
            }
            printf("\n");
        }
    }
    return 0;
}

