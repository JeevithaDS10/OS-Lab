#include<stdio.h>

typedef struct process
{
    int pid;
    int AT;
    int BT;
    int RT;
    int WT;
    int TAT;
    int CT;
    int finished;
    int priority;

}Process;

void priority(Process[],int);

int main()
{
    int n;
    printf("\nEnter the number of proceses:");
    scanf("%d",&n);

    Process processes[n];

    printf("\nEnter the details of proceses:\n");

    for(int i=0;i<n;i++)
    {
        printf("\n\nProcess-%d",(i+1));
        printf("\nEnter AT:");
        scanf("%d",&processes[i].AT);
        printf("\nEnter BT:");
        scanf("%d",&processes[i].BT);
        printf("\nEnter priority:");
        scanf("%d",&processes[i].priority);
        processes[i].pid=(i+1);
        processes[i].finished=0;
    }


    priority(processes,n);

    return 0;
}


void priority(Process processes[],int n)
{
    int totalTAT=0;
    int totalWT=0;
    int totalRT=0;
    float avgTAT=0;
    float avgWT=0;
    float avgRT=0;
    int completed=0;
    int curTime=0;
    int idleTime=0;


    printf("\nGANTT CHART\n");

    while(completed!=n)
    {
        int minIndex=-1;
        int minPriority=9999;

        for(int i=0;i<n;i++)
        {
            if(!processes[i].finished && processes[i].AT<=curTime)
            {
                if(processes[i].priority<minPriority||(processes[i].priority==minPriority && processes[i].AT<processes[minIndex].AT))
                {
                    minPriority=processes[i].priority;;
                    minIndex=i;
                }
            }
        }


        if(minIndex==-1)
        {
            //printf("|(%d)***(%d)",elapsedTime,elapsedTime+1);
            //elapsedTime++;
            curTime++;
            idleTime++;
        }

        else{
            if(idleTime>0)
            {
                printf("|Idle till %d",idleTime);
            }
            idleTime=0;
            curTime+=processes[minIndex].BT;

           // processes[exec].RT=elapsedTime-processes[exec].AT;
           // elapsedTime+=processes[exec].BT;
            processes[minIndex].finished=1;
            completed++;
            processes[minIndex].CT=curTime;
            processes[minIndex].TAT=processes[minIndex].CT-processes[minIndex].AT;
            processes[minIndex].WT=processes[minIndex].TAT-processes[minIndex].BT;
            printf("|P%d(%d)(%d)",processes[minIndex].pid,processes[minIndex].BT,processes[minIndex].CT);

        }
    }


        printf("\nPID\tAT\tBT\tCT\tTAT\tWT\tRT\n");

        for(int i=0;i<n;i++)
        {
            printf("%d\t %d\t %d\t %d\t%d\t %d\n",processes[i].pid,processes[i].AT,processes[i].BT,processes[i].CT,processes[i].TAT,processes[i].WT);
            totalTAT+=processes[i].TAT;
            totalWT+=processes[i].WT;
            //totalRT+=processes[i].RT;
        }



        avgTAT=(float)totalTAT/n;
        avgWT=(float)totalWT/n;
        //avgRT=(float)totalRT/n;


        printf("\nAvg TAT=%.2lf\n",avgTAT);
        printf("Avg WT=%.2lf\n",avgWT);
        //printf("Avg RT=%.2lf\n",avgRT);
    }