#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *oddoreven(void *value) {
	int* n=(int*) value;
	int m= *n;
	
	if(m%2==1)
    printf("hello from the second thread & number is Odd \n");
    else
	printf("hello from the second thread & number is even \n");

	pthread_exit(NULL); 
}
void *remof10(void *value) {
	int *n=(int *)value;
	int m= *n;
	
	int rem=m%10;
	printf("hello from the third thread & Reminder is %d \n",rem);
    pthread_exit(NULL); 
}


int main() {
    pthread_t thread2,thread3;

    printf("hello from the first thread \n");

    int num = 123;

    pthread_create(&thread2, NULL, oddoreven, &num);
	pthread_create(&thread3, NULL, remof10, &num);

	pthread_exit(NULL); 

    return 0;
}





/*
cd d:/
cd d:/Temp
ls
vi first.c
gcc -o first first.c -lpthread
./first
rm first
*/

/*
OR

vi first.c
gcc first.c -lpthread
./a.out or 
./a
*/