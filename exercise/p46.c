/*Program pentru ordonarea unui vector de numere
prin determinarea repetată a valorii maxime dintr-un vector 
şi schimbarea cu ultimul element din
vector. Funcţie care determină poziţia valorii
maxime dintr-un vector.*/
#include <stdio.h>
// functie care determina pozitia maxima în vector de numere
int max(float *x, int n){
    int i;
    int imax = 0;
    for(i = 0; i < n; i++){
        if(x[i] > x[imax])
        imax = i;
    }
    return imax;
}
//  functie ordonare vector
void sortare(float *x, int n){
    int imax;
    float aux;
    while (n > 1){
        imax = max(x, n);
        aux = x[imax];
        x[imax] = x[n - 1];
        x[n -1] = aux;
        n --;
    }
}
int main(){
    float t[] = { 5, 2, 9, 1, 4, 6, 2, 8};
    int i; 
    int n = sizeof(t);
    sortare(t,n);
    for(i = 0; i < n; i++){
        printf("%.2f", t[i]);
    }
    return 0;
}