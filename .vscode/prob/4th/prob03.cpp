//데이터 테스트 통과
#include <stdio.h>
#include <string.h>
#define BUFFER_SIZE 1000

FILE * file;
char *arr[BUFFER_SIZE][BUFFER_SIZE];
int blank[BUFFER_SIZE][BUFFER_SIZE];
char buffer[BUFFER_SIZE];
int i;
int n;
int m;
char *line[BUFFER_SIZE];

void open_file();
void read_file();
void sort();
void compress();
void gap();

void save_new_file();


int main(void){
    open_file();
    read_file();
    sort();
    gap();
    save_new_file();
    return 0;
}

void open_file(){
    file = fopen("table.txt","r");
    if (file == NULL){
        printf("There is no file.");
        return;
    }
    else{
        printf("Success\n");
        
    }
}

void read_file(){
    fscanf(file,"%d ",&n);
    fscanf(file,"%d ",&m);
    int i = 0;
        while(fgets(buffer, BUFFER_SIZE, file) != NULL){
            compress();
            line[i] = strdup(buffer);
            i++;
        }
        fclose(file);
}


void sort(){
for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
        if(j==0){
        arr[i][j] = strtok(line[i],"&");
        }
        else{
        arr[i][j] = strtok(NULL,"&");
        }
    }
}
}

void compress(){
    int n = 0;
    char tmp[BUFFER_SIZE];
    for (int i = 0; i < strlen(buffer); i ++){
        if (buffer[i] == ' ' && buffer[i + 1] == ' '){
        continue;
    }
    tmp[n++]=buffer[i];
}
tmp[n]=0;
strcpy(buffer,tmp);
}

void gap(){
    int longest = 0;

    for(int j = 0; j < m-1 ; j++){
        for(int i = 0; i < n ; i++){
            if(strlen(arr[i][j]) > longest){
                longest = strlen(arr[i][j]);
            }
        }
        for(int i = 0; i < n; i++){
            if (strlen(arr[i][j])<longest){
                blank[i][j] = longest - strlen(arr[i][j]);
            }
            else{
                blank[i][j] = 0;
            }
                printf("%d  ",blank[i][j]);
            }
        }
    }


// void gap(){
//     int longest;
//     int tmp;
//     for(int j = 0; j < m; j ++){
//         longest = 0;
//         for(int i = 0; i < n; i ++){
//             if(strlen(arr[i][j]) > longest){
//                 longest = strlen(arr[i][j]);
//                 tmp = longest;
//             }
//         }
//         printf("%d\n",tmp);
//         for(int i = 0; i < n; i ++){
//             while (strlen(arr[i][j]) < tmp) {
//                 strcat(arr[i][j], " ");
//             }
//         }
//     }
// }
void save_new_file(){
    FILE* output = fopen("output.txt", "w");
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            fputs(arr[i][j], output);
    }
}


    printf("\n");
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("%s",arr[i][j]);
            int tmp = blank[i][j];
            for(int k = 0; k<tmp; k++){
                printf(" ");
            }
        }
    }
}