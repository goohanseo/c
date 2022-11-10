#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUFFER_SIZE 100

void process_command();
void handle_push();
void handle_pop();
void handle_create();
void handle_list();
int read_line(FILE* fp, char str[], int n);
int num_stack = 0;

typedef struct stack {
    char* name;
    int top;
    char* data[BUFFER_SIZE];
    } *Stack;

Stack stacks[BUFFER_SIZE];

int main() {
    process_command();
    
    return 0;
}

void process_command() {
    char command_line[BUFFER_SIZE];
    char* command;
    while (1) {
        printf("$ ");
        if (read_line(stdin, command_line, BUFFER_SIZE) <= 0) {
            continue;
        }
        command = strtok(command_line, " ");
        if (strcmp(command, "create") == 0) {
            handle_create();
        }
        else if (strcmp(command, "push") == 0) {
            handle_push();
        }
        else if (strcmp(command, "pop") == 0) {
            handle_pop();
        }
        else if (strcmp(command, "list") == 0) {
            handle_list();
        }
        else if (strcmp(command, "exit") == 0) {
            break;
        }
        else {
            printf("unkown command\n");
        }
    }
}

void handle_create() {
    char* name = strtok(NULL, " "); //명령어 중에서 스택의 이름 추출
	stacks[num_stack] = (Stack)malloc(sizeof(Stack));
	stacks[num_stack]->name = strdup(name);
	stacks[num_stack]->top = -1;
	num_stack++;
}


void handle_push() {
    char* name = strtok(NULL, " ");
    char* update_data = strtok(NULL, " ");
    if (name == NULL || update_data == NULL) {
		printf("please enter command correctly\n");
		return;
	}
    for (int i = 0; i < num_stack; i++) {
        if (strcmp(stacks[i]->name, name) == 0) {
            stacks[i]->top++;
            stacks[i]->data[stacks[i]->top] = strdup(update_data);
        }
    }
}

void handle_pop() {
    char* name = strtok(NULL, " ");
    for (int i = 0; i < num_stack; i++) {
        if (strcmp(stacks[i]->name, name) == 0) {
            if(stacks[i]->top <= -1){
                return;
            }
            printf("%s\n", stacks[i]->data[stacks[i]->top]);
            stacks[i]->top--;
        }
    }
}

void handle_list() {
    char* name = strtok(NULL, " ");
    if (name == NULL) {
		printf("please enter stack name\n");
		return;
	}
    for (int i = 0; i < num_stack; i++) {
        if (strcmp(stacks[i]->name, name) == 0) {
            for (int j = stacks[i]->top; j >= 0; j--) {
				printf("%s\n", stacks[i]->data[j]);
			}
        }
    }
}

int read_line(FILE* fp, char str[], int n) {
    int ch, i = 0;
    while ((ch = fgetc(fp)) != '\n' && ch != EOF) {
        if (i < n - 1) {
            str[i++] = ch;
            }
            str[i] = '\0';
    }
    return i;
}
