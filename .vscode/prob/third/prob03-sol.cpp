#include <stdio.h>
#include <string.h>

#define LINE_LENGTH 10000
#define MAX 10000
char *words[MAX];
char *exp[MAX];
int n;

int main(){

    char line[LINE_LENGTH];
    FILE *fp = fopen("shuffled_dict.txt", "r");

    while(fgets(line, LINE_LENGTH,fp) != NULL){
        if (line[strlen(line)-1] == '\n'){
        line[strlen(line)-1] = '\0'; //\n->\0로 변경됨
    }
    if (strlen(line) <= 0)
    continue;
    
    
    //tokenizing
    char *p = strtok(line, "\t"); //구분자는 무조건 문자열이어야 하기때문에 ""
    words[n] = strdup(p);
    p = strtok(NULL, "\t");
    exp[n++] = strdup(p); //n값을 증가시켜주면 다음 words[n]이 증가된 값
    }
    fclose(fp);

    for (int i =0; i<n; i++){
        printf("%s   %s\n", words[i], exp[i]);
    }
    return 0;
}

