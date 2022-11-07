#include <stdio.h>

int main(){
double a = -0.1;
unsigned int *pA = (unsigned int*)&a;
//printf("%f\n%08x%08x\n", a, *(pA+1), *pA);
printf("%f\n%08x\n", a, *pA);
    return 0;
}
