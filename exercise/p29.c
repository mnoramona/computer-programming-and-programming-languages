#include <stdio.h>
#include <stdlib.h>

int main() {
    int cap = 0, n = 0;
    int *v = malloc(cap * sizeof(int));

    while(1) {
        int x;
        scanf("%d", &x);

        if(x == 0) {
            break;
        }
        if(n == cap) {
            cap *= 2;
            v = realloc(v, cap * sizeof(int));
        }

        v[n++] = x;
    }

    for(int i = 0; i < n; i++)
        printf("%d ", v[i]);
    free(v);
    return 0;
}