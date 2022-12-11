#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define BUFFER_SIZE 99999999

void open_file();
void organize_file();
void calculate();
void create_case();
FILE * file;

typedef struct data_case{ //data_case 구조체
    int index;            //배열 갯수
    int *argument; //배열 저장
    long long huristic;
} *Data_case;

Data_case case_array[BUFFER_SIZE]; //Data_case 배열

int n; //전체 테스트케이스 갯수
int num =0; //테스트케이스 배열
int m = 0; //h함수 구하기 위한 정수

int main(){
    clock_t start = clock();
    open_file();
    num = 1;

    calculate();
    
    fclose(file);
      clock_t end = clock();
      printf("Elapsed Time: %lf\n", (double)(end - start)/ CLOCKS_PER_SEC);
    return 0;
}

void open_file(){
    file = fopen("input.txt", "r");
    if (file == NULL){
        printf("There is no file.");
        return;
    }
    else{
        printf("open file\n");
        organize_file();
        
    }
}

void organize_file(){
    //printf("organize success\n");
    fscanf(file,"%d ", &n);
    for(int i=0; i<n; i++){
        //printf("%d,  %d\n",n,i);
        num++;
        case_array[num] = (Data_case)malloc(sizeof(Data_case));
        case_array[num]->argument = (int *)malloc(BUFFER_SIZE * sizeof(int));
        fscanf(file,"%d ", &case_array[num]->index);
        //printf("%d\n ", case_array[num]->index);
        //create_case();
        for(int j=0; j<case_array[num]->index; j++){
            fscanf(file,"%d ", &case_array[num]->argument[j]);
        }
        //printf("%d\n ", case_array[num]->index);
        //printf("%d-finished\n",i);
    }
    printf("open_file finished\n");
    

}


void calculate(){
    for(int i = 1; i <= n; i++){
        
        long long sum = 0;
        int max_index = 0;
        
        for(int j = 0; j < (case_array[i]->index); j++){
        int tmp = 1;
        if(case_array[i]->argument[j] >= case_array[i]->argument[max_index]){
            max_index = j;
            sum = sum + j;
        }
        else{
            
                while(case_array[i]->argument[j] >= case_array[i]->argument[j-tmp]){
                        
                        sum = sum + 1;
                        tmp++;
                    }
            }
        }
    printf("%d : %lld\n", i, sum%1000000); //출력하기     
     }
    
}
