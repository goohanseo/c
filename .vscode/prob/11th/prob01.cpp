//테스트 데이터 통과
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "pos.h" //stackADT.c 

#define MAX 100
#define WALL 0
#define PATH 1
#define VISITED 2 //green
#define BACKTRACKED 3 //yellow
#define BUFFER_SIZE 10000

int maze[MAX][MAX];
int m; //전체 테스트케이스 갯수
int n; //테스트케이스 내 가로세로 크기
int num = 0; //테스트케이스 갯수
int tmp = 0; //componenet들의 갯수 배열
void read_maze(); //테스트 불러오기
void print_maze(); //테스트 케이스당 컴포넌트 크기 출력
bool moable(POS pos, int dir); //다음으로 넘어갈 수 있는지 판단
FILE *file;

typedef struct test_case{ //테스트케이스 구조체
    int n; 
    int **argument; //이차원배열
    int component_num; //component 갯수
    int *component_arr; //각 component의 크기
} *Test_case;

Test_case case_array[BUFFER_SIZE]; //테스트케이스 배열


int main() {
    read_maze(); //미로 불러오고
    

    for(int i = 0; i < m; i++){ //각 케이스당
    num = 0 ;
        for(int j =0; j < case_array[i]->n; j++){
            for(int k = 0; k < case_array[i]->n; k++){ //배열 검색
                if(case_array[i]->argument[j][k] == 1){//첫 스택이 까만 색 일때
                (case_array[i]->component_num)++; //새로운 컴포넌트 하나 생성
                Stack s = create(); //포지션을 정의하는 스택하나 만들어주고
                Position cur; //항상 현재위치 표현
                cur.x = j;
                cur.y = k;
                int init_dir = 0; //처음 시도해볼 방향
                while (1){
                    maze[cur.x][cur.y] = VISITED; //현재 위치 온거니 2로 변경
                    bool forwarded = false; //여덟 방향 중 성공하면 true 반환
                    for (int dir = init_dir; dir < 8; dir++){
                        if (moable(cur, dir)){ //이동가능한지 판단
                            push(s,cur); //현재 나의 위치 push
                            case_array[i]->component_arr[tmp]++; //component의 크기에 +1
                            cur = move_to(cur, dir); //현재위치를 다음 위치로 변경
                            forwarded = true; //전진할 수 있다.
                            init_dir = 0; //전진했으니 다시 북쪽부터 검사
                            break;
                        }
                    }
                    if (!forwarded){ //더이상 전진 할 수가 없다.면
                        maze[cur.x][cur.y] = BACKTRACKED; //현재가 갈 수 있는 마지막 위치이니 3으로 표시
                        if (is_empty(s)){ //만약에 그곳이 스택이 더이상없는 곳이다. 그러면 새로운 component 생성
                            printf("new component");
                            
                            break;
                        }
                        int d = pop(s);
                        cur = move_to(cur, (d + 4) % 8);
                        init_dir = d + 1;
                    }
                    }
                }
            }
        }
        //케이스 데이터 출력
        for (int i = 0; i < case_array[i]->component_num; i ++){
            printf("%d ", case_array[i]->component_arr[i]);
            }
        tmp = 0;
    }

    //         bool forwarded = false; //네 방향중 성공하면 true 반환
    //         for (int dir = init_dir; dir < 4; dir++) { //n-0 e-1 s-2 w-3
    //         if (moable(cur, dir)) { //현재 위치에서 dir방향으로 이동 가능한지 범위 안에 들어오겠금 월도 아니게
    //             push(s.cur); //나의 현재 위치 push
    //             cur = move_to(cur, dir); //새로운 나의 좌표 cur
    //             forwarded = true; //이동에 성공하면 forwarded true
    //             init_dir = 0; //항상 0번 방향부터 시도해본다
    //             break;
    //         }
    //         }
    //         if (!forwarded) {
    //             maze[cur.x][cur.y] = BACKTRACKED; //왔다가 되돌아감
    //             if (is_empty(s)) { //스택이 비었다면 이전 위치 없음 출발점임 결국  원래 길이 없는 미로
    //                 printf("No path exists.\n");
    //                 break;
    //             }
    //         int d = pop(s);
    //         cur = move_to(cur, (d + 2) % 4);
    //         init_dir = d + 1;
    //     }
    // }
    print_maze();
}

void read_maze(){
    file = fopen("input.txt", "r");
    if (file == NULL){
        printf("There is no file.");
        return;
    }
    else{
        printf("open file\n");
        fscanf(file,"%d ", &m);
        for(int i = 0; i < m; i++){
            num++;
            case_array[num] = (Test_case)malloc(sizeof(Test_case));
            case_array[num] -> argument = (int **)malloc(BUFFER_SIZE * sizeof(int));
            for(int a = 0; i<BUFFER_SIZE; i++){
                case_array[num] -> argument[a] = (int *)malloc(BUFFER_SIZE * sizeof(int));
            }
            fscanf(file, "%d ", &case_array[num] -> n);
                for (int j = 0; j < case_array[num] -> n; j++){
                    for (int k = 0; k < case_array[num] -> n; k++){
                        fscanf(file,"%d ", &case_array[num]->argument[j][k]);
                    }
                }
        }
    }
}

void print_maze(){
    for(int i = 0; i< m; i++){
        for(int j = 0; j<case_array[i]->component_num; j++){
            printf("%d  ", case_array[i]->component_arr[j]);
        }
        printf("\n");
    }
}
//stack구현
//move 구현
//미흡한 부분 1. 되돌아온 위치 cur위치에서는 갔던 곳 다시 안 가도록
//2.위치가 아닌 방향값


//한바퀴 다 돌고 다시 돌아와서 처음위치에서 더이상 갈 곳이 없으면 새로운 그림
//movable 함수 만들기