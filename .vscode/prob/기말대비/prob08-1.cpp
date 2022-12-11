#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 100

//------------------------------stack.h
void push(int num);
void pop();
int is_full();

//------------------------------main.cpp

void check_stack(char tmp);
int num =0 ;

int main(){
    char array[100];
    scanf("%s",array);
    int n = strlen(array);
    for(int i=0; i<n; i++){
        if(array[i] == '('){
            num++;
            push(num); //스택 값 올려주기 더 개선해보아야함
            printf("%d",num);
        }
        else if(array[i]==')'){
            pop();
        }
        else{
            continue;
        }
    }
    return 0;
}


//------------------------------stack.cpp
//include "stack.h"
#define MAX_CAPACITY 100

char stack[MAX_CAPACITY];
int top = -1;

void push(int num){
    if (is_full()){
        return;
    }
    top++;
    stack[top] = num;
}

void pop(){
    char tmp = stack[top];
    top--;
    printf("%d",tmp);
}

int is_full(){
    return top == MAX_CAPACITY-1;
}

