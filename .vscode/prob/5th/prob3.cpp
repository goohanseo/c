//데이터 테스트 통과
#include <stdio.h>
#define BUFFER_SIZE 100

void open_file();
void read_file();
void play_game();
void count_col();
void count_row();
void count_dia_right();
void count_dia_left();
bool Finish1 = false;
bool Finish2 = false;
int arr[BUFFER_SIZE][BUFFER_SIZE];
int n;
FILE * file;

int main(void){
    open_file();
    read_file();
    play_game();
    if (Finish1 == true){
        printf("black");
    }
     if (Finish2 == true){
        printf("white");
    }
    if (Finish1 == false && Finish2 == false){
        printf("Not Finished");
    }
    return 0;
}

void open_file(){
    file = fopen("board.txt","r");
    if (file == NULL){
        printf("There is no file.");
        return;
    }
    else{
    }
}

void read_file(){
    fscanf(file, "%d", &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            fscanf(file, "%d", &arr[i][j]);
        }
    }
}


void play_game(){
    count_col();
    count_row();
    count_dia_right();
    count_dia_left();
}

void count_col(){
    for(int j = 0; j < n; j++){
        for(int i = 0; i < n-5; i++){
            if(arr[i][j] == 1 && arr[i+1][j] == 1 && arr[i+2][j] == 1 
            && arr[i+3][j] == 1 && arr[i+4][j] == 1 ){
            //printf("black");
            Finish1 = true;
            }
            else if(arr[i][j] == 2 && arr[i+1][j] == 2 && arr[i+2][j] == 2 
            && arr[i+3][j] == 2 && arr[i+4][j] == 2 ){
            //printf("white");
            Finish2 = true;
            }
            else{
            }
        }
    }    
}

void count_row(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-5; j++){
            if(arr[i][j] == 1 && arr[i][j+1] == 1 && arr[i][j+2] == 1 
            && arr[i][j+3] == 1 && arr[i][j+4] == 1 ){
            if(Finish1)
            //printf("black");
            Finish1 = true;
            }
            else if(arr[i][j] == 2 && arr[i][j+1] == 2 && arr[i][j+2] == 2 
            && arr[i][j+3] == 2 && arr[i][j+4] == 2 ){
            //printf("white");
            Finish2 = true;
            }
            else{
            }
        }
    }    

}

void count_dia_right(){
    for(int i = 0; i < n-4; i++){
        for(int j = 0; j < n-5; j++){
            if(arr[i][j] == 1 && arr[i+1][j+1] == 1 && arr[i+2][j+2] == 1 
            && arr[i+3][j+3] == 1 && arr[i+4][j+4] == 1 ){
            //printf("black");
            Finish1 = true;
            }
            else if(arr[i][j] == 2 && arr[i+1][j+1] == 2 && arr[i+2][j+2] == 2 
            && arr[i+3][j+3] == 2 && arr[i+4][j+4] == 2 ){
            //printf("white");
            Finish2 = true;}
            else{
            }
        }
    }
}

void count_dia_left(){
    for(int i = 0; i < n-4; i++){
        for(int j = n; j > 4; j--){
            if(arr[i][j] == 1 && arr[i+1][j-1] == 1 && arr[i+2][j-2] == 1 
            && arr[i+3][j-3] == 1 && arr[i+4][j-4] == 1 ){
            //printf("black");
            Finish1 = true;
            }
            else if(arr[i][j] == 2 && arr[i+1][j-1] == 2 && arr[i+2][j-2] == 2 
            && arr[i+3][j-3] == 2 && arr[i+4][j-4] == 2 ){
            //printf("white");
            Finish2 = true;}
            else{
            }
        }
    }
}