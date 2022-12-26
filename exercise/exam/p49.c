#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Produs{
    char nume[20];
    float pret;
    float cantitate;
}Produs;

typedef struct Magazin{
    char *id;
    int nr;
    Produs *prod;
}Magazin;

int cmpProduse(const void * a, const void * b){ 
    Produs *pa = (Produs*)a; 
    Produs *pb = (Produs*)b;
    if(strcmp(pa->nume, pb->nume) == 0)
        if(pa->pret < pb->pret)
            return 1;
    else if(strcmp(pa->nume, pb->nume) > 0)
        return 1;
    return -1;
}
void scrie(Magazin a, char *fisier, int (*cmp)(const void*, const void*)){
    int i;
    FILE *fp = fopen(fisier, "w");
    qsort(a.prod, a.nr, sizeof(Produs), cmp);
    fprintf(fp, "%s %d\n", a.id, a.nr); 
    for(i = 0; i < a.nr; i++)
        fprintf("%s %f %f\n", a.prod[i].nume, a.prod[i].pret, a.prod[i].cantitate);
    fclose(fp);
}

void modificaFisier(char *file_name, char nume[20], float pret, float cantitate){
    FILE* f = fopen(file_name, "rb");
    int nrCaractere;
    int i;
    char *id;
    int nr_prod;
    fread(&nrCaractere, sizeof(int), 1, f);       
    fread(id, nrCaractere * sizeof(char), 1, f);
    fread(nr_prod, sizeof(int), 1, f);
    int offset = (2 * sizeof(int)) + (nrCaractere * sizeof(char));
    for(i = 0; i < nr_prod; i++) {
        Produs p;
        fread(&p, sizeof(Produs), 1, f);
        if(strcmp(p.nume, nume) == 0) {
            FILE* out = fopen(file_name, "wb");
            fseek(out, offset + i * sizeof(Produs), SEEK_SET);
            Produs new_prod;
            strcpy(new_prod.nume, nume);
            new_prod.pret = pret;
            new_prod.cantitate = cantitate;
            fwrite(&new_prod, sizeof(Produs), 1, out);
            fclose(out);
            fclose(f);
            return;
        }
    }
    fclose(f);
}
