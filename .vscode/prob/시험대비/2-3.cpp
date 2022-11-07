#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 5000
int main(){
    int counter[5000] = {0};
    char *words[BUFFER_SIZE];
    int n =0; //초기 배열크기 0인것 지정해주어야됨.
    char buf[40];

    FILE *fp = fopen("harry.txt", "r");
    
    while(fscanf(fp,"%s",buf)!=EOF){
        if (strlen(buf)<6){
            continue; //continue시 while문 다시 시작
        }
        bool duplicate = false;
        for(int i=0; i<n; i++){
            if(strcmp(buf,words[i]) == 0){
                duplicate = true;
                counter[i++];
                break;
            }
        }
        if(!duplicate){
            int j = n-1; //사전식 정렬을 위한 sort
            while(j>=0 && strcmp(buf,words[j])<0){
                words[j+1] = words[j];
                counter[j+1] = counter[j];
                j--;
            } //첫글자 입력때는 배열 크기 0이니까 넘어감
            words[j+1] = strdup(buf); //맨마지막 j--하고 빠져나왔으니 j+1해주어야함
            counter[j+1] = 1;
            n++;
        }
    }
    fclose(fp);
    int sum = 0;
    for (int i =0; i<n; i++){
        printf("%s: %d\n", words[i],counter[i]);
        sum += 1;
    }
    printf("%d",sum);
    return 0;
}