#include <stdio.h>

static char OPERATORS[] = "+-*/";
static int PRECEDENCE[] = {1,1,2,2}; //우선순위 비교

Stack operator_stack;

int precedence(char op){ //우선순위 지정
    return PRECEDENCE[is_operator(op)]; // +-*/은 1122순으로 배당 받음 
}

int is_operator(char ch){
    for (int i=0; i<strlen(OPERATORS); i++){
        if(OPERATORS[i] == ch){
            return i;
        }
    }
    return -1;
}

int eval(char *expr){ //후위표기식
   operand_stack = create();
   char *token = strtok(expr, " ");
   while(token != NULL){
    if (token[0] >= '0' && token[0] <= '9'){
        int value = atoi(token);
        push(operand_stack, value);
    }
    else if (is_operator(token[0]) > -1){
        int result = eval_op(token[0]);
        push(operand_stack, result);
    }
    else {
        handle_exception("Syntax Error: invalid character encountered.");
    }
    token = strtok(NULL, " ");
   }
   if(is_empty(operand_stack)){
    handle_exception("Syntax Error: Stack empty in eval_op");
   }
   int answer = pop(operand_stack); //결과 팝하고 나서 비어있으면 결과 출력
   if(is_empty(operand_stack)){
    return answer;
   }
   else {
    handle_exception("Syntax Error: Stack should be mepty.");
    return -1;
   }
}

int eval_op(char op){
    if (is_empty(operand_stack)){
        handle_exception("Syntax Error: Stack empty in eval_op.");
    }
    int rhs = pop(operand_stack);
    if (is_empty(operand_stack)){
        handle_exception("Syntax Error: Stack empty in eval_op.");
    }
    int lhs = pop(operand_stack);
    int result = 0;
    switch (op){
        case '+': result = lhs + rhs; break;
        case '-': result = lhs - rhs; break;
        case '*': result = lhs * rhs; break;
        case '/': result = lhs / rhs; break;
    }
    return result;
}

void handle_exception(const char *err_msg){
    printf("%s\n", err_msg);
    exit(1);
}



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