#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 99999999

void open_file();
void organize_file();
void calculate();
void create_case();
FILE * file;

typedef struct data_case{ //data_case 구조체
    int index;            //배열 갯수
    int *argument; //배열 저장
} *Data_case;

Data_case case_array[BUFFER_SIZE]; //Data_case 배열

int n; //전체 테스트케이스 갯수
int num =0; //테스트케이스 배열
int m = 0; //h함수 구하기 위한 정수

int main(){
    open_file();
    for(int i = 0; i < n; i++){
        printf("nowfinished\n");
        calculate();
        m++;
    }
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
        printf("%d\n ", case_array[num]->index);
        printf("%d-finished\n",i);
    }
    
    fclose(file);
}

// void create_case(){
//     // ++num;
//     // case_array[num] = (Data_case)malloc(sizeof(Data_case));
//     case_array[num]->index = case_array[num]->index;
//     printf("%d-", case_array[num]->index);
//     printf("create\n");
//     }

void calculate(){
    int tmp = 0; 
    for(int j = (case_array[m]->index)-1; j >= 0; j--){ //구조체 index값만큼 뒤에서부터 검사
        int k = 1; 
        while((case_array[m]->argument[j])>=(case_array[m]->argument[j-k]) && j-k >= 0){ //현재 배열보다 앞 배열이 작으면 tmp++
            tmp++; //argument[index]~[0] 다 더하고 
            k++;
        }
    } 
    printf("%d\n", tmp%1000000); //출력하기
}
