#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
#define N 4
 
typedef struct Persoana{
        char* nume;
        char* prenume;
} Persoana;
 
void serializeaza(Persoana v[], int nrPersoane, char* fileName)
{
        FILE* f = fopen(fileName, "wb");
        fclose(f);
}
 
int main()
{
        Persoana v[N],w[N];
        char* prenume[N] = { "Eric", "Kyle", "Stan", "Kenny" };
        char* nume[N] = { "Cartman", "Broflovski", "Marsh", "McCormick" };
        int i;
        for (i = 0; i < N; i++){
                v[i].nume = nume[i];
                v[i].prenume = prenume[i];
        }
        serializeaza(v, N, "persoane.bin");
        for (i = 0; i < N; i++){
                printf("%s %s\n",w[i].prenume,w[i].nume);
        }
        return 0;
}