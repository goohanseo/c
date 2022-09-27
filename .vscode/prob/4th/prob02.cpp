#include <stdio.h>
#include <string.h>
#include <math.h>
#define BUFFER_SIZE 100

FILE * file;
int arr[BUFFER_SIZE][BUFFER_SIZE];
int sum;
int avg[BUFFER_SIZE][BUFFER_SIZE];
int k;
void open_file();
void read_file();
void average();
void std_dev();

int main(void){
    open_file();
    read_file();
    for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                printf("%d  ",arr[i][j]);
            }
            printf("\n");
        }
    avg[i][j]=arr[i][j]
    // for(int i = 0; i < row; i ++){
    // avg();
    // std_dev();
    // printf("%d",avg);
    // printf("%d",std_dev);
}

void open_file(){
    file = fopen("input.txt","r");
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
                fscanf(file, "%d", &arr[i][j]);
            }
        }
    }

void average(){
    for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                sum = 0;
                sum = sum + arr[i][j];
    }
    avg[n][i] = sum/4;
    }
    for(int j = 0; j < n; j++){
            for(int i = 0; i < n; i++){
                sum = 0;
                sum = sum + arr[i][j];
    }
    avg[j][n] = sum/4;
    }
    }