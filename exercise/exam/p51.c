#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Carte
{
    char titlu[30];
    char autor[30];
    int nr_pagini;
}Carte;

typedef struct Biblioteca
{
    char *nume;
    int n;
    Carte *carti;
}Biblioteca;

void scrie(Biblioteca bnr, char *fisier)
{
    FILE *in;
    in = fopen(fisier, "w");
    fprintf(in, "%s\n", bnr.nume);
    fprintf(in, "%d\n", bnr.n);
    int i;
    for(i = 0; i < bnr.n; i++)
    {
        fprintf(in, "%s %s %d\n", bnr.carti[i].titlu, bnr.carti[i].autor, bnr.carti[i].nr_pagini);
    }
    fclose(in);
}

Biblioteca citire(char *fisierbinar)
{
    Biblioteca centrala;
    FILE *in;
    in = fopen(fisierbinar, "rb");
    int nrcarnume;
    fread(&nrcarnume, sizeof(nrcarnume), 1, in);
    fread(centrala.nume, sizeof(char), nrcarnume, in);
    fread(&centrala.n, sizeof(int), 1, in);
    int i;
    for(i = 0; i < centrala.n; i++)
    {
        fread(&(centrala.carti[i]), sizeof(Carte), 1, in);
    }
    fclose(in);
    return centrala;
}

int cmpCarti(const void *a, const void *b)
{
    Carte *sa = (Carte*)a;
    Carte *sb = (Carte*)b;
    return(strcmp(sa->titlu, sb->titlu));
}
