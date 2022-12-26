#include <stdio.h>

int main(){
    int N, M, i, j;
    int m[100][100];
    int max=0, min;
    scanf("%d %d", &N, &M);
    for(i=0; i<N; i++){
        for (j=0; j<M; j++){
            scanf("%d", &m[i][j]);
        }
    }
    min= 1000000000;
    for(i=0; i<N; i++){
        max=0;
        for (j=0; j<M; j++){
            if (m[i][j]>= max) max= m[i][j];
        } 
        if(max<= min) min=max;
    }
    
    printf("%d", min);
    return 0;
}