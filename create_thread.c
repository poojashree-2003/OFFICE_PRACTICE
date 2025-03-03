#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

//function where thread is used
void* thread_function(void *arg){ //this function will return void * and get void * arguments
                int *num=(int *)arg; //type casting the argument sent as void to int
                printf("The thread %d is running.\n" ,*num);
                pthread_exit(NULL); //exiting the thread after use
}

int main(){
        pthread_t threads[3];//array of threads
        int args[3]={1,2,3};//arguments to pass for each thread in the function
        
        
        //creating the threads
        for(int i=0;i<3;i++){
                if(pthread_create(&threads[i],NULL,thread_function,(void*)&args[i])!=0){
        		printf("Error creating a thread");
        		return 1;
		}
	}
	
	
	//using join to wait for prev thread to complete the process
        for(int i=0;i<3;i++){
                pthread_join(threads[i],NULL);
        }
        
        
	printf("All threads completed");
	return 0;
}
