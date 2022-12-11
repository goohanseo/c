#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 100
#define BUFFER_LENGTH 200

//---------------------------------------string_tools.h
//#include<stdio.h>
int read_line(FILE *fp, char str[], int n);

//---------------------------------------stack.h
#define INIT_CAPACITY 100
typedef struct stack{
    char* name;
    int top;
    char* data[BUFFER_SIZE];
}*Stack;

Stack stacks[BUFFER_SIZE];
int num_stack = 0;

//---------------------------------------main.cpp

void process_command();
void create();
void push();
void list();
void pop();

int main(){
    process_command();
    return 0;
}

void process_command(){
    while(1){ //무한 루프
    char command_line[BUFFER_LENGTH];
    char *command;
        printf("$ "); //prompt 출력 사용자로부터 명령어 받아서 실행

        if (read_line(stdin, command_line, BUFFER_LENGTH) <= 0){ //라인 단위로 받아옴
           continue;
        }
        command = strtok(command_line, " ");
        if (strcmp(command, "create")==0){
            create();
        }
        else if (strcmp(command, "push")==0){
            push();
        }
        else if (strcmp(command, "list")==0){
            list();
              }
        else if (strcmp(command, "pop")==0){
            pop();
        }
        else if (strcmp(command, "exit")==0){
            break;
        }
    }
}

void create(){
    char *name = strtok(NULL, " ");
    stacks[num_stack] = (Stack)malloc(sizeof(Stack));
    stacks[num_stack]->name = strdup(name);
    stacks[num_stack]->top = -1;
    num_stack++;
}

void push(){
    char *name = strtok(NULL, " ");
    char *update_data = strtok(NULL, " ");
     if (name == NULL || update_data == NULL) {
		printf("please enter command correctly\n");
		return;
	}
    for(int i=0; i<num_stack; i++){
        if(strcmp(stacks[i]->name,name) == 0){
            stacks[i]->top++;
            stacks[i]->data[stacks[i]->top] = strdup(update_data);
        }
    }

}

void pop(){
    char *name = strtok(NULL, " ");
    for(int i=0; i<num_stack; i++){
        if(strcmp(stacks[i]->name,name) == 0){
            if(stacks[i]->top <=-1){
                return;
            }
            printf("%s\n", stacks[i]->data[stacks[i]->top]);
            stacks[i]->top--;
        }
    }
}

void list(){
    char *name = strtok(NULL, " ");
    for(int i=0; i<num_stack; i++){
        if(strcmp(stacks[i]->name,name) == 0){
            for(int j= stacks[j]->top; j >= 0; j--){
                printf("%s\n", stacks[i]->data[j]);
            }
        }
    }
}



//---------------------------------------string_tools.cpp
//#include "string_tools.h"
int read_line(FILE *fp, char str[], int n){
    int ch,i = 0;
    while ((ch=fgetc(fp)) != '\n' && ch != EOF){ //한 라인의 끝 또는 한 파일의 끝
        if (i<n-1){
            str[i++] = ch;
        }
    }
    str[i] = '\0';
    return i;
    }
