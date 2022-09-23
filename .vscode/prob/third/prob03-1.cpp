//데이터 테스트 통과 완료
#include <stdio.h>
#include <string.h>
#define BUFFER_SIZE 10000
#define WORDS 99999

FILE* shuffled_dict;
int count;
char buffer[BUFFER_SIZE];
char* words[WORDS];
char* word_setence[WORDS];


void open_file();
void read_file();
void sort_words();
void save_new_file();


int main(void){
 open_file();
 read_file();
 sort_words();
 for (int i = 0; i < count; i++) {
		printf("%s", word_setence[i]);
	}
 save_new_file();
return 0;
}

void open_file(){
   shuffled_dict = fopen("shuffled_dict.txt","r");
   if (shuffled_dict == NULL){
      printf("파일이 없습니다.");
      return;
   }
   else{
      printf("파일을 성공적으로 로드했습니다.\n");
      }
   }

void read_file(){
   count = 0;
   while(fgets(buffer, BUFFER_SIZE , shuffled_dict) != NULL){
    word_setence[count] = strdup(buffer);
        for(int i = 0; i < BUFFER_SIZE; i++){
            if(buffer[i] == '\t'){
                words[count] = strdup(buffer);
            }
        }
        count++;
    }

}

void sort_words() {
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < (count -i) -1; j++) {
			if (strcmp(words[j], words[j + 1]) > 0) {
				char* tmp = words[j];
				words[j] = words[j + 1];
				words[j + 1] = tmp;

				tmp = word_setence[j];
				word_setence[j] = word_setence[j + 1];
				word_setence[j + 1] = tmp;
			}
		}
	}
}

void save_new_file() {
	FILE* sorted_dict = fopen("sorted_dict.txt", "w");
	for (int i = 0; i < count; i++) {
		fputs(word_setence[i], sorted_dict);
	}
	printf("파일 저장 완료");
}