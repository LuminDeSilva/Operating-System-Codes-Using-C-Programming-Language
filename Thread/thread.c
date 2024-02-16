#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *entry_point() {
    printf("hello from the second thread \n");
	pthread_exit(NULL);
}

int main() {
    pthread_t thread;

    printf("hello from the first thread \n");

    pthread_create(&thread, NULL, entry_point, NULL);
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