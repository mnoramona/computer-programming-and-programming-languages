#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
#define MAX_VALUE 200
 
int cmp(const void * a, const void *b)
{
   return (*(int*)a - *(int*)b);
}
 
int main(void)
{
    int N, i, cautat;
    int *v;
    printf("Introduceti dimensiunea vectorului:\n");
    scanf("%d", &N);

    printf("Introduceti elementul cautat:\n");
    scanf("%d", &cautat);
 
    v = calloc(N, sizeof(int));
    if (!v) printf("Nu am putut aloca memorie pentru v!\n");
 
    srand(time(NULL));
    for (i = 0; i < N; ++i)
        v[i] = (rand() % MAX_VALUE)+1;
 
    for (i = 0; i < N; ++i)
        printf("%d ", *(v+i));
    printf("\n");
 
    qsort(v, N, sizeof(int), cmp);

    for (i = 0; i < N; ++i)
        printf("%d ", *(v+i));
    printf("\n");

    int *adr = (int*) bsearch(&cautat, v, N, sizeof(int), cmp);

    if(adr != NULL)
        printf("A fost gasit elementul %d pe pozitia %d!\n", *adr, ((int)adr - (int)v)/sizeof(int) + 1);
    else
        printf("Nu s-a gasit!\n");
 
   free(v);
   return 0;
}
