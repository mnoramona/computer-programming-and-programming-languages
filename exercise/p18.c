#include <stdio.h>
#include <math.h>

int prim (int N)
{
    int i, y=1;
    for (i=2; i<=sqrt(N);i++)
       if (N%i==0)
            y=0;
    return y;
}

int main()
{
    int N, i;
 scanf("%d", &N);
 for (i=1; i<=N/2; i++){
        if (prim(i)==1 && prim(N-i)==1) printf("%d+%d\n", i, N-i);
    }
 return 0;
}
