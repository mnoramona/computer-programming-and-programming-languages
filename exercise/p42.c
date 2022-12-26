#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

typedef struct PROD{
    char name[20];
    int quantity;
    double price;
} Prod;

void creare_fisier(char *nume_fisier){
    Prod array[100];
    srand((unsigned) time(0));
    for(int i = 0; i < 100; i++){
        int x = rand() % RAND_MAX;
        sprintf(array[i].name, "Product%d", x);
        array[i].quantity = x % 100;
        array[i].price = 1.0 * x / 100;
    }

    FILE *out = fopen(nume_fisier, "wb");
    fwrite(array, sizeof(Prod), 100, out);
    fclose(out);
}

void afisare_ecran(char *nume_fisier){
    Prod array[100];
    FILE *in = fopen(nume_fisier, "rb");
    fread(array, sizeof(Prod), 100, in);
    fclose(in);

    for(int i = 0; i < 100; i++)
        printf("%s %d %lf\n", array[i].name, array[i].quantity, array[i].price);
}

void modifica_produs(char *nume_fisier){
    char name[20];
    scanf("%s", name);

    FILE *in = fopen(nume_fisier, "rb+");

    for(int i = 0; i < 100; i++){
        fseek(in, i * sizeof(Prod), SEEK_SET);
        char prod_name[20];
        fread(prod_name, sizeof(char), 20, in);
        if(!strcmp(name, prod_name)){
            printf("S-a gasit produsul, are indicele %d\n", i);
            Prod new_prod;
            scanf("%s %lf %d", new_prod.name, &new_prod.price, &new_prod.quantity);
            fseek(in, -20, SEEK_CUR);
            fwrite(&new_prod, sizeof(Prod), 1, in);
            fclose(in);
            return;
        }
    }
    fclose(in);
}

int main(){
    creare_fisier("file.bin");
    afisare_ecran("file.bin");

    return 0;
}