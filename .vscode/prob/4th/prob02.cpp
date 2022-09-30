//데이터 테스트 통과
#include <stdio.h>
#include <string.h>
#include <math.h>
#define BUFFER_SIZE 100

FILE * file;
int arr[BUFFER_SIZE][BUFFER_SIZE];
double sum;
double tmp;
double avg1[BUFFER_SIZE];
double avg2[BUFFER_SIZE];
double root1[BUFFER_SIZE];
double root2[BUFFER_SIZE];
void open_file();
void read_file();
void average();
void std_dev();
int n;

 
int main(void){
    open_file();
    read_file();
    average();
    std_dev();
    for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                printf("%d      ", arr[i][j]);
            }
            printf("%.2f  ",avg1[i]);
            printf("%.2f  ",sqrt(root1[i]));
            printf("\n");
        }
    for(int i = 0; i < n; i++){
        printf("%.2f ", avg2[i]);
    }
    printf("\n");
    for(int i = 0; i < n; i++){
        printf("%.2f  ", sqrt(root2[i]));
    }
  
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
        sum = 0;
        for(int j = 0; j < n; j++){
            sum = sum + arr[i][j];
        }
        avg1[i] = sum/n;       
    }
     for(int j = 0; j < n; j++){
        sum = 0;
        for(int i = 0; i < n; i++){
            sum = sum + arr[i][j];
        }
        avg2[j] = sum/n;      
    }
}

void std_dev(){
    sum = 0;
    for(int i = 0; i < n; i++){
        tmp = 0;
        for(int j = 0; j < n; j++){
             tmp = (arr[i][j]-avg1[i]);
             tmp = tmp*tmp;
             sum = sum + tmp;
             tmp = 0;
        }
        sum = sum/n;
        root1[i] = sum;
        sum = 0;
    }
    sum = 0;
    for(int j = 0; j < n; j++){
        tmp = 0;
        for(int i = 0; i < n; i++){
             tmp = (arr[i][j]-avg2[j]);
             tmp = tmp*tmp;
             sum = sum + tmp;
             tmp = 0;
        }
        sum = sum/n;
        root2[j] = sum;  
        sum = 0;  
    }
}