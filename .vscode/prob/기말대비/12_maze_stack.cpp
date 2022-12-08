#include <stdio.h>
#define MAX 100
#define PATH 0
#define WALL 1
#define VISITED 2
#define BACKTRACKED 3

//-------------------------stack.cpp 


//-------------------------pos.h
typedef struct pos{
    int x,y;
} Position;

Position move_to(Position pos, int dir);

//--------------------------main.cpp

int maze[MAX][MAX];
int n;

void read_maze();
void print_maze();
bool moable(POS pos, int dir);

int main(){
    read_maze();

    Stack s = create();
    Position cur;
    cur.x = 0;
    cur.y = 0;
    while(1){
        maze[cur.x][cur.y] = VISITED;
        if (cur.x == n-1 && cur.y == n-1){
            printf("Found the path.\n");
            break;
        }
        bool forwarded = false;
        for (int dir = 0; dir<4; dir++){
            if (movable(cur, dir)){
                push(s,cur);
                cur = move_to(cur,dir);
                forwarded = true;
                break; //for문을 벗어나는거임 동서남북 나뉘는
            }
        }
        if(!forwarded){
            maze[cur.x][cur.y] = BACKTRACKED;
            if(is_empty(s)){ //출발지로 되돌아온거임 길이 없음
                printf("No path exists.\n");
                break;
            }
            cur = pop(s);
        }
    }
    print_maze();
}

//-------------------------pos.cpp
int offst[4][2] = {
    {-1,0},
    {0,1},
    {1,0},
    {0,-1}
};

Position move_to(Position pos, int dir){
    Position next;
    next.x = pos.x + offset[dir][0];
    next.y = pos.y + offset[dir][1];
    return next;
}