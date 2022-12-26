#include <stdlib.h>
typedef struct Carte{
    char titlu[30];
    char autor[30];
    int nr_pagini;
}Carte;

typedef struct Biblioteca{
    char *nume;
    Carte *carti;
    int n;
}Biblioteca;

void scrie(Biblioteca a, char *fisier){
    int i;
    FILE *file = fopen(fisier, "w");
    fprintf(file,"%s %d\n", a.nume, a.n);
    for(i = 0; i < a.n, i++) fprintf("%s %s %d\n", a.carti[i].titlu, a.carti[i].autor, a.carti[i].nr_pagini);
    fclose(file);
}

Biblioteca citire(char *fisier){
    FILE *file;
    int Nr_car_Nume;
    Biblioteca b;
    file = fopen(fisier, "rb");
    fread(&Nr_car_Nume, sizeof(int), 1, *file);
    fread(b.nume, sizeof(Biblioteca), 1, *file);
    }
int cmpCarti(const void * a, const void * b){
    Carte *pa = (Carte*)a; //Inveti papagaliceste
    Carte *pb = (Carte*)b;
    return strcmp(pa->titlu - pb->titlu);
}
char *cautaAutor(char *titlu, Biblioteca b, int (*cmp)(const void *, const void*)){
    /*
    
    */
}
