#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<sys/shm.h>


typedef struct
{
    int n;
    int arr[100];
}pack_t;

int main()
{
    key_t key=1234;
    pack_t * ptr;
    int shmid;
    pid_t pid;

    shmid=shmget(key,sizeof(pack_t),0666);
    ptr=(pack_t *)shmat(shmid,NULL,0666);
    printf("[CHILD] attached to shared memory with key-%d,id-%d and address-%p",key,shmid,ptr);

    
        for(int i=0;i<ptr->n;i++)
        {
            ptr->arr[i]=2*i+1;
        }
        printf("\nChild generated odd numbers\n");
        shmdt((void *)ptr);
       

    
    return 0;
}