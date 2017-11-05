#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

int buffer[10];
sem_t mutex;
sem_t empty,full;
int p=5,c=5;

void *produce(void *prod)
{
	for(int i = 0; i < p; i++)
	{
		sem_wait(&empty);
		sem_wait(&mutex);
		buffer[i] = i;
		printf("producing item : %d\n",i);
		sem_post(&mutex);
		sem_post(&full);
	}
	pthread_exit(NULL);
}

void *consumer(void *con)
{
	int temp;
	for(int i = 0; i < c; i++)
	{
		sem_wait(&full);
		sem_wait(&mutex);
		temp = buffer[i];
		printf("consuming item : %d\n",temp);
		sem_post(&mutex);
		sem_post(&empty);
	}

	pthread_exit(NULL);
}


int main()
{
	
	pthread_t prod;
	pthread_t cons;
	
	sem_init(&mutex,1,1);
	sem_init(&full,1,0);
	sem_init(&empty,1,10);

	pthread_create(&prod,NULL,produce,NULL);
	pthread_create(&cons,NULL,consumer,NULL);

	pthread_join(prod,NULL);
	pthread_join(cons,NULL);

	return 0;
}
