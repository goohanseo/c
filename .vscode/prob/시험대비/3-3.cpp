#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINE_LENGTH 1000
#define MAX 10000
char *words[MAX];
char *exp[MAX];
int n=0;


int main(){
    char line[LINE_LENGTH];
    FILE *fp = fopen("shuffled_dict.txt", "r");
    while(fgets(line, LINE_LENGTH,fp) != NULL){ //배열의 길이 //맨마지막 없애줌 NULL이라
        if(line[strlen(line)-1] == '\n') //파일의 마지막 부분 깨끗하게 만들어주기
            line[strlen(line)-1] = '\0'; //\0이 되버리니까 알아서 그전까지로 c언어가 인식
        
        if (strlen(line) <= 0) 이 라인은 그냥 끝내버리고 다시 while문 시작
        continue;
    

    char *p = strtok(line, "\t"); //문자열이기때문에 무조건 ""
    
    
    int j = n-1; //맨마지막부터 앞으로 훑어가면 옴
    while(j>=0 && strcmp(words[j],p)>0){
        words[j+1] = words[j];
        exp[j+1] = exp[j];
        j--; //j--해줘야 무한루프 끝남 사전식 배열 정리
    }
    words[j+1] = strdup(p);
    p = strtok(NULL, "\t");
    exp[j+1] = strdup(p); //n값을 증가시켜주면 다음 words[n]이 증가된 값
    n++;
    } //한단어에 대한 실행 끝
fclose(fp);

  for (int i =0; i<n; i++)
        printf("%s  %s\n", words[i], exp[i]);
    
    return 0;
}
