//데이터 테스트 통과
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define BUFFER_SIZE 200


void open_file();
int add(int n, char* words[]);
void sort(char* words[]);
int del_dup(char* words[]);

char buffer[BUFFER_SIZE];
int count, word_list, buffer_len;
char* words[BUFFER_SIZE];
char frequency[BUFFER_SIZE];

int main(void) {
	
	open_file(); 
	sort(words);
	del_dup(words);


	for (int i = 0; i < word_list; i++) {
		printf("%s : %d\n", words[i],frequency[i]);
	}
	printf("%d", word_list); 
	
	return 0;
}

void open_file() {
	int n = 0;
	FILE* harry = fopen("harry.txt", "r");
	if (harry == NULL) {
		printf("파일이 없습니다.");
		return;
	}
	else {
		printf("파일을 성공적으로 로드했습니다.\n");
		while (fscanf(harry, "%s", buffer) != EOF) { 
			if (buffer_len >= 6){
			add(n, words);
			n++;}
			}		}
			
	}


 
int add(int n, char* words[]) {
	words[n] = strdup(buffer); 
	count = n; 
	return count;
}

void sort(char* words[]) { 
	for (int i = 0; i <= count; i++) {
		for (int j = i + 1; j <= count; j++) {
			if (strcmp(words[i], words[j]) > 0) {
				char* tmp = words[i];
				words[i] = words[j];
				words[j] = tmp;
			}
		}
	}
}

int del_dup(char* words[]) {
	int j = 0;
	int k = 0;
	int l = 0;
	for (int i = 0; i <= count; i++) {
		if (i == 0 || strcmp(words[i], words[i - 1]) > 0) {
			words[j++] = words[i];
			frequency[l++]=k;
			k = 0;
		}
		else if (strcmp(words[i],words[i - 1])==0){
			if (strcmp(words[i-1],words[i-2])==0)
			{
				k++;
			}
		}
	}
	word_list = j; 

	return word_list;
}