//discutam acum doar de cuvinte tati
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
    char *continut_paragraf;
} site;

int main(){
    //introducem task1
/* Cerinta task2:
Va trebui sa cititi de la tastatura cuvinte cheie separate printr-un spatiu pana la intalnirea caracterului ‘\n’ 
si sa afisati site-urile care au in continutul lor cel putin unul dintre cuvintele cheie. 
Site-urile gasite se vor ordona alfabetic, iar in cazul in care vreun site a facut manevra lui Biju¸ 
si l-a copiat pe altul (2 site-uri au titlul identic), atunci al doilea
criteriu de ordonare, va fi numarul de accesari in ordine descrescatoare. 
*/
    int i;
    //" cititi de la tastatura cuvinte cheie separate printr-un spatiu pana la intalnirea caracterului ‘\n’"
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
        if(nr_site_uri = marime){
            marime = marime + 3;
            vector_site_uri = (char**) realloc ( vector_site_uri, marime * sizeof(char*)); //realocam memoria
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
                if(site_uri[i].continut_html[j] == 13) j--; // uita te la ascii
        }
        site_uri[i].continut_html[lungime_octeti] = '\0';
        fclose(open_site);
        char *inceput_de_paragraf1 = "<p>"; // inceput de paragraf reprezinta sirul de caractere "<p>" dupa care cautam continutul paragrafului
        char *final_de_paragraf = "</p>"; // final de paragraf reprezinta sirul de caractere "</p>" dupa care cautam unde se termina paragrafului
        // sau a doua posibilitate
        char *inceput_de_paragraf2 = "<p";
        char *final_de_inceput_de_paragraf2 = ";\">";
        char *inceputp;
        char *finalp;
        int lungime;
        inceputp = strstr(site_uri[i].continut_html, inceput_de_paragraf1); // are rolul de a identifica daca "<title>"" este subsir al sirului continut_html. 
        // Daca este, functia returneaza adresa de inceput a subsirului "<title>" in sirul continut_html
        if(inceputp != NULL){
            finalp = strstr(site_uri[i].continut_html, final_de_paragraf); // are rolul de a identifica daca "</title>"" este subsir al sirului continut_html.
            // Daca este, functia returneaza adresa de inceput a subsirului "</title>" in sirul continut_html
            if(finalt != NULL){
                lungime = finalt - (inceputt + strlen(inceput_de_titlu));
                memcpy(site_uri[i].titlu, inceputt + strlen(inceput_de_titlu), lungime);
                site_uri[i].titlu[lungime] = '\0';
            }
        }
        if(strstr(continut_html, "<p>") != NULL){
            inceputp = strstr(continut_html, inceput_de_paragraf1); // are rolul de a identifica daca "<p>"" este subsir al sirului continut_html. 
            // Daca este, functia returneaza adresa de inceput a subsirului "<p>" in sirul continut_html
            finalp = strstr(continut_html, final_de_paragraf1); // are rolul de a identifica daca "</p>"" este subsir al sirului continut_html.
            // Daca este, functia returneaza adresa de inceput a subsirului "</p>" in sirul continut_html
        }
        //else{
        //    inceputp = strstr(continut_html, inceput_de_paragraf2);
        //    finalp = strstr(continut_html, final_de_paragraf2);
        //}
        int dimensiune_paragraf; // in functie de inceput si final de paragraf
        //site_uri[i].continut_paragraf = (char*) malloc ( dimensiune_paragraf * sizeof(char*));
    int cate_cuvinte = 0; // contor pentru numarul de cuvinte citite de la tastatura
    char *cuvinte_cautate; // pointer in care salvez sirul de cuvinte, separate prin spatiu
    char cuvinte[101]; // sirul de cuvinte cautate
    scanf("%s", cuvinte); // aici citim de la tastatura cuvintele cautate separate prin spatiu
    int nr_initial_cuvinte = 1; // numarul minimum de cuvinte cautate 
    cuvinte_cautate = (char*) malloc (strlen(cuvinte + 1) * sizeof(char)); // alocarea memoriei in functie de numarul de caractere din sirul citit
    strcpy(cuvinte_cautate, cuvinte); 
    cuvinte_cautate = strtok(cuvinte, " "); // functia intoarce adresa primului caracter al primului cuvant cautat.
    char** vector_cuvinte_cautate; // vectorul in care salvez cuvintele cautate
    // alocarea dinamica:
    vector_cuvinte_cautate = (char**) malloc (cate_cuvinte * sizeof(char*));
    for(i = 0; i < cate_cuvinte; i++){
        //alocam memorie pt fiecare sir de caractere pentru fiecare cuvant
        vector_cuvinte_cautate[i] = (char*) malloc (strlen(cuvinte_cautate) * sizeof(char));
    }
    if(cate_cuvinte > nr_initial_cuvinte){ // in caz ca este nevoie, realocam memorie
        nr_initial_cuvinte ++;
        vector_cuvinte_cautate = (char**) realloc ( vector_cuvinte_cautate, nr_initial_cuvinte * sizeof(char*)); //realocam memoria
    }
    while(cuvinte_cautate){ // copiem cuvantul in vectorul de cuvinte cautate
        strcpy(vector_cuvinte_cautate[cate_cuvinte ++], cuvinte_cautate);
        cuvinte_cautate = strtok (NULL, " ");
    }
    }
    for(i = 0; i < nr_site_uri; i++){
        free(vector_site_uri[i]);
        free(site_uri[i].continut_html);
    }
    free(vector_site_uri);
    free(site_uri);
    return 0;
}