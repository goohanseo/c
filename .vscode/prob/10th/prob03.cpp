#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 1000000

void open_file();
void organize_file();
void calculation();
void create_case();
FILE * file;
typedef struct data_case{
    int index;
    int argument[BUFFER_SIZE];
    int h[BUFFER_SIZE];
} *Data_case;
Data_case case_array[BUFFER_SIZE];
char buffer[BUFFER_SIZE];
int num = 0;
int n;
int m;
int main(){
    open_file();
    for(int i =0; i < n; i++){
        calculation();
    }
}

void open_file(){
    file = fopen("input.txt","r");
    if (file == NULL){
        printf("There is no file.");
        return;
    }
    else{
        organize_file();
    }
}

void organize_file(){
    fscanf(file,"%d", &n);
    int i =0;
    while(fgets(buffer, BUFFER_SIZE, file) != NULL){
        if(i%2==0){
            create_case();
        }
        else{
            for(int j=0; j<case_array[num]->index; j++){
                if (j==0){
                    case_array[num]->argument[j] = atoi(strtok(buffer, " "));
                }
                else {
                    case_array[num]->argument[j] = atoi(strtok(NULL, " "));
                }
                num++;
            }
        }
    }
}

void create_case(){
    case_array[num] = (Data_case)malloc(sizeof(Data_case));
    case_array[num]->index = atoi(strdup(buffer));
}

void calculation(){
    int tmp = 0;
    for(int j = case_array[m]->index; j > 0; j--){
        int k = 0;
        while(case_array[m]->argument[j]>=case_array[m]->argument[j-k] || j != 0){
            tmp++;
            k--;
        }
    }
    printf("%d\n", tmp%1000000);
    m++;
}

//나보다 뒤에가 크면 나부터 시작해서 k++ 하는데 
//while(arr[i]=<arr[j]
//k++ 
//h(i+k)=k
//k=0;