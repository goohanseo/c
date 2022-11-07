#include <stdio.h>

int main(){
    int s;
    scanf("%d",&s);
    while(s > 0){
        s /= 2;
        printf("%d\n",s);
    }
    return 0;
}