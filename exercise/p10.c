#include <stdio.h>
int comb[11];
int main() {
    int n,m;
    scanf("%d %d", &n, &m);
    comb[0] =1;
    int k;
    for(k=1; k<=m; k++){
        comb[k]= comb[k-1] * (n-k+1)/k;
    }
    printf("%d\n", comb[m]);
    return 0;
}
