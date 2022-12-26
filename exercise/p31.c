#include <time.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct tm TM;

int main(){
    time_t t = time(NULL);
    TM *tm = localtime(&t);
    printf("Ora curenta: %d\n", tm->tm_hour);

    char *data = asctime(tm);
    printf("Data curenta: %s\n", data);

    return 0;
}