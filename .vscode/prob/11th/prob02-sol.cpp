#include <stdio.h>
#define MAX 100

int N;
int brd[MAX][MAX];

typedef struct pos {
    int x, y;
} Pos;

Pos queue[10000];
int front = 0, rear = -1;
int capacity = 10000;
int size = 0;

void enqueue(Pos x)
{
    rear = (rear + 1)%capacity;
    queue[rear] = x;
    size++;
}

Pos dequeue(){
    Pos val = queue[front];
    front = (front+1)%capacity;
    size--;
    return val;
}

bool is_empty()
{
    return size==0;
}

bool clear_queue()
{
    size = 0;
    front = 0;
    rear = -1;
}

void read_board(FILE * fp)
{
    fscanf(fp, "%d", &N);
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            fscanf(fp, "%d", &brd[i][j]);
}

void solve_instance();
int count_cells(Pos);
int main()
{
    int T;
    FILE *fp= fopen("input.txt", "r");
    fscanf(fp, "%d", &T);
    for (int t=0; t<T; t++) {
        read_board(fp);
        solve_instance();
    }
    fclose(fp);
}

void solve_instance() {
    Pos start;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (brd[i][j] != 1)
                continue;
            start.x = i; start.y = j;
            int size = count_cells(start);
            printf("%d ", size);
            clear_queue();
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

Pos move(Pos c, int d) {
    Pos q;
    q.x = c.x + offset[d][0];
    q.y = c.y + offset[d][1];
    return q;
}

bool feasible(Pos p) {
    return (p.x >= 0 && p.x < N && p.y >= 0 && p.y < N && brd[p.x][p.y] == 1);

}

int count_cells(Pos s) {
    int count = 1;
    enqueue(s);
    brd[s.x][s.y] = 2;
    while(!is_empty()) {
        Pos cur = dequeue();
        for (int d=0; d<8; d++) {
            Pos p = move(cur, d);
            if (feasible(p)) {
                brd[p.x][p.y] = 2;
                enqueue(p);
                count++;
            }
        }
    }
    clear_queue();
    return count;
}