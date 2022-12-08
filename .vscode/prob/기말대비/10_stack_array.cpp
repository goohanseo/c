
//------------------------------STACKADT_H
#include <stdbool.h>
#define INIT_CAPACITY 100
typedef int Item; //코드의 재사용을 위한 노하우

typedef struct stack_type *Stack;

Stack create();
void destory(Stack s);
void make_empty(Stack s);
bool is_empty(Stack s);
void push(Stack s, Item i);
Item pop(Stack s);
Item peek(Stack s);

//-------------------------------STACKADT.c

struct stack_type{ //한 stack 구조체의 구성
    Item *contents;
    int top;
    int size;
};

static void terminate(const char *message){
    printf("%s\n", message);
    exit(1);
}

Stack create(){
    Stack s = (Stack)malloc(sizeof(struct stack_type)); //왜 스택포인터가 아니고 그냥 스택인가 typedef을 stack 자체가 struct stacktype의 포인터로 정의되었기 떄문 
    if (s == NULL){
        terminate("Error in create: stack could not be created");
    }
    s->contents = (Item *)malloc(INIT_CAPACITY * sizeof(Item));
    if (s->contents == NULL){
        free(s);
        terminate("Error in create: stack could not be created.");
    }
    s->top = -1;
    s->size = INIT_CAPACITY;
    return s; //새로 만들어준 stack s 반환
}

void destory(Stack s){
    free(s->contents); //stack 내부의 contents 먼저 비워줌
    free(s);
}

void make_empty(Stack s){ //stack을 다른 용도로 사용하기 위해 top을 젤 처음으로 돌려놓음
    s->top = -1;
}

bool is_empty(Stack s){
    return s->top == -1;
}

void push(Stack s, Item i){
    if (is_full(s)){
        reallocate(s);
    }
    s->top++;
    s->contents[s->top] =i;
}

Item pop(Stack s){
    if (is_empty(s)){
        terminate("Error in popL stack is empty.");
    }
    s->top;
    return s->contents[s->top+1];
}

Item peek(Stack s){
    if(is_empty(s)){
        terminate("Eroor in peek: stack is empty");
    }
    return s->contents[s->top];
}

void reallocate(Stack s){
    Item *tmp = (Item *)malloc(s * s->size * sizeof(Item));
    if (tmp == NULL){
        terminate("Error in create: stack could not be created");
    }
    for (int i=0; i<s->size; i++){
        tmp[i] = s->contents[i];
    }
    free(s->contents);
    s->contents = tmp;
    s->size *= 2;
}