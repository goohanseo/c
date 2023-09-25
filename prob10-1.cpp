#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100
#define PATH 0
#define HORSE 1
#define VISITED 2

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

int N=0;
int maze[MAX][MAX];
bool solution = false;
void read_maze();
void print_maze();
void possible_path(int x, int y);
typedef struct point{
    int x;
    int y;
}point;

point start;
point end;

int main(){
    read_maze();
    print_maze();
    possible_path(start.x, start.y);
    if(!solution){
        printf("No!\n");
    }
    return 0;
}

void possible_path(int x, int y){
    if (x == end.x && y == end.y){
        solution = true;
        printf("Yes!\n");
        return;
    }
    for (int z = 1; z <= 4; z++){
        if (z == 1){
            for (int q = y - 1; q >= 0; q--){
                if (maze[x][q] == HORSE && maze[x][q + 1] != HORSE && maze[x][q - 1] != HORSE){
                    for (int t = q - 1; t >= 0; t--){
                        int new_y = t;
                        if (maze[x][new_y] == PATH){
                            maze[x][new_y] = VISITED;
                            possible_path(x, new_y);
                            if (solution){
                                return;
                            }
                            maze[x][new_y] = PATH;
                        }
                    }
                    break;
                }
            }
        }
        else if (z == 2){
            for (int q = x + 1; q < N; q++){
                if (maze[q][y] == HORSE && maze[q - 1][y] != HORSE && maze[q + 1][y] != HORSE){
                    for (int t = q + 1; t < N; t++){
                        int new_x = t;
                        if (maze[new_x][y] == PATH){
                            maze[new_x][y] = VISITED;
                            possible_path(new_x, y);
                            if (solution){
                                return;
                            }
                            maze[new_x][y] = PATH;
                        }
                    }
                }
            }
        }
        else if (z == 3){
            for (int q = y + 1; q < N; q++){
                if (maze[x][q] == HORSE && maze[x][q - 1] != HORSE && maze[x][q + 1] != HORSE){
                    for (int t = q + 1; t < N; t++){
                        int new_y = t;
                        if (maze[x][new_y] == PATH){
                            maze[x][new_y] = VISITED;
                            possible_path(x, new_y);
                            if (solution){
                                return;
                            }
                            maze[x][new_y] = PATH;
                        }
                    }
                    break;
                }
            }
        }
        else if (z == 4){
            for (int q = x - 1; q >= 0; q--){
                if (maze[q][y] == HORSE && maze[q + 1][y] != HORSE && maze[q - 1][y] != HORSE){
                    for (int t = q - 1; t >= 0; t--){
                        int new_x = t;
                        if (maze[new_x][y] == PATH){
                            maze[new_x][y] = VISITED;
                            possible_path(new_x, y);
                            if (solution){
                                return;
                            }
                            maze[new_x][y] = PATH;
                        }
                    }
                    break;
                }
            }
        }
    }
}
void read_maze(){
    int tmp;
	FILE* fp = fopen("input.txt", "r");
	if (fp == NULL) {
		printf("files not open");
        return;
	}
    fscanf(fp, "%d", &N);
        for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            fscanf(fp, "%d", &tmp);
            maze[i][j] = tmp;
        }
    }
    fscanf(fp, "%d", &tmp);
    start.x = tmp;
    fscanf(fp, "%d", &tmp);
    start.y = tmp;
    
    fscanf(fp, "%d", &tmp);
    end.x = tmp;
    fscanf(fp, "%d", &tmp);
    end.y = tmp;
    fclose(fp);
}

void print_maze(){
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            printf("%d ",maze[i][j]);       
        }
        printf("\n");
    }
    printf("%d %d ", start.x, start.y);
    printf("\n");
    printf("%d %d ", end.x, end.y);
}
