#include <stdio.h>

int main (void){
    int n;
    int num[100];

    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%d",&num[i]);
}
int theMin = num[0];
int theSecond;
for (int i=0; i<n; i++){
    if (num[i] < theMin){
        theSecond = theMin;
        theMin = num[i];}
}
printf("%d", theMin);
return 0;
}