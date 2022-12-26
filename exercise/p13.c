#include <stdio.h>

int main(){
    int N, i, j;
    int A[100][100];
    scanf("%d", &N);
    for(i=0; i<N; i++){
        for (j=0; j<N; j++){
            scanf("%d", &A[i][j]);
        }
    }
    
    for(j=0; j<N; j++){
        for(i=0; i<N; i++){
        
                if (j > N-i-1) printf("%d ", A[i][j]);
        } 
    }
    
    return 0;
}