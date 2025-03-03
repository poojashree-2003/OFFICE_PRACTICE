#include<stdio.h>
#include<pthread.h>

pthread_mutex_t lock; //declare mutex lock
int counter=0; // shared variable to be global


//function that uses common shared variable
void* incrementcounter(void* arg){
	pthread_mutex_lock(&lock);
	counter++;
	printf("Counter: %d\n",counter);
	pthread_mutex_unlock(&lock);
	return NULL;
}

int main(){
	pthread_t thread1,thread2; //thread pointers

	pthread_mutex_init(&lock,NULL); //mutex intialization

	//thread creating
	pthread_create(&thread1,NULL,incrementcounter,NULL);
	pthread_create(&thread2,NULL,incrementcounter,NULL);

	//waiting for prev thread to complete the process
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);

	//destroy the mutex after done
	pthread_mutex_destroy(&lock);

	return 0;
}
