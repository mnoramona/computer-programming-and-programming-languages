#include <stdio.h>
#include <string.h>

int is_anagram(char *cps1, char *cps2){ //functia care verifica daca doua siruri de caractere primite ca parametru sunt anagrame
    int i, j;
    char aux, s1[51], s2[51];
    strcpy(s1, cps1);
    strcpy(s2, cps2);
if(strlen(s1) != strlen(s2)) return 0;  //cuvintele nu sunt anagrame
    if(strlen(s1) == strlen(s2)){
    for(i = 0; i < strlen(s1); i++){
        for(j = i + 1; j < strlen (s1); j++){
            if (s1[i] > s1[j]){
                aux = s1[i];
                s1[i] = s1[j];
                s1[j] = aux;
            }
        }
    }
for(i = 0; i < strlen(s2); i++){
        for(j = i + 1; j < strlen (s2); j++){
            if (s2[i] > s2[j]){
                aux = s2[i];
                s2[i] = s2[j];
                s2[j] = aux;
            }
        }
    }
    if(strcmp(s1, s2) == 0) return 1;
    else return 0;
    }
}
double compute_grade(char *s1, char *s2){ // functia care calculeaza gradul a doua siruri de caractere primite ca parametru
    int i;
    int d = 0;
    if(is_anagram(s1, s2) == 0)
        return -1;
    for(i = 0; i < strlen(s1); i++){
        if(s1[i] != s2[i]) d++;
    }
    return (double) d/strlen(s1);
}
void swap_siruri(char s1[51], char s11[51])
{
	char maux[51];
    strcpy(maux, s1);
    strcpy(s1, s11);
    strcpy(s11, maux);
}
void swap_grad(double *v1, double *v11)
{
    double aux;
        aux = *v1;
        *v1 = *v11;
        *v11=aux;
}
int main(){
    char s1[1001][101];
    char s2[1001][101];
    int N;
    int i;
    double v[1001];
    int aux;
    char maux[1001];
    scanf("%d\n", &N);
    for(i = 0; i < N; i++)
    {
    scanf("%s %s",  s1[i], s2[i]);
    }
    for(i = 0; i < N; i++){
        v[i] = compute_grade(s1[i], s2[i]);
    }
    int j;
    for (i = 0; i < N-1; i++){    
    	for (j = i+1; j < N; j++){
        	if (v[i] < v[j]){
        	        swap_grad(&v[i], &v[j]);
            		swap_siruri(s1[i], s1[j]);
            		swap_siruri(s2[i], s2[j]);
}
 if(v[i] == v[j]){
                if(strcmp(s1[i],s1[j]) < 0){
                    swap_grad(&v[i], &v[j]);
            		swap_siruri(s1[i], s1[j]);
            		swap_siruri(s2[i], s2[j]);
                }
            }
}
}
for(i = 0; i < N; i++)
        printf("%s %s\n", s1[i], s2[i]);
    return 0;
}
