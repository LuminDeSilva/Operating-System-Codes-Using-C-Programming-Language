//creating a pipe

#include <stdio.h>


int main() {
    int p[2]; // Array to hold file descriptors for the pipe
    int rv;   // Return value of pipe()

    // Create the pipe using the pipe() function
    rv = pipe(p);

    // Check if the pipe creation was successful
            if (rv <0>) {
        perror("pipe is not created");
        else
        printf("pipe is created");
        return 0;
            }
   


   /*if (rv == -1) {
        perror("pipe() failed");
        return 1;*/ 
    }


