//테스트 데이터 통과
#include <stdio.h>

#define MAX 100
#define PATH 0
#define WALL 1
#define VISITED 2
#define BACKTRACKED 3

int maze[8][8]={
    {0,0,0,0,0,0,0,1},
    {0,1,1,0,1,1,0,1},
    {0,0,0,0,0,0,1,1},
    {0,1,0,0,1,1,0,0},
    {0,1,1,1,0,0,0,1},
    {0,1,0,0,0,1,0,1},
    {0,0,0,1,0,0,0,1},
    {0,1,1,1,0,1,0,0},
};
int N = 8;
int count=0;
int findMazePath(int x, int y);
int offset[4][2] = {
    {-1,0},
    {0,1},
    {1,0},
    {0,-1}
};
bool movable(int x, int y, int dir);

int main(){
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            printf("%d ",maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");    
    findMazePath(0,0);
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            printf("%d   ",findMazePath(i,j));
        }
        printf("\n");
    }
    printf("%d",findMazePath(0,0));
}

int findMazePath(int x, int y){
    if (x < 0 || y < 0 || y >= N || x>= N || maze[x][y] != PATH ){
        return 0;
    }
    else if (x==N-1 && y==N-1){
        return 1;
    }
    else {
        maze[x][y] = VISITED; 
        for(int d = 0; d<4; d++){
                x += offset[d][0];
                y += offset[d][1];
                findMazePath(x,y);
                }
        }
        count = findMazePath(x-1,y) + findMazePath(x,y+1)
        +findMazePath(x+1,y) +findMazePath(x,y-1);
        maze[x][y] = PATH;
        return count;
    }

bool movable(int x, int y, int dir)
{
    x += offset[dir][0];
    y += offset[dir][1];
    if(x >= 0 && y >= 0 && y < N && x < N && maze[x][y]==0){
        return true;
    }
    return false;
}