#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int sm=0,mul=1;

void *sum(void *arg);
void *prod(void *ard);

void *sum(void *parm)
{
    int n,i;
    n=atoi(parm);
    printf("\nInside sum thread\n");
    for(i=1;i<=n;i++)
    {
        sm+=i;
    }
    printf("Sum thread completed\n");

}

void *prod(void *parm)
{ int n,i;
    n=atoi(parm);
    printf("\ninside product thread\n");
    for(i=2;i<=n;i++)
    {
        mul*=i;
    }
    printf("Product thread completed\n");
}

void main(int argc,char *argv[])
{
    pthread_t T1,T2;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_create(&T1,&attr,sum,argv[1]);
    pthread_create(&T2,&attr,prod,argv[1]);
    pthread_join(T1,NULL);
    pthread_join(T2,NULL);

    printf("\nInside main thread\n");
    printf("Sum:%d",sm);
    printf("\nProduct:%d\n",mul);
    
}