#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<dirent.h>


void main(int argc,char* argv[])
{
    DIR *dp;
    struct dirent *dirp;

    if(argc<2)
    {
        printf("Directory name is not given as an arguement\n");
        exit(0);

    }

    if((dp=opendir(argv[1]))==NULL)
    {
        printf("Cannot open this directory\n");
        exit(1);
    }

    while((dirp=readdir(dp))!=NULL)
    {
        printf("%s\n",dirp->d_name);

    }
    closedir(dp);
}