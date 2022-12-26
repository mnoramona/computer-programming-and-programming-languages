#include <stdio.h>
#include <string.h>
int main(int argc, const char *argv[]){
//argc reprezintă numărul de argumente
//argv vectorul de pointeri la argumente (şiruri de caractere)
// *Primul argument argv[ 0 ] este întotdeauna numele executabilului
    const char *file = argv[1];
    const char *str = argv[2];
    int LINE_SIZE = 100;
    //FILE * fopen ( const char * filename, const char * mode )
    FILE *in = fopen(file, "r"); //“r” deschide fişierul pentru citirE
    if(in == NULL){ //Dacă fişierul nu există sau nu a putut fi deschis, se va întoarce NULL.
        fprintf(stderr, "Error! Nu s-a deschis cu succes fisierul %s\n", file);
        return 0;
    }
    char line[LINE_SIZE];
    while (fgets(line, LINE_SIZE, in)){ //char *fgets ( char *buf, int nmax, FILE * f ) 
    //citeşte caractere din fişier până cănd se întâlneşte '\n' (este şi el adăugat la şir) sau până când s­au citit nmax ­ 1 caractere.
        if(strstr(line, str) != NULL) printf("%s", line);
    }
    fclose(in); //int fclose ( FILE * file ) închide fişierul asociat cu structura file şi îl dezasociază.

    return 0;
}