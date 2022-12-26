#include <stdio.h>
int main() {
    int nr=0;
    for (int i=32; i<=127; i++) {
        if(nr==10){
        printf("\n");
        nr=0;}
        printf("%c = %d", i, i);
        nr++;
        
    }
    return 0;
}
