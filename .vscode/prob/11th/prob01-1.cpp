//테스트 데이터 통과
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100
#define WALL 0 //벽이면 못가요
#define PATH 1 //이동가능한 길
#define VISITED 2 //되돌아갈순 있는길
#define BACKTRACKED 3 //되돌아갈수 없는 길
#define BUFFER_SIZE 10000
#define STACK_SIZE 1000
#define INIT_CAPACITY 100

typedef struct pos {
    int x, y;
} Position;

typedef struct stack_type{
    Position pos[STACK_SIZE];
    int top;
    int size;
}*Stack;

typedef struct test_case{ //테스트케이스 구조체
    int maze_size;  //미로판 크기
    int **argument; //이차원배열
    int component_num ; //component 갯수
    int *component_arr; //각 component의 크기
} *Test_case;

int maze[MAX][MAX]; //미로판
int entry_count; //전체 테스트케이스 갯수
int maze_size; //테스트케이스 내 가로세로 크기
int num = 0; //테스트케이스의 순서
int tmp = 0; //componenet들의 갯수 배열
void read_maze(); //테스트 불러오기
void print_maze(); //테스트 케이스당 컴포넌트 크기 출력
bool moveable(Position pos, int dir); //다음으로 넘어갈 수 있는지 판단
Position move_to(Position pos, int dir);
Stack create();
void initStack(Stack s);
void push(Stack s, Position pos);
Position pop(Stack s);
bool is_empty(Stack s);
FILE *file;

Test_case case_array[BUFFER_SIZE]; //테스트케이스 배열


int main() {
    read_maze(); //미로 불러오고
    
    for(int r = 0; r < entry_count; r++){ //각 케이스당
        printf("미로 크기 출력:%d\n",case_array[r]->maze_size);
        case_array[r]->component_num = 0;
        for(int j =0; j < case_array[r]->maze_size; j++){
            for(int k = 0; k < case_array[r]->maze_size; k++){ //배열 검색
                if(case_array[r]->argument[j][k] == PATH){//첫 스택이 까만 색 일때
                (case_array[r]->component_num)++; //새로운 컴포넌트 하나 생성
                case_array[r]->component_arr = (int *)malloc(BUFFER_SIZE * sizeof(int));
                Stack s = create(); //포지션을 정의하는 스택하나 만들어주고
                Position cur; //항상 현재위치 표현
                cur.x = j;
                cur.y = k;
                while (1){
                    maze[cur.x][cur.y] = VISITED; //현재 위치 온거니 2로 변경
                    bool forwarded = false; //여덟 방향 중 성공하면 true 반환
                    for (int dir = 0; dir < 8; dir++){
                        printf("%d\n", dir);
                        if (moveable(cur, dir)){ //이동가능한지 판단
                            push(s,cur); //현재 나의 위치 push
                            printf("푸쉬한다");
                            case_array[r]->component_arr[case_array[r]->component_num]++; //component의 크기에 +1
                            cur = move_to(cur, dir); //현재위치를 다음 위치로 변경
                            forwarded = true; //전진할 수 있다.
                            printf("전진합니다\n");
                            break;
                        }
                    }
                    if (!forwarded){ //더이상 전진 할 수가 없다.면
                        maze[cur.x][cur.y] = BACKTRACKED; //현재가 갈 수 있는 마지막 위치이니 3으로 표시
                        if (is_empty(s)){ //만약에 그곳이 스택이 더이상없는 곳이다. 그러면 새로운 component 생성
                            break;
                            
                        }
                        cur = pop(s);
                        printf("한번 끝났습니다");
                    }
                    }
                }
            }
        }
    }
    print_maze();
return 0;
}

void read_maze(){
    file = fopen("input.txt", "r");
    if (file == NULL){
        printf("There is no file.");
        return;
    }
    else{
        printf("open file\n");
        fscanf(file,"%d ", &entry_count);
        for(int i = 0; i < entry_count; i++){
            case_array[num] = (Test_case)malloc(sizeof(Test_case));
            case_array[num] -> argument = (int **)malloc(BUFFER_SIZE * sizeof(int));
            for(int j = 0; j<BUFFER_SIZE; j++){
                case_array[num] -> argument[j] = (int *)malloc(BUFFER_SIZE * sizeof(int));
            }
            fscanf(file, "%d ", &case_array[num] -> maze_size);
                for (int j = 0; j < case_array[num] -> maze_size; j++){
                    for (int k = 0; k < case_array[num] -> maze_size; k++){
                        fscanf(file,"%d ", &case_array[num]->argument[j][k]);
                    }
                }
                num++;
        }
    }
    printf("success read\n");
    printf("미로 크기 출력:%d\n",case_array[0]->maze_size);
    printf("미로 크기 출력:%d\n",case_array[1]->maze_size);
    printf("미로 크기 출력:%d\n",case_array[2]->maze_size);
    fclose();
}

void print_maze(){
    for(int i = 0; i< entry_count; i++){
        for(int j = 1; j<case_array[i]->component_num+1; j++){
            printf("%d  ", case_array[i]->component_arr[j]);
        }
        printf("\n");
    }
}

bool moveable(Position pos, int dir){
    Position move_can = move_to(pos, dir);
    if (maze[move_can.x][move_can.y] == PATH){
        return true;
    }
    else{
        return false; 
    }
}

Stack create(){
    Stack s = (Stack)malloc(sizeof(struct stack_type));
        s->top = -1;
        s->size = INIT_CAPACITY;
        return s;
}


void initStack(Stack s){
    s->top = -1;
    s->size = 0;
}

bool is_empty(Stack s){
    if (s->top < 0) {
        return true;
    }
    return false;
}

void push(Stack s, Position pos){
        s->top++;
        s->size++;
        s->pos[s->top] = pos;
}

Position pop(Stack s){
    s->top--;
    Position tmp = s->pos[s->top];
    

    return tmp;
}

int offset[8][2] = {  //동서남북 방향
    {-1,0}, //북
    {-1,1}, //북동
    {0,1},  //동 
    {-1,1},  //동남
    {1,0},  //남
    {1,-1},  //서남
    {0,-1}, //서
    {-1,-1}  //서북
};

Position move_to(Position pos, int dir) {
    Position next;
    next.x = pos.x + offset[dir][0];
    next.y = pos.y + offset[dir][1];
    return next;
}


