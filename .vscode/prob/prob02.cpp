//테스트 결과 데이터 출력 완료
#include<stdio.h>

int main() {
	int n;
	int num[100];
	int tmp;

	while (1) { //조건 달성 시까지 무한 루프
		printf("2~100사이 정수 n을 입력하시오: ");
		scanf("%d", &n); 
		if (n < 2 && n>100) { 
			printf("다시 입력하시오\n");}
		else {
			break;
		}
	}
	for (int i = 0; i < n; i++) { 
		scanf("%d", &num[i]);
	}

	for (int i = 0; i < n; i++) { //정렬 알고리즘 사용
		for (int j = i + 1; j < n; j++) { 
			if (num[i] > num[j]) { //i와 j값 비교하여 작은 수 부터 배열 앞쪽에 오도록 배열
				tmp = num[i];
				num[i] = num[j];
				num[j] = tmp;
			}
		}
	}

	printf("%d %d", num[0], num[1]); //1번째 2번째 배열 출력

	return 0;
}