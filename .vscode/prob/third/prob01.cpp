#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 100

void max();
void swap();
int n;
int arr[BUFFER_SIZE];
int max;
int tmp;


int main(void) {
	printf("n과 n개의 정수를 입력하시오:");
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < n; i++) {
		printf("%d", arr[i]);
	}
    printf("\n");
	max();
	swap();
    for (int i = 0; i < n; i++) {
		printf("%d", arr[i]);
	}
	return 0;
}

void max() {
	max = arr[0];
	for (int i = 0; i < n; i++) {
		if (max < arr[i]) {
			max = arr[i];
		}
	}
}
void swap(){
    tmp = arr[n-1];
    arr[n-1]=max;


}