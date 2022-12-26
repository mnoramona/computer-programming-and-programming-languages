#include <stdio.h>
int perechi_de_nebuni(int mat[101][101], int M){ //functie care afiseaza numarul de perechi de nebuni care se ataca reciproc
int i, ii, j, jj;
int atac = 0;
for(i = 0; i < M; i++){
    for(j = 0; j < M; j++){
        if(mat[i][j] == 1){
            for(ii = i - 1, jj = j - 1; ii >= 0, jj >= 0; ii--, jj--){
                if(mat[ii][jj] == 1) atac++;
            }
            for(ii = i - 1, jj = j + 1; ii >= 0, jj < M; ii--, jj++){
                if(mat[ii][jj] == 1) atac++;
            }
            for(ii = i + 1, jj = j - 1; ii < M, jj >= 0; ii++, jj--){
                if(mat[ii][jj] == 1) atac++;
            }
            for(ii = i + 1, jj = j + 1; ii < M, jj < M; ii++, jj++){
                if(mat[ii][jj] == 1) atac++;
            }
 
        }
 
    }
}
return atac/2;
}
void print_mat(int mat[101][101], int M){
    int i, j;
     for(i = 0; i < M; i++){
        for(j = 0; j < M; j++){
            printf("%d", mat[i][j]);
        }
        printf("\n");
    }
}
void swap_nebuni(int *v1, int *v11)
{
    int aux;
	aux = *v1;
	*v1 = *v11;
	*v11 = aux;
}
int posibil(int M, int x[10001], int y[10001], int mat[101][101], int N){
    int i, j, k;
    for(k = 0; k < N; k++){
        for(i = 0; i < M; i ++){    
            for (j = 0; j < M; j++){
                swap_nebuni(&mat[x[k]][y[k]], &mat[i][j]);
                if(perechi_de_nebuni(mat, M) == 0) return 1;
                swap_nebuni(&mat[x[k]][y[k]], &mat[i][j]);
            }
        }
    }
    return 0;
}
int main(){
    int M;
    scanf("%d", &M); //dimensiunea matricei 
    int mat[101][101];
    int N;
    scanf("%d", &N); //numarul de nebuni pe tabla
    int x[10001];
    int y[10001];
    int i, j, k;
    for(i = 0; i < M; i++){
        for(j = 0; j < M; j++)
            mat[i][j] = 0;
 
    }
    for(i = 0; i < N; i++){
        scanf("%d %d", &x[i], &y[i]);
        mat[x[i]][y[i]] = 1;
    }
    printf("%d\n", perechi_de_nebuni(mat, M));
 
    if(perechi_de_nebuni(mat, M) != 1) printf("NU");
    else{
    if (posibil(M, x, y, mat, N) == 1) printf("DA");
    else printf("NU");
    }
	printf("\n");
    return 0;
}
