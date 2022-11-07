#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bublesort(int n, char words[]);
int main(void){

    char *words[100];
    int n=0;
    char buf[20];

    scanf("%d", &n);
    for (int i=0; i<n; i++){
        scanf("%s", buf);
        words[i] = strdup(buf);
    }

    bubllesort(n, words[]);
    for (int i=0; i<n; i++)
    printf("%s", words[i]);

    return 0;
}

void bublesort(int n, char *words[]){
    for(int i=n-1; i>0; i--){
        for (int j = 0; j < i; j++){
            if (strlen(words[j])>strlen(words[j+1])
            ||strlen(words[j])==strlen(words[j+1])
            && strcmp(words[j], words[j+1]) > 0
             )
                char * tmp = words[j];
                words[j] = words[j+1];
                words[j + 1] = tmp;
            }
        }
    }
