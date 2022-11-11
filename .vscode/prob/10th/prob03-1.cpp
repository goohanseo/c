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
    long argument[BUFFER_SIZE]; //배열 저장
} *Data_case;

Data_case case_array[BUFFER_SIZE]; //Data_case 배열
int n; //전체 테스트케이스 갯수
int num =0; //테스트케이스 배열
int m = 0; //h함수 구하기 위한 정수
int tmp_index = 0; //각 테스트케이스당 인자 갯수

int main(){
    open_file();
    for(int i = 0; i < n; i++){
        calculate();
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
        fclose(file);
    }
}

void organize_file(){
    printf("organize success\n");
    fscanf(file,"%d ", &n);
    for(int i=0; i<n; i++){
        printf("%d,  %d\n",n,i);
        tmp_index = 0;
        fscanf(file,"%d ", &tmp_index);
        create_case();
        for(int j=0; j<tmp_index; j++){
            int tmp_argument = 0;
            fscanf(file,"%d ", &tmp_argument);
            case_array[num]->argument[j] = tmp_argument;
        }
        num++;
    }
}

void create_case(){
    case_array[num] = (Data_case)malloc(sizeof(Data_case));
    case_array[num]->index = tmp_index;
    printf("%d  ", case_array[num]->index);
    printf("create success\n");
}

void calculate(){
    int tmp = 0; 
    for(int j = (case_array[m]->index)-1; j >= 0; j--){ //구조체 index값만큼 뒤에서부터 검사
        int k = 1; 
        while(case_array[m]->argument[j]>=case_array[m]->argument[j-k] && j-k >= 0){ //현재 배열보다 앞 배열이 작으면 tmp++
            tmp++; //argument[index]~[0] 다 더하고 
            k++;
        }
    } 
    printf("%d\n", tmp%1000000); //출력하기
    m++;
}
