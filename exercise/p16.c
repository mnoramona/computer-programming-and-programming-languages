#include <stdio.h>
 
int cifre(int n, int c)
{
 while (n) 
 {
     if(n%10==c) return 1;
     else n = n/10;   
}
}
int main(void)
{
    int n,c;
 scanf("%d %d", &n, &c);
 if(cifre(n,c)==1) printf("DA"); 
 else printf("NU"); 
 return 0;
}