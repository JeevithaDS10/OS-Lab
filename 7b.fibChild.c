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
    int i,j,k=2,n1,n2,n3;
    int shmid;
    void *ptr;
    pid_t pid;
    shmid=shmget((key_t)1122,4096,0666);
    ptr=shmat(shmid,NULL,0666);
    printf("[CHILD]\n");
    i=atoi(argv[1]);
    n1=0;
    n2=1;
    sprintf(ptr,"%d ",n1);
    ptr+=strlen(ptr);
    printf("%d\t",n1);
    sprintf(ptr,"%d ",n2);
    ptr+=strlen(ptr);
    printf("%d\t",n2);
    while(k!=i)
    {
        n3=n1+n2;
        sprintf(ptr,"%d ",n3);
        printf("%d\t",n3);
        n1=n2;
        n2=n3;
        ptr+=strlen(ptr);
        k++;
    }
    shmctl(shmid,IPC_RMID,NULL);

   
    return 0;

}