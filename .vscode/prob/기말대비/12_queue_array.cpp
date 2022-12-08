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

#include<stdlib.h>
#define INIT_CAPACITY 100

struct queue_type{
    Item *contents;
    int front;
    int rear;
    int size;
    int capacity;
};

void terminate(const char *message){
    printf("%s\n", message);
    exit(1);
}

int get_size(Queue q){
    return q->size;
}

Queue create(){
    Queue q = (Queue)malloc(sizeof(struct queue_type));
    if(q == NULL){
        terminate("Error in create: queue could not be created.";)
    }
    q->contents = (Item *)malloc(INIT_CAPACITY * sizeof(Item));
    if (q->contents == NULL){
        free(q);
        terminate("Error in create: queue could not be created.");
    }
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    q->capacity = INIT_CAPACITY;
    return q;
}

void destory(Queue q){
    free(q->contents);
    free(q);
}

void make_empty(Queue q){
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

bool is_empty(Queue q){
    return q->size == 0;
}

bool is_full(Queue q){
    return q->size == q->capacity;
}

void enqueue(Queue q, Item i){
    if(is_full(q)){
        reallocate(q);
    }
    q->rear = (q->rear +1) %q->capacity; //만약 rear가 제일 마지막이면 0으로 돌아가고
    q->contents[q->rear] = i; // 제일 마지막이 아니면 그 다음을 가르킴
    q->size++;
}

Item dequeue(Queue q){
    if(is_empty(q)){
        terminate("Error in dequeue: queue is empty.");
    }
    Item result = q->contents[q->front];
    q->front = (q->front +1)%q->capacity; //enqueue와 동일
    q->size--;
    return result;
}

Item peek(Queue q){
    if (is_empty(q)){
        terminate("Error in peek: queue is empty.");
    }
    return q->contents[q->front];
}

void reallocate(Queue q){
    Item *tmp == (Item *)malloc(2 * q->capacity * sizeof(Item));
    if(tmp == NULL){
        terminate("Error in create: queue could not be expanded.");
    }
    int j = q->front;
    for (int i=0; j<q->size; i++){
        tmp[i] = q->contents[j]; //프론트가 j이므로 j를 tmp[0]자리에 넣음
        ㅓ = (ㅓ +1)%q->capacity;
    }
    free(q->contents);

    q->front = 0;
    q->rear = q->size -1;
    q->contents = tmp;
    q->capacity *= 2;
}