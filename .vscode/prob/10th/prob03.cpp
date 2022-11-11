#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 1000000

void open_file(); 
void organize_file();
void calculation();
void create_case();
FILE * file;
typedef struct data_case{ //data_case 구조체
    int index;            //배열 갯수
    int argument[BUFFER_SIZE]; //배열 저장
    int h[BUFFER_SIZE]; //h배열 저장
} *Data_case;
Data_case case_array[BUFFER_SIZE]; //Data_case 배열
char buffer[BUFFER_SIZE];
int num = 0;
int n;
int m=0;
int main(){
    open_file();                //파일 열어주고
    for(int i =0; i < n; i++){ //n개의 구조체에 대하여 계산하기
        calculation();
    }
}

void open_file(){              //파일 열어주고
    file = fopen("input.txt","r");
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
    fscanf(file,"%d ", &n);  //총 몇개 테스트 필요한지 받아오고
    int i =0;
    while(fgets(buffer, BUFFER_SIZE, file) != NULL){  //한줄식 받아오기
        if(i%2==0){                //i가 짝수일때는 각 테스트의 인자갯수 알려줌
            create_case();         //구조체 생성
        }
        else{
            for(int j=0; j<case_array[num]->index; j++){ //index 만큼의 인자값 받아오기
                if (j==0){                              
                    case_array[num]->argument[j] = atoi(strtok(buffer, " "));  //argument[0]은 strtok buffer
                }
                else {                  
                    case_array[num]->argument[j] = atoi(strtok(NULL, " ")); //나머지는 NULL
                }
                num++;                                   //다음 구조체 배열로 넘어가기 위해 num++
            }
        }
        i++; //index와 argument를 포함해야되니까 두줄마다 i++
    }
}

void create_case(){
    case_array[num] = (Data_case)malloc(sizeof(Data_case)); //구조체 하나 생성해주고
    case_array[num]->index = atoi(strdup(buffer)); //buffer로 받은 정수 index에 삽입해줌
}

void calculation(){
    int tmp = 0; 
    for(int j = case_array[m]->index-1; j >= 0; j--){ //구조체 index값만큼 뒤에서부터 검사
        int k = 1; 
        while(case_array[m]->argument[j]>=case_array[m]->argument[j-k] && j >= 0){ //현재 배열보다 앞 배열이 작으면 tmp++
            tmp++; //argument[index]~[0] 다 더하고 
            k++;
        }
    } 
    printf("%d\n", tmp%1000000); //출력하기
    m++;
}


fscanf(file,%d, %n)
for(int i =0; i < n; i++){
    fscanf("%d",%m);
    for(int i = 0; i < n; )
}