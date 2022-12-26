#include <stdio.h>

int main() {
    int n, par = 0, max =0, contor_cifre_pare = 0;
    scanf("%d", &n);
    while(n != 0){
    if(n%10/2==0){
        par = n%10;
        contor_cifre_pare ++;
        n = n/10;
    }
    else n = n/10;
    if (par > max) max = par;
    }
    if(contor_cifre_pare != 0) printf("%d", max);
    if(contor_cifre_pare == 0) printf("10");
    return 0;
}