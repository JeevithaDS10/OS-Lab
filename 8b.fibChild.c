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
    int i,shm_fd;
    int k=2,n1,n2,n3;
    void *ptr;
   
        shm_fd=shm_open("vss",O_CREAT|O_RDWR,0666);
        ftruncate(shm_fd,4096);
        ptr=mmap(0,4096,PROT_WRITE,MAP_SHARED,shm_fd,0);
        printf("[CHILD]\n");
        i=atoi(argv[1]);
        n1=0;
        n2=1;
        sprintf(ptr,"%d\t",n1);
        ptr+=strlen(ptr);
        printf("%d\t",n1);
        sprintf(ptr,"%d\t",n2);
        ptr+=strlen(ptr);
        printf("%d\t",n2);
        while(k!=i)
        {
            n3=n1+n2;
            sprintf(ptr,"%d\t",n3);
            printf("%d\t",n3);
            n1=n2;
            n2=n3;
            ptr+=strlen(ptr);
            k++;
        }
        *(char *)ptr='\0';

    
    return 0;
}
    

