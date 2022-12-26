#include <stdio.h>
int cmmdc(int a, int b)
{
    while(a!=b){
        if(a>b) a = a-b;
        else b= b-a;
    }
    return a;
}
int cmmmc(int a, int b){
    int n;
    n=(a*b)/cmmdc(a,b);
    return n;
}
int main()
{
    int x1, x2, y1, y2;
 scanf("%d %d", &x1, &y1);
 scanf("%d %d", &x2, &y2);
    int x3, x4;
 x3= x1*(cmmmc(y1, y2)/y1);
 x4= x2*(cmmmc(y1, y2)/y2);
 printf("%d %d\n", x3, cmmmc(y1, y2));
 printf("%d %d", x4, cmmmc(y1, y2));
 return 0;
}