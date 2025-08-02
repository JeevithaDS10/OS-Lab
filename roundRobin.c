#include<stdio.h>
#include<stdlib.h>

typedef struct process
{
    int AT;
    int pid;
    int BT;
    int TAT;
    int CT;
    int WT;
    int flag;
}Process;

void rround(Process[],int,int,int[]);

int main()
{
    int n;
    int quantum;
    printf("\nEnter the number of processes:");
    scanf("%d",&n);
    int tempBT[n];
    Process processes[n];

    printf("\nEnter process details:");
    printf("\nAT BT\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&processes[i].AT,&processes[i].BT);
        tempBT[i]=processes[i].BT;
        processes[i].pid=(i+1);
    }

    printf("\nEnter quantum:");
    scanf("%d",&quantum);

    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(processes[j].AT>processes[j+1].AT)
            {
                Process temp=processes[j];
                processes[j]=processes[j+1];
                processes[j+1]=temp;
            }
        }
    }


    rround(processes,n,quantum,tempBT);
    return 0;
}


void rround(Process processes[],int n,int quantum,int tempBT[])
{
    int completed=0;
    int totalTAT=0;
    int totalWT=0;
    float avgTAT=0;
    float avgWT=0;
    int curTime=processes[0].AT;
    int curIndex;
    int* queue=(int *)malloc(n*sizeof(int));
    int rear=0;
    int front=0;

    queue[rear]=0;
    processes[0].flag=1;

    while(completed!=n)
    {
        int curIndex=queue[front];
        front=(front+1)%n;

        if(processes[curIndex].BT>quantum)
        {
            processes[curIndex].BT-=quantum;
            curTime+=quantum;
            printf("|P%d(%d)(%d)",processes[curIndex].pid,quantum,curTime);
        
        }
        else{
            curTime+=processes[curIndex].BT;
            printf("|P%d(%d)(%d)",processes[curIndex].pid,processes[curIndex].BT,curTime);

            processes[curIndex].BT=0;
            processes[curIndex].CT=curTime;
            processes[curIndex].TAT=processes[curIndex].CT-processes[curIndex].AT;
            processes[curIndex].WT=processes[curIndex].TAT-tempBT[processes[curIndex].pid-1];
        }

        for(int i=0;i<n && processes[i].AT<=curTime;i++)
        {
            if(i==curIndex || processes[i].flag==1 || processes[i].BT==0)
            continue;
            rear=(rear+1)%n;
            queue[rear]=i;
            processes[i].flag=1;
        }


        if(processes[curIndex].BT>0)
        {
            rear=(rear+1)%n;
            queue[rear]=curIndex;
        }
        else{
            completed++;
        }
    }


    printf("\n");
    printf("OBSERVATION TABLE:\n");
    
        printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");

        for(int i=0;i<n;i++)
        {
            printf("%d\t %d\t %d\t %d\t%d\t %d\t %d\n",processes[i].pid,processes[i].AT,tempBT[i],processes[i].CT,processes[i].TAT,processes[i].WT);
            totalTAT+=processes[i].TAT;
            totalWT+=processes[i].WT;
           // totalRT+=processes[i].RT;
        }



        avgTAT=(float)totalTAT/n;
        avgWT=(float)totalWT/n;
        //avgRT=(float)totalRT/n;


        printf("\nAvg TAT=%.2lf\n",avgTAT);
        printf("Avg WT=%.2lf\n",avgWT);
       // printf("Avg RT=%.2lf\n",avgRT);
    }