#include <stdio.h>

    char str1[100], str2[100];
    int strcmp(char str1[], char str2[])
    {
        int i;
        i=0; 
        while (str1[i] != 0 || str2[i] != 0)
        {
            if (str1[i] > str2[i])
            return 1;
            if (str1[i] < str2[i])
            return -1;
            i++;
        }
        return 0;
    }
    int main()
    {
        scanf("%s %s", str1, str2);
        printf("%d\n", strcmp(str1, str2));
        return 0;
    }