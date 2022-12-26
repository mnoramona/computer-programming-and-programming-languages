#include <stdio.h>
#include <stdlib.h> // pentru functii pentru alocarea memoriei
#include <string.h> // functii predefinite pentru prelucrarea sirurilor de caractere

/* Pentru reprezentarea in memorie unui site, se va folosi o structura care sa contina URL-ul,
numarul de accesari, checksum-ul, titlul si continutul, obtinute dupa parsarea codului HTML. URL-ul si titlul
vor avea o dimensiune maxima de 50 de caractere, iar continutul va avea exact dimensiunea necesara pentru
stocarea sa. */
typedef struct{
    char url[51];
    int accesari;
    int checksum;
    int lungime_octeti_url;
    char titlu[51];
    //char *continut_paragraf;
    char* continut_html;
} site;

int main(){
    int i;
    char numele_site_ului[31];
    int nr_site_uri = 0; // contor cu numarul de site-uri
    // Datele corespunzatoare tuturor site-urilor se vor memora intr-un vector de astfel de structuri
    char **vector_site_uri; // vector cu numele site-urilor din master
    // alocat dinamic cu o marime initiala de 3 elemente
    int marime = 3; // marimea initiala
    // alocare dinamica:
    vector_site_uri = (char**) malloc (marime * sizeof(char*));
    FILE *open_master;
    open_master = fopen("master.txt", "r"); //deschide fisierul pentru citire
    site *site_uri;
    FILE *open_site;
    site_uri = (site*) malloc (marime * sizeof(site));

    while(fgets(numele_site_ului, 31, open_master ) != NULL){ //cat timp imi citeste site-urile din fisier
    // realocat daca este nevoie, marit de fiecare data cu inca 3 elemente
        if(nr_site_uri == marime){
            marime = marime + 3;
            vector_site_uri = (char**) realloc ( vector_site_uri, marime * sizeof(char*)); //realocam memoria
            site_uri = (site*) realloc (site_uri, marime * sizeof(site));
        }
        int lungime;
        lungime = strlen(numele_site_ului); // lungimea denumirii site-ului
        if(numele_site_ului[lungime - 1] == '\n') numele_site_ului[lungime - 1] = '\0'; // sa nu luam in considerare si enter-ul
        //alocam memorie pt fiecare sir de caractere pentru fiecare nume de site
        vector_site_uri[nr_site_uri] = (char*) malloc ((strlen(numele_site_ului) + 1) * sizeof(char));
        strcpy(vector_site_uri[nr_site_uri], numele_site_ului); // copiem numele site-ului in vectorul de nume
        nr_site_uri++; //creste contorul de site-uri
    }
    fclose(open_master);
    int lungime_octeti;
    for(i = 0; i < nr_site_uri; i++){
        open_site = fopen(vector_site_uri[i], "r"); //deschide fisierul pentru citire
        //Un fisier va fi alcatuit din caractere ASCII si va contine
        //1. URL-ul site-ului, 2. lungimea in octeti a codului HTML, 3. numarul de accesari, 4. checksum-ul
        fscanf(open_site, "%s", site_uri[i].url);
        fscanf(open_site, "%d", &site_uri[i].lungime_octeti_url);
        fscanf(open_site, "%d", &site_uri[i].accesari);
        fscanf(open_site, "%d", &site_uri[i].checksum);
        lungime_octeti = site_uri[i].lungime_octeti_url;
        site_uri[i].continut_html = (char*) malloc ((lungime_octeti + 1) * sizeof(char));
        int j;
        char primul_endline;
        fscanf(open_site, "%c", &primul_endline);
        for( j = 0; j < lungime_octeti; j++){
                fscanf(open_site, "%c", &site_uri[i].continut_html[j]);
                //if(site_uri[i].continut_html[j] == 13) j--; // uita te la ascii
        }
        site_uri[i].continut_html[lungime_octeti] = '\0';
        fclose(open_site);
        char *inceput_de_titlu = "<title>"; // inceput de titlu reprezinta sirul de caractere "<title>" dupa care cautam titlul
        char *final_de_titlu = "</title>"; // final de titlu reprezinta sirul de caractere "</title>" dupa care cautam unde se termina titlul
        char *inceputt;
        char *finalt;
        int lungime;
        inceputt = strstr(site_uri[i].continut_html, inceput_de_titlu); // are rolul de a identifica daca "<title>"" este subsir al sirului continut_html. 
        // Daca este, functia returneaza adresa de inceput a subsirului "<title>" in sirul continut_html
        if(inceputt != NULL){
            finalt = strstr(site_uri[i].continut_html, final_de_titlu); // are rolul de a identifica daca "</title>"" este subsir al sirului continut_html.
            // Daca este, functia returneaza adresa de inceput a subsirului "</title>" in sirul continut_html
            if(finalt != NULL){
                lungime = finalt - (inceputt + strlen(inceput_de_titlu));
                memcpy(site_uri[i].titlu, inceputt + strlen(inceput_de_titlu), lungime);
                site_uri[i].titlu[lungime] = '\0';
            }
        }
    }
    
    // Task 1: vom afisa URL-ul site-urilor, numarul vizualizarilor si titlul, in ordinea in care apar in master.txt. 
    // afisarea URL-urilor si a numarului de vizualizari
    for(i = 0; i < nr_site_uri; i++){
        printf("%s ", site_uri[i].url);
        printf("%d ", site_uri[i].accesari);
        printf("%s", site_uri[i].titlu);
        printf("\n");
    }
    for(i = 0; i < nr_site_uri; i++){
        free(vector_site_uri[i]);
        free(site_uri[i].continut_html);
    }
    free(vector_site_uri);
    free(site_uri);
    return 0;
}