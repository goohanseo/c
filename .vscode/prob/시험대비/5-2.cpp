//데이터 테스트 통과
#include <stdio.h>
#include <string.h>
#define BUFFER_SIZE 100
//scanf(%s)
//scanf(%d 화이트 스페이스)

FILE * file;
int arr[BUFFER_SIZE][BUFFER_SIZE];
int n;

void open_file();
void read_file();
void process_command();
void show();
void colmax();
void colmin();
void rowmax();
void rowmin();
void slice();

int main(void){
    open_file();
    read_file();
    process_command();
    return 0;
}

void open_file(){
    file = fopen("data.mat","r");
    if (file == NULL){
        printf("There is no file.");
        return;
    }
    else{
        printf("Success\n");
    }
}

void read_file(){
    fscanf(file,"%d",&n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            fscanf(file,"%d",&arr[i][j]);
        }
    }
}

void process_command(){
    char buffer[BUFFER_SIZE];

    while(1){
    printf("$ ");
    scanf("%s",buffer);
    if (strcmp(buffer,"show") == 0){
        show();
    }

    else if (strcmp(buffer, "colmax") == 0){
        colmax();
    }

    else if (strcmp(buffer, "colmin") == 0){
        colmin();
    }

    else if (strcmp(buffer, "rowmax") == 0){
        rowmax();
    }
    
    else if (strcmp(buffer, "rowmin") == 0){
        rowmin();
    }

    else if (strcmp(buffer, "slice") == 0){
        slice();
    }

    else if (strcmp(buffer, "exit") == 0)
    break;
}
}

void show(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}

void colmax(){
    for(int j = 0; j < n; j++){
        int max = arr[0][j];
        for(int i = 0; i < n; i++){
            if (max < arr[i][j]){
                max = arr[i][j];
            }
        }
        printf("%d ", max);
    }
    printf("\n");
}

void colmin(){
    for(int j = 0; j < n; j++){
        int min = arr[0][j];
        for(int i = 0; i < n; i++){
            if (min > arr[i][j]){
                min = arr[i][j];
            }
        }
        printf("%d ", min);
    }
    printf("\n");
}

void rowmax(){
    int i = 0;
    int j = 0;
    for(int i = 0; i < n; i++){
        int max = arr[i][0];
        for(int j = 0; j < n; j++){
            if (max < arr[i][j]){
                max = arr[i][j];
            }
        }
            printf("%d ", max);
    }
    printf("\n");
}

void rowmin(){
    for(int i = 0; i < n; i++){
        int min = arr[i][0];
        for(int j = 0; j < n; j++){
            if (min > arr[i][j]){
                min = arr[i][j];
            }
        }
        printf("%d ", min);
    }
    printf("\n");
}



void slice(){
    int x, p, y, q;
    scanf("%d%d%d%d",&x,&p,&y,&q); //for(int i=x; i<n; i+=q)
    for(int i = 0; i < n; i++){
        int xx = x + (i*p);
        for(int j = 0; j < n; j++){
            int yy = y + (j*q);
            if(xx < n && yy < n){
            printf("%d ",arr[xx][yy]);
            }
        }
        printf("\n");
    }
}