#include<stdio.h>
#include<stdlib.h>
#include<string.h>

 void main()
 {
    char fn[10],temp[100],pat[10];
    FILE *fp;
    printf("Enter file name:\n");
    scanf("%s",fn);
    fp=fopen(fn,"r");
    if(fp==NULL)
    {
        printf("No such file\n");
        exit(1);
    }
    printf("Enter the pattern:\n");
    scanf("%s",pat);
    //fp=fopen(fn,"r");

    while(!feof(fp))
    {
        fgets(temp,100,fp);
        if(strstr(temp,pat))
        {
            printf("%s",temp);

        }
    }
    fclose(fp);
 }