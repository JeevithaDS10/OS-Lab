#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

pid_t my_pid,child_pid,parent_pid;
child_pid=fork();
if(child_pid<0)
{
    printf("\nfork failed\n");
    exit(0);
}

if(child_pid==0)
{
    printf("\n[CHILD] This is the child procees\n");
    my_pid=getpid();
    parent_pid=getppid();
    printf("[CHILD] My pid is %d",my_pid);
    printf("[CHILD] My parent pid is %d",parent_pid);
    printf("[CHILD] Sleeping for 10 seconds");
    sleep(10);
    printf("[CHILD] My parent ended...So I'm an orphan process now adopted by an INIT process");

}

else{
    printf("\n[PARENT] This ias the parent process\n");
    my_pid=getpid();
    parent_pid=getppid();
    printf("[PARENT] My pid is %d",my_pid);
    printf("[PARENT] My parent pid is %d",parent_pid);
    printf("[PARENT] Parent process is exiting\n");
    exit(0);
}