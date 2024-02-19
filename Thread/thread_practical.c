#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void *test(){
    printf("Hello everyone");
    pthread_exit(NULL);
}

void *test1(){
    printf("How was the day?");
    pthread_exit(NULL);
}

int main(){
    pthread_t thread,thread1;
    printf("Nice day!!!");
    pthread_create(&thread,NULL,test,NULL);
    pthread_create(&thread1,NULL,test1,NULL);
    pthread_exit(NULL);
    return 0;
}