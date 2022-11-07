#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char *words[5000];
    int n = 0;
    char buf[40];

    FILE *fp = fopen("harry.txt", "r");

    while(fscanf(fp,"%s",buf)!=EOF){ //f end of file 파일의 끝을 도달
    bool duplicate = false;//했는지 판단
    //EOF 미리 정의 되어 있는 매크로
    for(int i =0; i<n; i++){
        if (strcmp(buf, words[i]) == 0){
        duplicate = true;
        break;
    }
    }
    
    if(!duplicate){
        int j = n-1;
        while(j>=0 && strcmp(buf, words[j])<0){
            words[j+1] = words[j];
            j--;
        } //첫번째 글자 이므로 while 그냥 넘어가고 word[0]에 저장
        words[j+1] = strdup(buf);
        n++;
    }
}

//개행문자까지 포함해서 출력함

    fclose(fp);

    char prefix[40];
    scanf("%s",prefix);

    int count = 0;

    for (int i=0; i<n; i++){
        if(strncmp(prefix,words[i],strlen(prefix))==0){ //prefix길이 만큼만 비교
        printf("%s\n", words[i]);
        count++;
        }
    }
    printf("%d\n", count);
    return 0;
}