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

    shmid=shmget(key,sizeof(pack_t),0666|IPC_CREAT);
    ptr=(pack_t *)shmat(shmid,NULL,0666);
    printf("[PARENT] create shared memory with key-%d,id-%d and address-%p",key,shmid,ptr);
    printf("[PARENT] Enter n:");
    scanf("%d",&ptr->n);
    pid=fork();
    if(pid==0)
    {
        execlp("./odd","odd",NULL);
    }
    else
    {
        wait(NULL);
        printf("[PARENT] child completed\n");
        printf("[PARENT] printing\n");
        for(int i=0;i<ptr->n;i++)
        {
            printf("%d\t",ptr->arr[i]);
        }
        printf("\n");
        shmdt((void *)ptr);
        shmctl(shmid,IPC_RMID,NULL);
        printf("[PARENT] Shared memory deleted\n");

    }
    return 0;
}