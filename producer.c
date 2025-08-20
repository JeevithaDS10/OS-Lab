#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

#define bufferSize 3
#define maxItems 3

sem_t empty;
sem_t full;
pthread_mutex_t mutex;
int in;
int out;
int buffer[bufferSize];

void *producer(void *pno)
{
    for(int i=0;i<maxItems;i++)
    {

        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        int item=rand()%100;
        buffer[in]=item;
        printf("\nProducer-%d has inserted an item %d at %d",*((int *)pno),item,in);
        in=(in+1)%bufferSize;
        pthread_mutex_unlock(&mutex);
        sem_post(&full);

    }
}


void *consumer(void *cno)
{
    for(int i=0;i<maxItems;i++)
    {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        int item=buffer[out];
        printf("\nConsumer-%d has removed item %d from %d",*((int *)cno),item,out);
        out=(out+1)%bufferSize;
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
}


int main()
{
    pthread_t pro[3],con[3];
    pthread_mutex_init(&mutex,NULL);
    sem_init(&empty,0,bufferSize);
    sem_init(&full,0,0);

    int a[3]={1,2,3};

    for(int i=0;i<3;i++)
    {
        pthread_create(&pro[i],NULL,(void *)producer,(void *)&a[i]);
    }

    for(int i=0;i<3;i++)
    {
        pthread_create(&con[i],NULL,(void *)consumer,(void *)&a[i]);

    }

    for(int i=0;i<3;i++)
    {
        pthread_join(pro[i],NULL);
    }

    for(int i=0;i<3;i++)
    {
        pthread_join(con[i],NULL);

    }

    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);
    return 0;
}