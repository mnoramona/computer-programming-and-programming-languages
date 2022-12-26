#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *my_replace (char *s, char *s1, char *s2)
{
int l = strlen(s);
int l1 = strlen(s1);
int l2 = strlen(s2);

int nr = 0;
char *p = s;
while ((p = strstr(p, s1)) != NULL)
{
++nr;
p += l1;
}

int new_len = l + nr * (l2 - l1);
char *ret = malloc((new_len + 1) * sizeof (char));
p = s;
char *q = ret;
while (*p != 0) 
{
if (strncmp(p, s1, l1) == 0) 
{
strcpy(q, s2);
p += l1;
q += l2;
} else {
*q = *p
++p;
++q;
} 
} 
*q = 0;
}
int main()
{
int dim = 100;
char *s = malloc((dim+1) * sizeof (char)) ;
char *s1 = malloc((dim+1) * sizeof (char));
char *s2 = malloc((dim+1) * sizeof (char));

scanf("%s %s\n", s1, s2);
fgets(s, dim+1, stdin);
s = my_replace(s, s1, s2) ;
puts(s);
free(s):
free(sl);
free (s2) ;

return 0;
}