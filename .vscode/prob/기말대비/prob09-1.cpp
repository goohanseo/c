#include <stdio.h>
#define MAX 100

int N;
int brd[MAX][MAX];
int stack[10000];
int top = -1;

void read_board(FILE * fp){
    fscanf(fp, "%d", &n);
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            fscanf(fp, "%d", &brd[i][j]);
}

void push(int x){
    top++;
    stack[top] = x;
}

int pop(){
    top--;
    return stack[top+1];
}

int is_empty(){
    return top ==-1;
}

void clear_stack(){
    top = -1;
}

void solve_instance();
int count_cells(int, int);

int maini(){
    int T;
    FILE *fp = fopen("input.txt","r");
    fscanf(fp, "%d", %T);
    for (int t=0; t<T; t++){
        read_board(fp);
        solve_instance();
        clear_stack();
    }
    fclose(fp);
}

void solve_instance(){
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (brd[i][j] != 1)
                continue;
            int size = count_cells(i,j);
            printf("%d ", size);
            clear_stack();
        }
    }
    printf("\n");
}

int offset[8][2] = { {-1, 0},
                     {-1, 1},
                     {0, 1},
                     {1, 1},
                     {1, 0},
                     {1, -1},
                     {0, -1},
                     {-1, -1}};

bool movable(int x, int y, int dir)
{
    x += offset[dir][0];
    y += offset[dir][1];
    return (x >= 0 && x < N && y >= 0 && y < N && brd[x][y] == 1);
}

int count_cells(int x, int y){
    int init_dir = 0;
    int count = 1;
    while(1){
        brd[x][y] = 2;
        bool forwarded = false;
        for (int d=init_dir; d<8; d++){
            if(movable(x,y,d)){
                push(d);
                count++;
                x += offset[d][0];
                y += offset[d][1];
                init_dir = 0;
                forwarded = true;
                break;
            }
        }
    if (!forwarded) {
            if (is_empty()) //다시 처음으로 돌아온것이지 count return
                return count;
            int d = pop();
            x -= offset[d][0];
            y -= offset[d][1];
            init_dir = d+1;
        }
    }
    return -1;
}