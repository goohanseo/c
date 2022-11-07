#include <stdio.h>

int abs(int a)
{
    if (a>=0) return a;
    return -a;
}

int main()
{
    int n, k;
    int num[100];
    scanf("%d", &n);
    for (int i=0; i<n; i++){
        scanf("%d",&num[1]);
    }
    scanf("%d",&k)

    int idx_min_diff = 0;
    for (int i=1; i<n; i++){
        if (abs(num[i]-k) < abs(num[idx_min_diff]-k))
        idx_min_diff=i;
    }
    printf("%d\n", num[idx_min_diff])
    return 0;
}

