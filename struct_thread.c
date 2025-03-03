#include<stdio.h>
#include<pthread.h>

//structure
typedef struct{
        int id; 
        char name[20];
}ThreadData;

//function for thread
void* printelem(void* arg){

        ThreadData* data=(ThreadData*)arg;//type casting to struct type

        printf("ID:%d\n Name:%s\n",data->id,data->name);//printing the details

        return NULL;
}


int main(){
        pthread_t thread1; //declare the thread

        ThreadData tdata={1,"POOJA"}; //details given to store in the struct

        pthread_create(&thread1,NULL,printelem,&tdata); //creating the pthread

        pthread_join(thread1,NULL);//ensuring pthread completed the work

        return 0;
}   
