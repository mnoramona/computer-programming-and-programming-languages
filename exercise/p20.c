#include <stdio.h>
double putere(double x, int n)
{
    int i;
    double y;
    y=1;
    for(i=1; i<=n; i++){
        y=y*x;
        return y;
    }
}

int factorial(int n)
{
    int f, i;
    f=1; 
    for(i=1; i<=n; i++) f= f*i;
    return f;
}

double taylor(double  x, int n)
{
    double ex;
    int i;
    ex=0;
    for(i=0; i<=n; i++) ex= ex + putere(x,i)/factorial(i);
    return ex;
}
int main()
{
    double x;
    int n;
    scanf("%lf %d", &x, &n);
    printf("%.4lf\n", taylor(x,n));
    return 0;
}