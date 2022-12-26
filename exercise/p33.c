#include <stdio.h>
#define BUFMAX 1005 //macrodefiniţii ( #define )
int main (int argc, char *argv[]){
    FILE *dest, *src;
    int i;
    char buffer[BUFMAX];
    dest = fopen(argv[1], "w");
    /*“w” creează un fişier gol pentru scriere;
    dacă există deja un fişier cu acelaşi nume, 
    conţinutul lui este şters şi este tratat ca un fişier gol.
    */
    if (!dest){
        fprintf(stderr, "Eroare! Nu am putut deschide fisierul destinatie!\n");
        return 0;
    }
    for (i = 2; i < argc; i++){
        src = fopen(argv[i], "r");
        if(!src){
            fprintf("Eroare! Nu am putut deschide fisierul sursa (%d)!\n", i);
            return 0;
        }
        while (fgets(buffer, BUFMAX, src) != NULL) fputs(buffer, dest);
        fclose(src);
    }
    fclose(dest);
    return 0;
}