//테스트 데이터 통과
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int num, tmp;
	int arr[100]; 
	int buffer[100];
	int n = 0;
	int isDup;

	while (scanf("%d", &num) != EOF) {
		if (num == -1) {
			break;
		}
		isDup = 0;  //중복 flase로 초기화
		for (int i = 0; i <= n; i++) {
			if(arr[i] == num) { 
				printf("duplicate \n");
				isDup = 1; 
				n--; 
				break;
			}
		} //현재 arr[i]에 중복된다면 넣지 않고 duplicate 출력, 중복되지 않는다면 arr[i]배열에 입력
		
		if (isDup == 0) { 
			arr[n] = num; 

			for (int i = 0; i <= n; i++) {
				for (int j = i + 1; j <= n; j++) {
					if (arr[i] > arr[j]) {
						tmp = arr[i];
						arr[i] = arr[j];
						arr[j] = tmp;
					}
				}
			}

			for (int i = 0; i <= n; i++) {
				printf("[%d]", arr[i]);
			}
			printf("\n");
		}
		n++;
	}

	return 0;
}