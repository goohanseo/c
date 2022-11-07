#include "string_tools.h"
int read_line(FILE *fp, char str[], int n){
    int ch,i =0;
    while ((ch=fgetc(fp)) != '\n' && ch != EOF){
        if(i<n-1){
            str[i++] = ch;
            }
        str[i]= '\0';
        }
        return i;
    
}

//소스파일은 항상 자신의 헤더 파일을 include 해주어야함
//소스파일 -> 헤더파일 -> 메인함수
//7번 한글로 x