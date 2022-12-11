#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int N;
int cols[100];
int SUM = 0;
int queens(int level);
bool promising(int level);
int level = 0;
int main(){
    scanf("%d", &N);
    
    queens(level);
    printf("%d", SUM);
    return 0;
}

int queens(int level){
    if (!promising(level)){
        return 0;
    }
    else if(level == N){
        return SUM++;
    }
    for (int i =1; i<= N; i++){
        cols[level + 1] = i;
        queens(level +1);
    }
    return 0;
}

bool promising(int level){
    for(int i =1; i< level; i++){
        if (cols[i] == cols[level]){
            return false;
        }
        else if (level-i == abs(cols[level] - cols[i])){
            return false;
        }
    }
    return true;
}