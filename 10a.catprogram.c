#include<stdio.h>
#include<stdlib.h>

void main(int argc,char* argv[])
{
    FILE *fp;
    char ch;
    if(argc<2)
    {
        printf("No file name is passed as an arguement\n");
        exit(0);

    }

    fp=fopen(argv[1],"r");

    if(fp==NULL)
    {
        printf("File doesnt exist\n");
        exit(0);
    }

    while((ch=fgetc(fp))!=EOF)
    {
        printf("%c",ch);
    }
    fclose(fp);
    printf("\n");
}

