#include <stdio.h>
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int i, j;
    int nr=0, nr2 = 0;
    for (i=1; i<=n; i++){
        printf("%d ", i);
        nr++;
        if (nr==m){
            printf("\n");
            nr=0;
            nr2++;
            if (nr2 == 24) {
                printf("\n");
                nr2 = 0;
            }
        }
    }
    fflush(stdin);
    getchar();
    return 0;
}
