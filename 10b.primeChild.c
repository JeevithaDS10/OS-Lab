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

  
    
        printf("[CHILD]\n");
        shm_fd=shm_open("VSS",O_CREAT|O_RDWR,0666);
        ftruncate(shm_fd,4096);
        ptr=mmap(0,4096,PROT_WRITE,MAP_SHARED,shm_fd,0);
        printf("[CHILD]:\n");

        n1=atoi(argv[1]);
        n2=atoi(argv[2]);

        int flag=0;
        char buffer[100];

        for(int i=n1;i<=n2;i++)
        {
            flag=0;
            for(int j=2;j<=i/2;j++)
            {
                if(i%j==0)
                {
                    flag=1;
                    break;
                    
                }
            }
            if(flag==0)
            {
                sprintf(buffer,"%d\t",i);
                sprintf(ptr,"%s\t",buffer);
                ptr+=strlen(buffer);
                printf("%d\t",i);
            }
            *(char *)ptr='\0';
        }
       
    return 0;
}