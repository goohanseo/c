//데이터 테스트 통과
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define BUFFER_SIZE 200
#define WORDS_SIZE 99999

FILE* harry;
char buffer[BUFFER_SIZE];
int count;
char* words[WORDS_SIZE];
int frequency[WORDS_SIZE];

void open_file();
int check_list(int mim_len);
void sort(char* words[]);
void del_dup(char* words[]);

int main(void) {
	
	open_file();
	check_list(6); 
	sort(words);
	del_dup(words);


	for (int i = 0; i < count; i++) {
		printf("%s : %d\n", words[i],frequency[i]);
	}
	printf("%d\n", count); 
	
	return 0;
}

void open_file() {
	harry = fopen("harry.txt", "r");
	if (harry == NULL) {
		printf("파일이 없습니다.");
		return;
	}
	else {
		printf("파일을 열었습니다.\n");
				}

	}

int check_list(int mim_len){
	int i =0;
	while (fscanf( harry , "%s", buffer) != EOF) { 
			if (strlen(buffer) >= mim_len){
				words[i++] = strdup(buffer);
			}
}
count = i;
return count;
}

 


void sort(char* words[]) { 
	for (int i = 0; i < count; i++) {
		for (int j = i + 1; j < count; j++) {
			if (strcmp(words[i], words[j]) > 0) {
				char* tmp = words[i];
				words[i] = words[j];
				words[j] = tmp;
			}
		}
	}
}

void del_dup(char* words[]) {
	int j = 0;
	for (int i = 0; i < count; i++) {
		if (i == 0 || strcmp(words[i], words[i - 1]) > 0) {
			words[j] = words[i];
			frequency[j] = frequency[j] + 1; 
			j++;
		}
		else{ 
			frequency[j-1] = frequency[j - 1] + 1;
		}
	}
	count = j; 
}