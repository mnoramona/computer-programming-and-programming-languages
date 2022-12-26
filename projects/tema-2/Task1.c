#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
char url[51],titlu[51],*continut;
int accesari,checksum;
}a;
a *site; 
char s[31],s1[100],sir[100];
int main()
{
    int nr_caractere;
    char ch,ch2;
    int n=3,nr;
    FILE *fp,*f;
    int k=0;
    char **fisiere = (char **) malloc (n*sizeof(char*));        
    fp=fopen("master.txt","r");

    while ( fgets(s,31,fp) != NULL )        //cat timp citim din fisierul master numele celorlaltor fisiere
    {
        if(k%3==0&&k!=0)                    //daca nu mai e loc in matrice, facem loc
        {
            fisiere=(char **)realloc(fisiere,(k+3)*sizeof(char*)); 
        }
        nr=strlen(s);
        if(s[nr-1]=='\n')s[nr-1]='\0';      //ca sa nu ia fgets-ul si enterul in considerare
        fisiere[k]= (char*) malloc (nr*sizeof(char));
        strcpy(fisiere[k],s);        
        k++;
    }
    fclose (fp);
    site=(a *)malloc(k*sizeof(a));
    
    for(int i=0;i<k;i++)                //pt fiecare fisier citit, citim datele de intrare din el
    {
        int size=3;
        site[i].continut= (char*) malloc (size*sizeof(char));
        nr_caractere=0;
        strcpy(sir,fisiere[i]);
        f=fopen(sir,"r");               //deschidem pe rand fisierele/site-urile
        fgets(s1,100,f);                //citim prima linie stocata in s1

        int nc=strlen(s1)-2;            
        site[i].checksum=0;
        
        int p=1;
        while(s1[nc]!=' ')
        {
            site[i].checksum=site[i].checksum+(s1[nc]-'0')*p;
            p=p*10;
            nc--;
        }
    //printf("%d ", site[i].checksum);

    nc--;
    p=1;
        while(s1[nc]!=' ')
        {
            site[i].accesari=site[i].accesari+(s1[nc]-'0')*p;
            p=p*10;
            nc--;
        }

    nc--;
    p=1;
        while(s1[nc]!=' ')
        {
            nr_caractere=nr_caractere+(s1[nc]-'0')*p;
            p=p*10;
            nc--;
        }

    int inc=0;
    while(s1[inc]!=' ')         //salvam url ul
    {
        site[i].url[inc]=s1[inc];
        inc++;
    }
    site[i].url[inc]='\0';
    

        inc=0;
        for(int j=0;j<nr_caractere;j++)
        {
            ch=fgetc(f);
            //printf("%c", ch);
            if(ch=='<')
            {
                ch2=fgetc(f);
                j++;
                //pt titlu
                if(ch2=='t')
                {
                    while(ch2!='>')
                    {
                        ch2=fgetc(f);
                        j++;
                    }
                    ch2=fgetc(f);
                    j++;
                    while(ch2!='<')         //salvam url ul
                    {
                        site[i].titlu[inc]=ch2;
                        inc++;
                        ch2=fgetc(f);
                        j++;
                    }
                    site[i].titlu[inc]='\0';
                }

                
                //pt continut
                int inc2=0;
                if(ch2=='p')
                {
                    while(ch2!='>')
                    {
                        ch2=fgetc(f);
                        j++;
                    }
                    ch2=fgetc(f);
                    j++;
                    while(ch2!='<')         
                    {
                        if(inc2>size)
                        {
                            size+=3;
                            site[i].continut=(char *)realloc(site[i].continut,size*sizeof(char)); 
                        }
                        site[i].continut[inc2]=ch2;
                        inc2++;
                        ch2=fgetc(f);
                        j++;
                    }
                    site[i].continut[inc2]='\0';
                }
            }
        }
        
        //pt task 1:
        printf("%s ", site[i].url);
        printf("%d ", site[i].accesari);
        printf("%s\n", site[i].titlu);

        fclose(f);
    }

    

    return 0;
} 
