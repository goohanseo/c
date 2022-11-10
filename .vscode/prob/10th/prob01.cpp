#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define BUFFER_SIZE 100
#define MAX_CAPACITY 100
int bracket(char ch);
void push(int index);
char pop();
int stack[MAX_CAPACITY];
int top = -1;
int main() {
char buffer[BUFFER_SIZE];
int index = 1;
scanf("%s", buffer);
for (int i = 0; buffer[i] != NULL; i++) {
if (bracket(buffer[i]) == 0) {
push(index);
index++;
}
else if (bracket(buffer[i]) == 1) {
pop();
}
}
return 0;
}
//괄호 타입 분석
int bracket(char ch) {
if (ch == '(') { //ch가 여는 괄호면 0
return 0;
}
else if (ch == ')') { //ch가 닫는 괄호면 1
return 1;
}
else { //괄호가 아니면 -1
return -1;
}
}
void push(int index) {
top++;
stack[top] = index;
printf("%d ", stack[top]);
}
char pop() {
int tmp = stack[top];
printf("%d ", stack[top]);
top--;
return tmp;
}
