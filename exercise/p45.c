#include <stdio.h>
#define N 5

int citire1(int *tab){ // citeste elementele lui tab prin accesarea indexata a elementelor
    int i = 0;
    while(scanf("%d", &tab[i]) != EOF) i++;
    return i;
}
void tiparire1(int *tab, int n){ // tipareste elementele tabloului prin accesarea indexata a elementelor
    int i;
    for(i = 0; i < n; i++) printf("%d", tab[i]);
    printf("\n");
}
int citire2(int *tab){// citeste elementele lui tab - accesarea fiecarui element
// se face printr-un pointer la el
    int *pi;
    pi = tab;
    while(scanf("%d", pi) != EOF) pi++;
    return pi - tab;
}
void tiparire2(int *tab, int n){// tipareste elementele lui tab prin accesare prin pointeri
    int *pi;
    for(pi = tab; pi < tab + n; pi++)printf("%d", pi);
    printf("\n");  
}
int main(){
    int tab1[N], tab2[N], n, m;
    n = citire1(tab1);
    tiparire1(tab1, n);
    m = citire2(tab2);
    tiparire2(tab2, m);
    return 0;
}