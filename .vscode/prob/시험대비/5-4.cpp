#include <stdio.h>

int main()
{
    FILE *fp = fopen("sample.html", "r");
    FILE *of = fopen("sample.txt", "w");
    int c;
    bool inside_tag = false;
    while((c=fgetc(fp)) != EOF){ //단어 하나하나 다 똑같이 저장
    if (c=='<')
    inside_tag = true;
    else if (c=='>')
    inside_tag = false;
    else if(!inside_tag) //if(!inside_tag)이러면 false로 넘어와서 True가 되어버림
    fputc(c,of);
    }
    fclose(fp);
    fclose(of);
}