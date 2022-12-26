#include <stdio.h>
#include <stdlib.h>
int e_prim(int nr){
    int i;
    for(i = 2; i < nr/2; i++){
        if(nr % i == 0) return 0;
    }
    return 1;
}
void extrage_prime_diag(int n, int mat[10][10], int a, int b, int *nr, int *v){
    int i;
    for(i = 0; i < n; i ++){
            if( mat[i][i] >= a && mat[i][i] <=b && e_prim(mat[i][i])== 1){
                *nr ++;
                v[*nr] = mat[i][i];
            }
    }
}
int main(){
    int mat[10][10], a, b, *v, nr, n;
    scanf("%d", &n);
    int i, j;
    for(i = 0; i < n; i ++){
        for(j = 0; j < n; j ++){
            scanf("%d", mat[i][j]);
        }
    }
    scanf("%d %d", &a, &b);
    v = (int*) malloc (10*sizeof(int));
    extrage_prime_diag(n, mat, a, b, &nr, v);
    for(i = 0; i < nr; i ++){
        printf("%d ", v[i]);
    }
    return 0;
}
