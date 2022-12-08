#include <stdio.h>

//------------------------queueadt.h
#include <stdbool.h>
typedef int Item;
typedef struct queue_type *Queue;

Queue create();
void destroy(Queue q);
void make_empty(Queue q);
bool is_empty(Queue q);
void enqueue(Queue q, Item i);
Item dequeue(Queue q);
Item peek(Queue q);
int get_size(Queue q); //que는 현재 que안에 저장된 갯수를 알아야되는 경우가 잇음

//------------------------queueadt.c
#include <stdlib.h>

struct node{
    Item data;
    struct node *next;
};

struct queue_type{
    struct node *front;
    struct node *rear;
    int size;
};

void terminate(const char *message){
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

int get_size(Queue q){
    return q->size;
}

Queue create(){
    Queue q = malloc(sizeof(struct queue_type));
    if (q == NULL){
        terminate("Error in create: queue could not be created.");
    }
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;
}

void destory(Queue q){
    make_empty(q);
    free(q);
}

void make_empty(Queue q){
    while (!is_empty(q)){
        dequeue(q);
    }
    q->size = 0;
}

bool is_empty(Queue q){
    return q->front == NULL;
}

void enqueue(Queue q, Item i){
    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL){
        terminate("Error in push: queue is full.");
    }
    new_node->data = i;
    new_node->next = NULL;
    if (q->front == NULL){ //empty
        q->front = new_node;
        q->rear = new_node;
    }
    else{ //추가는 무조건 연결리스트의 제일 마지막으로 들어감
        q->rear->next = new_node;
        q->rear = new_node;
    }
    q->size++;
}

Item dequeue(Queue q){ //삭제된 값 리턴 및 노드 프리
    struct node *old_front;
    Item i;
    if(is_empty(q)){
        terminate("Error in dequeue: queue is empty.");
    }
    old_front = q->front;
    i = old_front->data;
    q->front = old_front->next;
    if(q->front == NULL){
        q->rear = NULL;
    }
    free(old_front);
    q->size--;
    return i;
}

Item peek(Queue q){
    if (is_empty(q)){
        terminate("Error in peek: queue is empty.");
    }
    return q->front->data;
}