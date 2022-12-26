#include <stdio.h>
#include <string.h>
void trigonometric(int mat[3][3]) // functia ce efectueaza rotirea unei matrice in sens trigonometric
{
    int aux[3];
    aux[0] = mat[0][0];
    aux[1] = mat[0][1];
    aux[2] = mat[0][2];
    mat[0][1] = mat[1][2];
    mat[0][2] = mat[2][2];
    mat[1][2] = mat[2][1];
    mat[2][2] = mat[2][0];
    mat[2][1] = mat[1][0];
    mat[2][0] = aux[0];
    mat[1][0] = aux[1];
    mat[0][0] = aux[2];
}
void ceasornic(int mat[3][3])// functia ce efectueaza rotirea unei matrice in sens ceasornic prin rotirea trigonometrica de 3 ori
{
    trigonometric(mat);
    trigonometric(mat);
    trigonometric(mat);
}
void F(int a[3][3], int b[3][3], int c[3][3], int d[3][3])
{
    int aux[3];
    aux[0] = a[2][0];
    aux[1] = a[2][1];
    aux[2] = a[2][2];
    a[2][0] = d[0][2];
    a[2][1] = d[1][2];
    a[2][2] = d[2][2];
    d[0][2] = c[0][0];
    d[1][2] = c[0][1];
    d[2][2] = c[0][2];
    c[0][0] = b[2][0];
    c[0][1] = b[1][0];
    c[0][2] = b[0][0];
    b[0][0] = aux[0];
    b[1][0] = aux[1];
    b[2][0] = aux[2];
}
void FF(int a[3][3], int b[3][3], int c[3][3], int d[3][3])
{  
    F(a, b, c, d);
    F(a, b, c, d);
    F(a, b, c, d);
}
void B(int a[3][3], int b[3][3], int c[3][3], int d[3][3])
{
    int aux[3];
    aux[0] = a[0][0];
    aux[1] = a[0][1];
    aux[2] = a[0][2];
    a[0][0] = d[2][0];
    a[0][1] = d[1][0];
    a[0][2] = d[0][0];
    d[0][2] = c[0][0];
    d[1][2] = c[0][1];
    d[2][2] = c[0][2];
    c[0][0] = b[2][0];
    c[0][1] = b[1][0];
    c[0][2] = b[0][0];
    b[0][0] = aux[0];
    b[1][0] = aux[1];
    b[2][0] = aux[2];
}
void BB(int a[3][3], int b[3][3], int c[3][3], int d[3][3])
{
    B(a, b, c, d);
    B(a, b, c, d);
    B(a, b, c, d);
}
void U(int a[3][3], int b[3][3], int c[3][3], int d[3][3])
{
    int aux[3];
    aux[0] = a[0][0];
    aux[1] = a[0][1];
    aux[2] = a[0][2];
    a[0][0] = d[0][0];
    a[0][1] = d[0][1];
    a[0][2] = d[0][2];
    d[0][0] = c[0][0];
    d[0][1] = c[0][1];
    d[0][2] = c[0][2];
    c[0][0] = b[0][0];
    c[0][1] = b[0][1];
    c[0][2] = b[0][2];
    b[0][0] = aux[0];
    b[0][1] = aux[1];
    b[0][2] = aux[2];
}
void UU(int a[3][3], int b[3][3], int c[3][3], int d[3][3])
{
    U(a, b, c, d);
    U(a, b, c, d);
    U(a, b, c, d);
}
void D(int a[3][3], int b[3][3], int c[3][3], int d[3][3])
{
    int aux[3];
    aux[0] = a[2][0];
    aux[1] = a[2][1];
    aux[2] = a[2][2];
    a[2][0] = d[2][0];
    a[2][1] = d[2][1];
    a[2][2] = d[2][2];
    d[2][0] = c[2][0];
    d[2][1] = c[2][1];
    d[2][2] = c[2][2];
    c[2][0] = b[2][0];
    c[2][1] = b[2][1];
    c[2][2] = b[2][2];
    b[2][0] = aux[0];
    b[2][1] = aux[1];
    b[2][2] = aux[2];
}
void DD(int a[3][3], int b[3][3], int c[3][3], int d[3][3])
{
    D(a, b, c, d);
    D(a, b, c, d);
    D(a, b, c, d);
}
void R(int a[3][3], int b[3][3], int c[3][3], int d[3][3])
{
    int aux[3];
    aux[0] = a[0][2];
    aux[1] = a[1][2];
    aux[2] = a[2][2];
    a[0][2] = d[0][0];
    a[1][2] = d[1][0];
    a[2][2] = d[2][0];
    d[0][0] = c[0][2];
    d[1][0] = c[1][2];
    d[2][0] = c[2][2];
    c[0][2] = b[0][2];
    c[1][2] = b[1][2];
    c[2][2] = b[2][2];
    b[0][2] = aux[0];
    b[1][2] = aux[1];
    b[2][2] = aux[2];
}
void RR(int a[3][3], int b[3][3], int c[3][3], int d[3][3])
{
    R(a, b, c, d);
    R(a, b, c, d);
    R(a, b, c, d);
}
void L(int a[3][3], int b[3][3], int c[3][3], int d[3][3])
{
    int aux[3];
    aux[0] = a[0][0];
    aux[1] = a[1][0];
    aux[2] = a[2][0];
    a[0][0] = d[0][2];
    a[1][0] = d[1][2];
    a[2][0] = d[2][2];
    d[0][2] = c[0][0];
    d[1][2] = c[1][0];
    d[2][2] = c[2][0];
    c[0][0] = b[0][0];
    c[1][0] = b[1][0];
    c[2][0] = b[2][0];
    b[0][0] = aux[0];
    b[1][0] = aux[1];
    b[2][0] = aux[2];
}
void LL(int a[3][3], int b[3][3], int c[3][3], int d[3][3])
{
    L(a, b, c, d);
    L(a, b, c, d);
    L(a, b, c, d);
}
int pozitie_culoare(char culori[6][11], char sir[11]){
    int i;
    for(i = 0; i < 6; i++){
        if(strcmp(sir, culori[i]) == 0) return i;
    }
    return -1;
}
void citire(int mat[3][3], char culori[6][11]){
    int i;
    char maux[35];
    for(i = 0; i < 3; i++){
        scanf("%s", maux);
        char *p;
        p = strtok(maux, ".");
        int j = 0;
        while(p != NULL){
            mat[i][j] = pozitie_culoare(culori, p);
            j++;
            p = strtok(NULL, ".");
        }
    }
}
void afisare(int mat[3][3], char culori[6][11]){
    int i;
    for(i = 0; i < 3; i++){
        printf("%d.%d.%d", mat[i][0], mat[i][1], mat[i][2]);
        printf("\n");
        printf("%s.%s.%s", culori[mat[i][0]], culori[mat[i][1]], culori[mat[i][2]]);
        printf("\n");
    }
}
int verificare(char mutare[2], char litera[2]){
    if(strcmp(mutare, litera) == 0) return 1;
    else return 0;
}
int main(){
    int i;
    int nr_mutari;
    char culori[6][11];
    char mutare[2];
    int  fata1[3][3], fata2[3][3], fata3[3][3], fata4[3][3], fata5[3][3], fata6[3][3];
    for(i = 0; i < 6; i++){
        scanf("%s", culori[i]);
    }
    citire(fata1, culori);
    citire(fata2, culori);
    citire(fata3, culori);
    citire(fata4, culori);
    citire(fata5, culori);
    citire(fata6, culori);
    scanf("%d", &nr_mutari);
    for(i = 0; i < nr_mutari; i++){
        scanf("%s", mutare);
        if (verificare(mutare, "F") == 1){ 
            ceasornic(fata1);
            F(fata3, fata6, fata4, fata5);
        }
        if (verificare(mutare, "F\'") == 1){
            trigonometric(fata1);
            FF(fata3, fata6, fata4, fata5);
        }
        if (verificare(mutare, "B") == 1){
            ceasornic(fata2);    
            B(fata3, fata5, fata4, fata6);
        }
        if (verificare(mutare, "B\'") == 1){
            trigonometric(fata2);
            BB(fata3, fata5, fata4, fata6);
        }
        if (verificare(mutare, "U") == 1){
            ceasornic(fata3);
            U(fata6, fata1, fata5, fata2);
        }
        if (verificare(mutare, "U\'") == 1){
            trigonometric(fata3);
            UU(fata6, fata1, fata5, fata2);
        }
        if (verificare(mutare, "D") == 1){ 
            ceasornic(fata4);
            D(fata6, fata1, fata5, fata2);
        }
        if (verificare(mutare, "D\'") == 1){ 
            trigonometric(fata4);
            DD(fata6, fata1, fata5, fata2);
        }
        if (verificare(mutare, "R") == 1){
            ceasornic(fata5);
            R(fata3, fata1, fata4, fata2);
        }
        if (verificare(mutare, "R\'") == 1){
            trigonometric(fata5);
            RR(fata3, fata1, fata4, fata2);
        }
        if (verificare(mutare, "L") == 1){
            ceasornic(fata6);
            L(fata3, fata1, fata4, fata2);
        }
        if (verificare(mutare, "L\'") == 1){
            trigonometric(fata6);
            LL(fata3, fata1, fata4, fata2);
        }
    }
    afisare(fata1, culori);
    afisare(fata2, culori);
    afisare(fata3, culori);
    afisare(fata4, culori);
    afisare(fata5, culori);
    afisare(fata6, culori);
    return 0;
}
