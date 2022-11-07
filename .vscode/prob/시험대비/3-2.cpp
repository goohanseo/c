#include <stdio.h>

int main(){
    int start[100];
    int end[100];
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%d %d",&start[i],&end[i]);
    }
    for(int i=n-1; i>0; i--){
        int max_index=0;
        for(int j=0; j<i; j++){
            if (start[i]>start[max_index]
            || start[i]==start[max_index]
            && end[i]>end[max_index])
            max_index = i;
        }
        int tmp = start[i];
        start[i] = start[max_index];
        start[max_index] = tmp;

        tmp = end[i];
        end[i] = end[max_index];
        end[max_index] = tmp;
    }
    for (int i=0; i<n; i++){
        printf("%d %d\n", start[i], end[i]);
    }
    return 0;
}