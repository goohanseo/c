#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 200

void compress(char *str);

int main(){
    int m,n;
    char *table[10][10]; //각문자열들의 주소 저장이니까 포인터

    char line[MAX];
    FILE *fp = fopen("table.txt", "r");
    fscanf(fp,"%d%d ",&m,&n); //가짜라인 없애기 스페이스로 한칸 띄어서 한 칸 먹기
    for (int i=0; i<m; i++){
        fgets(line, MAX, fp);
        if(line[strlen(line)-1] == '\n')
        line[strlen(line)-1] = '\0'; //라인의 줄바꿈 문자 NULL로 바꾸기
        //printf("%s\n",line);

        char *p = strtok(line, "&");
        table[i][0] = strdup(p);
        for(int j=1; j<n; j++){ //총 몇갠지 알기 때문에 첫 단어 그 이후로 총 4개 저장함
            p = strtok(NULL, "&");
            table[i][j] = strdup(p);
        }
    }
    fclose(fp);

    for(int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            compress(table[i][j]);
        }
    }

    int colwidth[10];
    for (int j=0; j<n; j++){
        colwidth[j] = strlen(table[0][j]);
        for (int i=1; i<m; i++){
            if (strlen(table[i][j])>colwidth[j]){
                colwidth[j] = strlen(table[i][j]);
            }
        }
    }
    FILE *of = fopen("output.txt","w");
    for(int i=0; i<m; i++){
        for(int j=0; i<n; j++){
            fprintf(of,"%s",table[i][j]);
            for(int k=0; k<=colwidth[j]-strlen(table[i][j]); k++) //공백칸 출력
            fprintf(of," ");
        }
        fprintf(of,"\n");
    }
       fclose(of);
    return 0;
}

void compress(char *str){ //배열을 새로 잡아서 옮기는데 그러지 않고 그 배열에 다시 대입
    int s = 0; //저장할 자식
    for (int i=0; i<strlen(str); i++){
        if (!isspace(str[i]) ||//만약 살아남아야된다면 //앞쪽 공백 다 사라짐
        i>0 && !isspace(str[i-1]) ){ //i가 0이면 안 됨
        str[s++] = str[i];
        }
    }
    if (s>0 && isspace(str[s-1]))//마지막으로 살아남은 문자
    str[s-1] = '\0';
    else
    str[s] = '\0';
}