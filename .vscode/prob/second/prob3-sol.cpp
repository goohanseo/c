#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char *words[5000];
    int counter[5000] = {0}; //컴파일 타임 0으로 초기화
    int n = 0;
    char buf[40];

    FILE *fp = fopen("harry.txt", "r");

    while(fscanf(fp,"%s",buf)!=EOF){ //f end of file 파일의 끝을 도달
    if (strlen(buf)<6){
        continue; //continue를 하게 되면 while loop 안 모두 뛰어넘음
    } 
    bool duplicate = false;//했는지 판단
    //EOF 미리 정의 되어 있는 매크로
    for(int i =0; i<n; i++){
        if (strcmp(buf, words[i]) == 0){
        duplicate = true;
        counter[i++];
        break;
    }
    }
    
    if(!duplicate){
        int j = n-1;
        while(j>=0 && strcmp(buf, words[j])<0){
            words[j+1] = words[j];
            counter[j+1] = counter[j];
            j--;
        }
        words[j+1] = strdup(buf);
        counter[j+1] = 1;
        n++;
    }
}

//개행문자까지 포함해서 출력함

    fclose(fp);

    for (int i=0; i<n; i++){
        
        printf("%s: %d\n", words[i],counter[i]);
        
        }
    printf("%d\n",n);
    return 0;
}