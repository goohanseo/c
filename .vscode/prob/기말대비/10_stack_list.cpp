//stack을 연결리스트로 구현할 때는 연결리스트의 제일 앞 노드를 기준으로 한다
//add_first = <push> 와 remove_first = <pop> 


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

struct node{
    Item data;
    struct node *next;
};

struct stack_type{
    struct node *top;
};

static void terminate(const char *message){
    printf("%s\n",message);
    exit(EXIT_FAILURE);
};

Stack create(){
    Stack s = malloc(sizeof(struct stack_type));
    if (s == NULL){
        terminate("Error in create: stack could not be created.");
        s->top = NULL;
        return s;
    }
}

void destory(Stack s){
    make_empty(s);
    free(s);
}

void make_empty(Stack s){
    while(!is_empty(s)){
        pop(s);
    }
}

bool is_empty(Stack s){
    return s->top == NULL;
}

void push(Stack s, Item i){
    struct node *new_node = malloc(sizeof(struct node));{
        if (new_node == NULL){
            terminate("Error in push: stack is full.");
        }
        new_node->data = i;
        new_node->next = s->top;
        s->top = new_node;
    }
}

Item pop(Stack s){
    struct node *old_top;
    Item i;

    if(is_empty(s)){
        terminate("Error in pop: stack is empty.");
    }
    old_top = s->top;
    i = old_top->data;
    s->top = old_top->next;
    free(old_top);
    return i;
}

Item peek(Stack s){
    if (is_empty(s)){
        terminate("Error in peek: stack is empty.");
    }
    return s->top->data;
}