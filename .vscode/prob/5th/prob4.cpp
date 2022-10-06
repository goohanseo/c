//데이터 테스트 통과
#include <stdio.h>
#include <string.h>
#define BUFFER_SIZE 1000

FILE * file;
char *arr[BUFFER_SIZE];
char buffer[BUFFER_SIZE];


void open_file();
void read_file();
void delete_tag();
void save_file();
int i = 0;

int main(void){
    open_file();
    read_file();
    save_file();
    return 0;
}

void open_file(){
    file = fopen("sample.html","r");
    if(file == NULL){
        printf("There is no file.");
        return;
    }
    else{
        printf("file open!\n");
    }
}

void read_file(){
    int i = 0;
    while(fgets(buffer, BUFFER_SIZE, file) != NULL){
        delete_tag();
        arr[i] = strdup(buffer);
        i++;
    }
    fclose(file);
}

void delete_tag(){
    int i = 0;
	int j = 0;
	char tmp[BUFFER_SIZE];
	while (buffer[i] != '\0') {
		if (buffer[i] == '<') { 
			while (buffer[i] != '>') {
				i++;
			}
			i++; 
			if (buffer[i] == '<') continue;
		}
		tmp[j++] = buffer[i++];
	}
	tmp[j] = NULL; 
	strcpy(buffer, tmp);
}



void save_file() {
	file = fopen("sample.txt", "w");
	
	for (int i = 0; arr[i] != NULL; i++) {
		fprintf(file, "%s\n", arr[i]);
	}

	fclose(file);
}