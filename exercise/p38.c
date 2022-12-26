#include <stdio.h>

void count(int n, int *v, int *zero, int *poz, int *neg) 
{
    int i;
    for(i=0;i<n;i++)
    {
        if(v[i]<0)(*neg)++;
        else if(v[i]>0)(*poz)++;
        else (*zero)++;
    }

}

int main()
{
    int v[100],n,i;
    scanf("%d", &n);

    for(i=0;i<n;i++)
    scanf("%d", &v[i]);

    int poz=0,neg=0,zero=0;
    count(n,v,&zero,&poz,&neg);
    printf("nule: %d\n", zero);
    printf("pozitive: %d\n", poz);
    printf("negative: %d\n", neg);
    return 0;
}