#include <stdio.h>
#include <string.h>

char *strdel(char *p, int n)
{
    char aux[3005];
    strcpy(aux, p+n);
    strcpy(p, aux);
    return p;
}

char *strins(char *p, char *s)
{
    char aux[3005];
    strcpy(aux, s);
    strcat(aux, p);
    strcpy(p, aux);
    return p;
}

char *strrep(char *p, char *s, char *t)
{
    int l_s = strlen(s);
    int l_t = strlen(t);
    char *q = p;
    while((q = strstr(q, s)) != NULL)
    {
        q = strdel(q, l_s);
        q = strins(q, t);
        q += l_t;
    }
    return p;
}

int main()
{
    char str1[3005], str2[22], str3[22];
    fgets(str1, 3005, stdin);
    fgets(str2, 22, stdin);
    fgets(str3, 22, stdin);
    int l1 = strlen(str1), l2 = strlen(str2), l3 = strlen(str3);
    str1[--l1] = 0;
    str2[--l2] = 0;
    str3[--l3] = 0;
    char *fin = strrep(str1, str2, str3);
    printf("%s\n", fin);
    return 0;
}