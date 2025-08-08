#include<stdio.h>

typedef struct process
{
    int pid;
    int AT;
    int BT;
    int CT;
    int TAT;
    int WT;
    int RT;

}Process;


void fcfs(Process[],int);

int main()
{
    int n;
    printf("\nEnter the number of processes:");
    scanf("%d",&n);
    Process processes[n];

    printf("\nEnter the details of processes:\n");
    for(int i=0;i<n;i++)
    {
    printf("\nProcess-%d",(i+1));
    printf("\nEnter AT:");
    scanf("%d",&processes[i].AT);
    printf("\nEnter BT:");
    scanf("%d",&processes[i].BT);
    processes[i].pid=(i+1);
    printf("\n");
    }



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


    fcfs(processes,n);
    return 0;
}


void fcfs(Process processes[],int n)
{
    int totalTAT=0;
    int totalWT=0;
    int totalRT=0;
    float avgTAT=0;
    float avgWT=0;
    float avgRT=0;
    int elapsedTime=0;


    printf("\nGANTT CHART\n");


    for(int i=0;i<n;i++)
    {
        if(processes[i].AT>elapsedTime)
        elapsedTime=elapsedTime+(processes[i].AT-elapsedTime);

        int temp=elapsedTime;
        processes[i].RT=elapsedTime-processes[i].AT;
        elapsedTime+=processes[i].BT;
        processes[i].CT=elapsedTime;
        processes[i].TAT=processes[i].CT-processes[i].AT;
        processes[i].WT=processes[i].TAT-processes[i].BT;


        printf("|(%d)P%d(%d)",temp,processes[i].pid,elapsedTime);
    
    }


    printf("\n");
    printf("Observation Table\n");
    printf("Pid\tAT\tBT\tCT\tTAT\tWT\tRT\n");

    for(int i=0;i<n;i++)
    {
       printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",processes[i].pid,processes[i].AT,processes[i].BT,processes[i].CT,processes[i].TAT,processes[i].WT,processes[i].RT);
       totalTAT+=processes[i].TAT;
       totalWT+=processes[i].WT;
       totalRT+=processes[i].RT;

    }

    avgTAT=(float)totalTAT/n;
      avgWT=(float)totalWT/n;
        avgRT=(float)totalRT/n;


        printf("\nAvg TAT:%.2lf\n",avgTAT);
        printf("\nAvg WT:%.2lf\n",avgWT);
        printf("\nAvg RT:%.2lf\n",avgRT);

}