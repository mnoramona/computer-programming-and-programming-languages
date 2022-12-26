
#include <stdio.h>

int main(){
    int N, i, v[101];
    scanf("%d", &N);
    for (i=1; i<=N; i++) {
        scanf("%d ", &v[i]);
    }
    int neg=0, poz=0;
for(i=1; i<=N; i++){
    if(v[i]<0) neg++;
    else poz++;
}
printf("%d %d", neg, poz);
    return 0;
}