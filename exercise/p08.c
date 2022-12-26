#include <stdio.h>
int main() {
    int p;
    scanf("%d ", &p);
    int i, j;
    for(i=0; i<=p; i++){
        for(j=i; j<=p-i-j; j++){
            int k;
            k= p-i-j;
            if(j<=k && i+j>=k){
                printf("%d %d %d \n", i, j, k);
            }
        }
    }
    return 0;
}
