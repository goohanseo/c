#include <stdio.h>
#include <string.h>


bool jaum(char c)
{
    return !(c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
}

int main()
{
    char str[100];
    scanf("%s",str);
    int len =0;
    int max_len = 0;
    int max_pos = -1; //인덱스 0값이 될수도잇으니

    for (int i=0; i<strlen(str); i++){
        if(!jaum(str[i]))
        len=0;
        else{
            len++;
            if(len>max_len){
                max_len = len;
                max_pos = i;
            }
        }
    }

    for (int i=0; i<max_len; i++){
        printf("%c", str[max_pos-max_len+1+i]);
    }
    return 0;
}