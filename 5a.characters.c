#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

#define MAX 30

int main()
{
    int n;
    int buffer[MAX];
    int fd=open("Jee.txt",O_RDWR);
    printf("File descriptor is %d\n",fd);
    if(fd==-1)
    {
        printf("Cannot open file\n");
        exit(0);
    }

    printf("Reading 10 characters from the file\n");
    n=read(fd,buffer,10);
    write(1,buffer,n);

    printf("\nSkipping 5 characters from the current position and reading 10 characters in the file:\n");
    lseek(fd,5,SEEK_CUR);
    n=read(fd,buffer,10);
    write(1,buffer,n);

    printf("\nGoing 10 characters before the current position and reading 10 characters:\n");
    lseek(fd,-10,SEEK_CUR);
    n=read(fd,buffer,10);
    write(1,buffer,n);

    printf("\nGoing to 5th last character from the file:\n");
    lseek(fd,-5,SEEK_END);
    n=read(fd,buffer,5);
    write(1,buffer,n);

    printf("\nGoing to the 3rd character in the file(beginning) and reading 5 characters:\n");
    lseek(fd,3,SEEK_SET);
    n=read(fd,buffer,5);
    write(1,buffer,n);
    printf("\n");

    return 0;
}