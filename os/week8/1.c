// reader writer's problem
#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>
#include <pthread.h>
sem_t wrt;// = 1;
sem_t mutex;// = 1;
int readcount = 0;
int data = 1;
void* reader(void* vargp){
	sem_wait(&mutex);
	readcount++;
	if(readcount == 1)
		sem_wait(&wrt);
	sem_post(&mutex);
	printf("Read Operation: %d\n", data);
	
	sem_wait(&mutex);
	readcount--;
	if(!readcount)
		sem_post(&wrt);
	printf("Reader exiting\n");
	sem_post(&mutex);

}

void* writer(void* vargp){
	sem_wait(&wrt);
	printf("Write Operation: data x 2 = %d\n", data = data * 2);
	
	sem_post(&wrt);
}

int main(int argc, char const *argv[])
{
	sem_init(&mutex,0,1);
	sem_init(&wrt,0,1);
	pthread_t p1,p2,p3,p4;
	// pthread_create(&p3,NULL,reader,NULL);
	pthread_create(&p1,NULL,reader,NULL);
	sleep(1);
	pthread_create(&p3,NULL,reader,NULL);
	// sleep(1);
	pthread_create(&p2,NULL,writer,NULL);
	pthread_create(&p4,NULL,writer,NULL);

	pthread_join(p1,NULL);
	pthread_join(p2,NULL);
	pthread_join(p3,NULL);
	pthread_join(p4,NULL);

	sem_destroy(&wrt);
	sem_destroy(&mutex);

	return 0;
}