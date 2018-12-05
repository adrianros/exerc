#include <stdio.h>
#include <stdlib.h>
int i,j;
typedef struct angajati{
    int cnp,varsta,salariu;
    char nume[30];
}k,a;
void citire()
{FILE *f;
f=fopen("angajati.bin","wb+");
    int n=4;
    for(i=1;i<=4;++i)
    {
        scanf("%d %d %d %20s",&k.cnp,&k.varsta,&k.salariu,&k.nume);
        fwrite(&k,sizeof(k),1,f);
    }
    fclose(f);
}
void stergere()
{   int cnpp;
citire();
    scanf("%d",&cnpp);
    FILE *f;
    f=fopen("angajati.bin","rb+");
    int x=fseek(f,0,SEEK_END);
    x=ftell(f);
    x=x/sizeof(k);
    for(i=0;i<x;++i)
    {


        fseek(f,i*sizeof(k),SEEK_SET);
        if(k.CNP==cnpp)
        {
            for(j=i+1;j<x;++x)
            {


                fread(&a,j*sizeof(k),1,f);
                fwrite(&a,(j-1)*sizeof(k),1,f);
            }
            break;
        }
    }
    fclose(f);




}
int main()
{
    stergere();
    return 0;
}
