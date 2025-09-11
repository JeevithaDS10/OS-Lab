#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<sys/shm.h>
#include<sys/mman.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>


int main(int argc,char *argv[])
{
    int n1,n2;
    int shm_fd;
    void *ptr;

    if(argc>2)
    {
        sscanf(argv[1],"%d",&n1);
        sscanf(argv[2],"%d",&n2);

        if(n1<2)
        {
            printf("\nInvalid input\n");
            exit(0);
        }

    }
    else
    {
        printf("Min of 2 arguements should be passed\n");
        exit(0);
    }

    pid_t pid=fork();
    if(pid==0)
    {
        execlp("./prime","prime",argv[1],argv[2],NULL);
    }
    else
    {
        wait(NULL);
        printf("[PARENT] Child completed\n");
        shm_fd=shm_open("VSS",O_RDONLY,0666|IPC_CREAT);
        ptr=mmap(0,4096,PROT_READ,MAP_SHARED,shm_fd,0);
        printf("[PARENT] Printing:\n");
        printf("%s",(char *)ptr);
        shm_unlink("VSS");
    }
    return 0;
}