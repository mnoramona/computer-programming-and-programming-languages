#include <stdio.h>
#include <math.h>

float dist(int x1, int y1, int x2, int y2){
    float a;
    a=sqrt(x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
    return a;
}
int main(){
    int n, x[10], y[10], i;
    scanf("%d"; &n);
    for(i=0; i<n; i++) scanf("%d *%d", &x[i], &y[i]);
    return 0;
}