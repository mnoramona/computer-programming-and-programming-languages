#include <stdio.h>
void bubble_sort(int n, int v[])
{
    int sortat=0;
    int i, aux;
    while(sortat==0)
    {
        sortat=1;
        for(i=0; i<n-1; i++)
        {
            if(v[i]>v[i+1])
            {
                aux= v[i];
                v[i]=v[i+1];
                v[i+1]=aux;
                sortat=0;
            }
        }
    }
     
}
int main() 
{
    int n, v[10000],i;
    scanf("%d", &n);
    for(i=0; i<n; i++) scanf("%d", &v[i]);
    bubble_sort(n,v);
    for(i=0; i<n; i++) printf("%d ", v[i]);
    return 0;
}
