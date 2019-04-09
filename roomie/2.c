#include<stdio.h>
#include<unistd.h>
#include<semaphore.h>
#include<pthread.h>

sem_t s;

void * func(int * arg)
{

}

int main()
{
	sem_init(&s,0,1);
	pthread_t th1,th2;
	pthread_create(&th1,NULL,func,)

}