#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 5000
int main(){
    char buf[40];
    char *words[BUFFER_SIZE];
    int n =0; //초기 배열크기 0인것 지정해주어야됨.
    FILE *fp = fopen("harry.txt", "r");
    
    while(fscanf(fp,"%s",buf)!=EOF){ //Endoffile
        bool duplicate = false;
        for(int i=0; i<n; i++){
            if(strcmp(buf,words[i]) == 0){
                duplicate = true;
                break;
            }
        }
        if(!duplicate){
            int j = n-1; //사전식 정렬을 위한 sort
            while(j>=0 && strcmp(buf,words[j])<0){
                words[j+1] = words[j];
                j--;
            } //첫글자 입력때는 배열 크기 0이니까 넘어감
            words[j+1] = strdup(buf); //맨마지막 j--하고 빠져나왔으니 j+1해주어야함
            n++;
        }
    }
    fclose(fp);
    char prefix[40];
    scanf("%s",prefix);
    int count = 0;
    for(int i=0; i<n; i++){
        if(strncmp(words[i],prefix, strlen(prefix)) == 0){ //길이도 포함될때는 str<n>cmp 넣기
            printf("%s\n", words[i]);
            count ++;
        }
    }
    printf("%d\n", count);
    return 0;
}