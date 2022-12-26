#include <stdio.h>
#include <string.h>

char src[101],dest[101];
int nr,poz;

char* substr(char *src, int n, char *dest)
{
    strncpy(dest,src,nr);
    return dest;
}

int main() {
   
   int a,b;
   scanf("%s", src);
   scanf("%d %d", &poz, &nr);
   substr(src+poz, nr, dest);
   printf("%s\n", dest);
   return 0;
}