#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

pthread_mutex_t lock;
int pointer=0;
int check=0;

void* add(void* args){
	if(pthread_mutex_trylock(&lock)==0){
		int* arr=(int *)args;
		int sum;
		check=1;
		sum=arr[pointer]+arr[pointer+1];
		printf("The sum of pair[%d,%d]: %d\n",arr[pointer],arr[pointer+1],sum);
		pthread_mutex_unlock(&lock);
	}
	else{
		printf("The mutex is already in lock");
	}
	return NULL;
}

int main(){

	int size;
	int i;
	int track_thread=0;
	
	pthread_t thread[size];
	pthread_mutex_init(&lock,NULL);
	
	
	int* array=malloc(size*sizeof(int));
	
	
	while(1){
	printf("Enter size of the array: ");
	if(scanf("%d",&size)!=1 && size<=0){
		printf("ENTER VALID INPUT\n");
		while(getchar()!='\n');
		continue;
	}
	break;
	}

	for(i=0;i<size;i++){
element:
		printf("Enter element %d: ",i+1);
		if(scanf("%d",&array[i])!=1){
			printf("ENTER VALID INPUT\n");
			while(getchar()!='\n');
			goto element;
		}
		
	}
	
	while(pointer!=size-1){
		if(array[pointer]%2==0 && array[pointer+1]%2==0){
			pthread_create(&thread[track_thread],NULL,add,(void*)array);
			pthread_join(thread[track_thread++],NULL);	
		}
		pointer++;
	}
	if(check==0){
		printf("There is no even pair\n");
	}
	printf("--------------------------------------------------------------\n");
	int option;
	printf("1.CHANGE ARRAY\n");
	printf("2.EXIT\n");
option:
	printf("Enter your option: ");
	if(scanf("%d",&option)!=1 && (option!=1 || option!=2)){
		printf("ENTER VALID INPUT\n");
		while(getchar()!='\n');
		goto option;
	}
	if(option==1){
		free(array);
		pointer=0;
		check=0;
		main();
	}
	else{
		return 1;
	}
	
	pthread_mutex_destroy(&lock);	
}
