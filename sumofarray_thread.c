#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int size;
int sum1=0;
int sum2=0;

//int condition=0;

pthread_mutex_t lock;
//pthread_cond_t cond;

//function to sum 1st half of the array
void* part1(void* arg){
	if(pthread_mutex_trylock(&lock)==0){
		int* nums=(int*)arg;
		for(int i=0;i<(size/2);i++){
			sum1+=nums[i];
		}
		pthread_mutex_unlock(&lock);
	}
	else{
		printf("Mutex already locked");
	}
	return NULL;
}

//function to sum 2nd half of the array
void* part2(void* arg){
        if(pthread_mutex_trylock(&lock)==0){
                int* nums=(int*)arg;
                for(int i=(size/2);i<size;i++){
                        sum2+=nums[i];
                }
		pthread_mutex_unlock(&lock);	
        }
        else{
                printf("Mutex already locked");
        }
        return NULL;
}

//function to give total sum
void* sum(void* arg){
	if(pthread_mutex_trylock(&lock)==0){
		int final;
		final=sum1+sum2;
		printf("The sum of the array is: %d\n",final);
		pthread_mutex_unlock(&lock);
	}
	else{
		printf("Mutex already locked");
	}
	return NULL;
}


int main(){
	pthread_t thread1,thread2,thread3;

	printf("Enter size of the array: ");
	if(scanf("%d",&size)!=1){
		printf("Enter valid number");
		while(getchar()!='\n');
		main();
	}

	
	int* array=(int*)malloc(size*(sizeof(int)));
	for(int i=0;i<size;i++){
		printf("Enter number %d: ",i+1);
		if(scanf("%d",&array[i])!=1){
			printf("Enter valid number");
			while(getchar()!='\n');
			main();
		}
	}

	pthread_mutex_init(&lock,NULL);
	//pthread_cond_init(&cond,NULL);

	pthread_create(&thread1,NULL,part1,(void *)array);
	pthread_join(thread1,NULL);

	pthread_create(&thread2,NULL,part2,(void*) array);
	pthread_join(thread2,NULL);

	pthread_create(&thread3,NULL,sum,NULL);
	pthread_join(thread3,NULL);

	pthread_exit(&thread1);
	pthread_exit(&thread2);
	pthread_exit(&thread3);

	pthread_mutex_destroy(&lock);
	//pthread_cond_destroy(&cond);

	return 0;

}
