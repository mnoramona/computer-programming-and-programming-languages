#include <stdio.h>
void count(int n, int *v, int *zero, int *poz, int *neg)
{
    int i;
    for(i=0; i<n; ++i)
    {
        if(v[i]<0) ++(*neg);
        if(v[i]>0) ++(*poz);
        if(v[i]==0) ++(*zero);
    }
}
int main(){
    int v[100];
    int n, i;
    scanf("%d", &n);
    for(i=0; i<n; ++i) scanf("%d", v+i);
    int zero=0, poz=0, neg=0;
    count(n, v, &zero, &poz, &neg);
    printf("nule: %d\n", zero);
    printf("pozitive: %d\n", poz);
    printf("negative: %d\n", neg);
    return 0;
}