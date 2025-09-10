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

int main(int argc,char* argv[])
{
    int i;
    int shmid;
    void *ptr;
    pid_t pid;
    shmid=shmget((key_t)1122,4096,0666|IPC_CREAT);
    ptr=shmat(shmid,NULL,0666);

    if(argc>1)
    {
        sscanf(argv[1],"%d",&i);
        if(i<1)
        {
            printf("ERROR in input\n");
            return 0;
        }
    }
    else
    return 1;

    pid=fork();
    if(pid==0)
    {
        execlp("./fib","fib",argv[1],NULL);
    }
    else if(pid>0)
    {
        wait(NULL);
        printf("[PARENT] Child completed\n");
        printf("[PARENT] printing\n");
        printf("%s ",(char *)ptr);
      
    }   
    shmdt(ptr);
    return 0;

}