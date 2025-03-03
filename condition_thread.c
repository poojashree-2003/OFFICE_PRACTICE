#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

pthread_mutex_t lock;
pthread_cond_t  cond;
int ready=0;

void* waitforsignal(void* arg){
	pthread_mutex_lock(&lock);
	while(!ready){
		printf("WAITING...\n");
		pthread_cond_wait(&cond,&lock);	
	}
	printf("RECIEVED!\n");
	pthread_mutex_unlock(&lock);
	return NULL;
}

void* sendsignal(void* arg){
	pthread_mutex_lock(&lock);
	ready=1;
	pthread_cond_signal(&cond);
	pthread_mutex_unlock(&lock);
	return NULL;
}

int main(){
	pthread_t thread1,thread2;

	pthread_mutex_init(&lock,NULL);
	pthread_cond_init(&cond,NULL);

	pthread_create(&thread1,NULL,waitforsignal,NULL);
	pthread_create(&thread2,NULL,sendsignal,NULL);

	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	
	pthread_mutex_destroy(&lock);
	pthread_cond_destroy(&cond);

}
