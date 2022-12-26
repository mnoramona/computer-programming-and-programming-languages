#include <stdio.h>
void swap(int *pa, int *pb){
    double aux;         
    aux = *pa;
    *pa = *pb;
    *pb = aux;
}
int main(){
    int N, i, v[101];
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d ", &v[i]);
    }
    int neg = 0, poz = 0, nul = 0;
    for(i=1; i<=N; i++){
    if(v[i]<0) neg ++;
    else poz ++;
}
printf("%d %d %d", nul, neg, poz);
    return 0;
}