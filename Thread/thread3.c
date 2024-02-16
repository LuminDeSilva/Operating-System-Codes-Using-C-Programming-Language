#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#define NUM_THREADS 5

void *printHello(void *threadid){

        long tid;
        tid=(long)threadid;
        printf("Hello World! It's me thread %d\n",tid);
		pthread_exit(NULL);
}

int main(){

        pthread_t threads[NUM_THREADS];
        int rc;
        long t;
        for(t=0;t<NUM_THREADS;t++){
                printf("In main: creating thread %d\n",t);
                rc=pthread_create(&threads[t], NULL, printHello, (void *)t);
                if(rc!=0){
                        printf("ERROR: return code from pthread_create() is %d\n",rc);
                        exit(-1);
                }
        }

pthread_exit(NULL);
}



/*
..........

OR

cc -pthread thread1.c
./a.out
./a
*/