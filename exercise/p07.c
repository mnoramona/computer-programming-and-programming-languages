#include <stdio.h>
int main() {
    float x, sx=0;
    double y, sy=0;
    int n,i;
    scanf ("%d %f %lf", &n, &x, &y);
    for(i=1; i<=n; i++){
        sx = sx + x;
        sy = sy + y;
        if(i%(n/10)==0){
            printf("%f %e %f %e \n", sx, sx, sy, sy);
        }
    }
    return 0;
}
