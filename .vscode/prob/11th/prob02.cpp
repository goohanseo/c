//테스트데이터통과

#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define STACK_SIZE 1000
#define WALL 0
#define PATH 1
#define VISITED 2
#define BACKTRACKED 3

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3
#define RIGHT_UP 4
#define RIGHT_DOWN 5
#define LEFT_DOWN 6
#define LEFT_UP 7


typedef struct testcase{
    int maze_size;
    int comp_num;
    int comp_arr[MAX];
    int maze[MAX][MAX];
}Testcase;

typedef struct pos{
    int x, y;
}Position;


typedef struct node {
	Position pos;
	node* next;
}Node;

typedef struct queue {
	Node* front;
	Node* rear;
	int size;
}Queue;
 
void create(int test_case);
void read_maze();
void search(Testcase*);
bool movable(Testcase*, Position cur, int dir);
Position startPos(Testcase*);
void print(Testcase*);

Position moveto(Position pos, int dir);

Queue* create();
void enqueue(Queue*, Position pos);
Position dequeue(Queue*);
Position peek(Queue*);
void destoy(Queue*);
void make_empty(Queue*);
bool isEmpty(Queue*);

int test_case;
Testcase *test[MAX];
Queue* q;

int main(){
    read_maze();
    q = create();
    for(int i = 0; i< test_case; i++){
        search(test[i]);
        print(test[i]);
    }
    return 0;
}

void create(int test_case){
    test[test_case] = (Testcase *)malloc(sizeof(Testcase));
    test[test_case]->comp_num = 0;
}

void read_maze(){
    int N, tmp;
	FILE* fp = fopen("input.txt", "r");
	if (fp == NULL) {
		return;
	}

	fscanf(fp, "%d", &test_case); //몇 개의 case가 있는지
	for (int i = 0; i < test_case; i++) {
		create(i); //case가 저장될 공간 할당
		fscanf(fp, "%d", &N); //해당 case의 maze 크기는 
		test[i]->maze_size = N; 
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				fscanf(fp, "%d", &tmp); 
				test[i]->maze[j][k] = tmp;
			}
		}
	}
	fclose(fp);
}

void search(Testcase *test){
    Position cur;
    while (1){
        cur = startPos(test);
        if(cur.x == -1 && cur.y == -1){ 
			break;
    }
    enqueue(q, cur);
    test->maze[cur.x][cur.y] = -1;
    while(!isEmpty(q)){
        cur = dequeue(q);
        for(int dir = 0; dir < 8; dir++){
            if (movable(test, cur, dir)){
                Position p = moveto(cur,dir);
                test->maze[p.x][p.y] = test->maze[cur.x][cur.y] - 1;
                enqueue(q, p);
            }
        }
    }
    test->comp_arr[test->comp_num++] = q->size;
    make_empty(q);
    }
}

bool movable(Testcase *test, Position pos, int dir){
    Position can = moveto(pos,dir);
    if (test->maze[can.x][can.y] == PATH){
        return true;
    }
    return false;
}

Position startPos(Testcase *test){
    Position start_pos;
    start_pos.x = -1;
	start_pos.y = -1;
    for (int i =0; i< test->maze_size; i++){
        for(int j =0; j < test->maze_size; j++){
            if (test->maze[i][j] == PATH){
                start_pos.x = i;
                start_pos.y = j;

                return start_pos;
            }
        }
    }
    
	return start_pos;
}

void print(Testcase* test){
    for (int i = 0; i < test->comp_num; i++) {
		printf("%d ", test->comp_arr[i]);
	}
	printf("\n");
}



int offset[8][2] = { 
	{-1,0}, //0
	{0,1}, //1
	{1,0},  //2
	{0,-1},  //3
	{-1,1}, //4
	{1,1}, //5
	{1,-1}, //6
	{-1,-1} //7
};

Position moveto(Position pos, int dir) {
	Position next;
	next.x = pos.x + offset[dir][0];
	next.y = pos.y + offset[dir][1];
	return next;
}

Queue* create() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
	q->front = NULL;
	q->rear = NULL;
	q->size = 0;
	
	return q;
}

void enqueue(Queue *q, Position pos) {
    Node* new_node = (Node*)malloc(sizeof(Node));
	
	new_node->pos = pos;
	new_node->next = NULL;
	if (q->front == NULL) { 
		q->front = new_node;
		q->rear = new_node; 
	}
	else { 
		q->rear->next = new_node;
		q->rear = new_node;
	}
	q->size++;
}

Position dequeue(Queue *q) {
    Node* old_front;
	Position pos;

	old_front = q->front;
	pos = old_front->pos;
	q->front = old_front->next;
	if (q->front == NULL) { 
		q->rear = NULL;
	}
	free(old_front); 

	return pos; 
}


Position peek(Queue* q) { 
	if (isEmpty(q)) {
		printf("ERROR: Queue is empty\n");
	}
	return q->front->pos;
}

void destoy(Queue* q) {
	make_empty(q);
	free(q);
}

void make_empty(Queue* q) {
	while (!isEmpty(q)) {
		dequeue(q);
	}
	q->size = 0;
}

bool isEmpty(Queue* q) {
	if (q->front == NULL) {
		return true; //NULL이면 true 반환
	}
	else {
		return false;
	}
}