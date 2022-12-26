#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Produs
{
    char nume[20];
    float pret;
    float cantitate;
}Produs;

typedef struct Magazin
{
    char *id;
    int nr;
    Produs *prod;
}Magazin;

int cmpProduse(const void *a, const void *b)
{   
    Produs *sa = (Produs*)a;
    Produs *sb = (Produs*)b;

    if(strcmp(sa->nume, sb->nume) == 0)
    {
        return (sb->pret - sa->pret);
    }
    return strcmp(sa->nume, sb->nume);
}

void scrie(Magazin a, char *fisier, int(*cmp)(const void *a, const void *b))
{
    FILE *out;
    out = fopen(fisier, "w");
    qsort(a.prod, a.nr, sizeof(Produs), cmp);
    fprintf(out, "%s\n", a.id);
    fprintf(out, "%d\n", a.nr);
    int i;
    for(i = 0; i < a.nr; i++)
    {
        fprintf(out, "%s %f %f\n", a.prod[i].nume, a.prod[i].pret, a.prod[i].cantitate);
    }
    fclose(out);
}

void modificaFisier(char *fisierbinar, char *nume, float pret, float cantitate_new)
{
    Magazin Lidl;
    FILE *in;
    in = fopen(fisierbinar, "rb");
    int nrmm;
    fread(&nrmm, sizeof(nrmm), 1, in);
    fread(Lidl.id, sizeof(char), nrmm, in); //id e smecher
    fread(&(Lidl.nr), sizeof(int), 1, in); ///nr mai sarac
    int i;
    for(i = 0; i < Lidl.nr; i++)
    {
        fread(&(Lidl.prod[i]), sizeof(Produs), 1, in); 
        if((strcmp(nume, Lidl.prod[i].nume) == 0) && Lidl.prod[i].pret == pret)
        {
            Lidl.prod[i].cantitate = cantitate_new;
        }
    }
    fclose(in);
    in = fopen(fisierbinar, "wb");
    fwrite(&nrmm, sizeof(nrmm), 1, in);
    fwrite(&Lidl, sizeof(Magazin), 1, in); // si apoi noi sa fim sanatosi
    fclose(in);
}
