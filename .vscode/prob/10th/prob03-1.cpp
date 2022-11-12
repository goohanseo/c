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
    num =1;
    for(int i = 0; i < n; i++){
         calculate();
        num++;
    }
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
    //printf("%d\n",(case_array[num]->index));
    long long k =0 ;
    int max_index = 0;
    case_array[num]->huristic = 0;

    for(int j = 0; j < (case_array[num]->index); j++){
        if(case_array[num]->argument[j] >= case_array[num]->argument[max_index]){
            max_index = j;
            case_array[num]->huristic = case_array[num]->huristic + j;
        }
        else(){
            for(int i = j; i > max_index; i--){

            }
        }
    }




    //for(int j = 0; j < (case_array[num]->index); j++)
    int j = 0;
    while(j <(case_array[num]->index)){ //구조체 index값만큼 뒤에서부터 검사
        if(j == 0){
            k = 0;
            case_array[num]->huristic = case_array[num]->huristic + k;
            j++;
        }
        else if(j != 0 && (case_array[num]->argument[j] >= case_array[num]->argument[j-1])){
            k = k + 1;
            case_array[num]->huristic = case_array[num]->huristic + k;
            j++;
        }
        else if(j != 0 && (case_array[num]->argument[j] < case_array[num]->argument[j-1])){
            k = 0;
            case_array[num]->huristic = case_array[num]->huristic + k;
            j++;
            break;
        }
    }
printf("%d : %lld\n", num, case_array[num]->huristic%1000000); //출력하기
}
