#include <stdio.h>
void dec_to_bin (int n, char *s) //functia ce transforma numarul n din baza 10 in baza 2 si il intoarce ca sir de caractere (s) de '0' sau '1'
{
    int i;
    int r = 0;
    for(i = 7; i >= 0; i--){
        if(n%2 == 1) s[i] = '1';
        if(n%2 == 0) s[i] = '0';
        n=n/2;
    }
    s[8] = 0;
}

int bin_to_dec (char *s) //functia ce primeste un numar in baza 2 ca sir de caractere si intoarce valoarea in baza 10
{
    int i;
    int k = 0;
    int p = 1;
    for(i = 7; i >= 0; i--){
        if(s[i] == '1') k = k + p;
        p = p*2;
    }
    return k;
}
char adunare(char a, char b){
    if (a == '0' && b == '0') return '0';
    if (a == '1' && b == '0') return '1';
    if (a == '0' && b == '1') return '1';
    if (a == '1' && b == '1') return '1';
}

char inmultire(char a, char b){
    if (a == '0' && b == '0') return '0';
    if (a == '1' && b == '0') return '0';
    if (a == '0' && b == '1') return '0';
    if (a == '1' && b == '1') return '1';
}
void inmultire_matrice(char a[8][9], char b[8][9], char c[8][9]) //functia ce efectueaza inmultirea a doua matrice
{   
    int i, j, k;
    for(i = 0; i < 8; i++){
        for(j =0; j < 8; j++){
            c[i][j] = '0';
            for(k = 0; k < 8; k++){
                c[i][j] = adunare (c[i][j], inmultire(a[i][k], b[k][j]));
            }
        }
    }
    for(i = 0; i < 8; i++) c[i][8] = 0;
}

void transpusa(char A[8][9], char B[8][9]) // functia ce efectueaza transpusa unei matrice
{
    int i, j;
    for(i = 0; i < 8; i++){
        for(j = 0; j < 8; j++){
            B[i][j] = A[j][i];
        }
    }
    for(i = 0; i < 8; i++) B[i][8] = 0;
}
int sum_X_0(char m[8][9]) //functia ce calculeaza scorul X si 0 pentru matrice
{
    int ok, p = 0;
    int i, j, k;
    //matricea stanga-sus
        for(i = 0; i < 4; i++){
            ok = 1;
            for(j =0; j < 4; j++){
                if(m[i][j] == '0') ok = 0;
            }
            p = p + ok;
        }
        for(j = 0; j < 4; j++){
            ok = 1;
            for(i =0; i < 4; i++){
                if(m[i][j] == '0') ok = 0;
            }
            p = p + ok;
        }
        ok = 1;
        for(i = 0; i < 4; i++){
                if(m[i][i] == '0') ok = 0;
        }
        p = p + ok;
        ok = 1;
        for(i = 0; i < 4; i++){
                if(m[i][3-i] == '0') ok = 0;
        }
        p = p + ok;
    //matricea stanga-jos
        for(i = 4; i < 8; i++){
            ok = 1;
            for(j =0; j < 4; j++){
                if(m[i][j] == '0') ok = 0;
            }
            p = p + ok;
        }
        for(j = 0; j < 4; j++){
            ok = 1;
            for(i = 4; i < 8; i++){
                if(m[i][j] == '0') ok = 0;
            }
            p = p + ok;
        }
        ok = 1;
        for(i = 4; i < 8; i++){
                if(m[i][i-4] == '0') ok = 0;
        }
        p = p + ok;
        ok = 1;
        for(i = 4; i < 8; i++){
                if(m[i][7-i] == '0') ok = 0;
        }
        p = p + ok;
    //matricea dreapta-sus
        for(i = 0; i < 4; i++){
            ok = 1;
            for(j = 4; j < 8; j++){
                if(m[i][j] == '0') ok = 0;
            }
            p = p + ok;
        }
        for(j = 4; j < 8; j++){
            ok = 1;
            for(i = 0; i < 4; i++){
                if(m[i][j] == '0') ok = 0;
            }
            p = p + ok;
        }
        ok = 1;
        for(i = 0; i < 4; i++){
                if(m[i][i+4] == '0') ok = 0;
        }
        p = p + ok;
        ok = 1;
        for(i = 0; i < 4; i++){
                if(m[i][i+7] == '0') ok = 0;
        }
        p = p + ok;
    //matricea dreapta-jos
        for(i = 4; i < 8; i++){
            ok = 1;
            for(j = 4; j < 8; j++){
                if(m[i][j] == '0') ok = 0;
            }
            p = p + ok;
        }
        for(j = 4; j < 8; j++){
            ok = 1;
            for(i = 4; i < 8; i++){
                if(m[i][j] == '0') ok = 0;
            }
            p = p + ok;
        }
        ok = 1;
        for(i = 4; i < 8; i++){
                if(m[i][i] == '0') ok = 0;
        }
        p = p + ok;
        ok = 1;
        for(i = 4; i < 8; i++){
                if(m[i][11-i] == '0') ok = 0;
        }
        p = p + ok;
        return p;
}
 

int main()
{
    int n;
    int i;
    char s[9];
    char A[8][9];
    char At[8][9];
    char AA[8][9];
    char AAt[8][9];
    for(i = 0; i < 8; i++){
        scanf("%d", &n);
        dec_to_bin(n, A[i]);
    }
    transpusa(A,At);
    inmultire_matrice(A, At, AAt);
    inmultire_matrice(A, A, AA);
    int p1 = 0, p2 = 0, p3 = 0;
    p1 = sum_X_0(A);
    p2 = sum_X_0(AAt);
    p3 = sum_X_0(AA);
    if(p1 >= p2 && p1 >= p3) 
        for(i = 0; i < 8; i++) 
            printf("%d\n", bin_to_dec(A[i]));
    else if(p2 >= p3 && p2 >= p1) 
        for(i = 0; i < 8; i++) 
            printf("%d\n", bin_to_dec(AAt[i]));
    else if(p3 >= p1 && p3 >= p2) 
        for(i = 0; i < 8; i++) 
            printf("%d\n", bin_to_dec(AA[i]));
    return 0;
}
