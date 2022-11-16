#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef int Item;

//typedef struct stack_type *Stack;

Stack create();
void destory(Stack s);
void make_empty(Stack s);
bool is_empty(Stack s);
void push(Stack s, Item i);
Item pop(Stack s);
Item peek(Stack s);

#endif