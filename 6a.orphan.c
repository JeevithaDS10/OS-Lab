#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
    pid_t my_pid,child_pid,parent_pid;
child_pid=fork();
if(child_pid<0)
{
    printf("\nFork failed\n");
    exit(0);

}

if(child_pid==0)
{
    printf("\n[CHILD] This is child process");
    my_pid=getpid();
    parent_pid=getppid();
    printf("\n[CHILD] My pid is %d",my_pid);
    printf("\n[CHILD] My parent pid is %d",parent_pid);
    printf("\n[CHILD] Child process is sleeping for 10 seconds");
    sleep(10);
    printf("\n[CHILD] Parent process has completed its execution,now i'm an orphan process adopted by an init process\n");
    
}

else{
    printf("\n[PARENT] This is parent process");
    my_pid=getpid();
    parent_pid=getppid();
    printf("\n[PARENT] My pid is %d",my_pid);
    printf("\n[PARENT] My parent pid is %d",parent_pid);
    printf("\n[PARENT] Parent process exiting\n");
    exit(0);
}

return 0;
}