// creating a child process

#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        // Fork failed
        fprintf(stderr, "Fork failed.\n");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("This is the child process.\n");
        printf("Child PID: %d\n", getpid());
    } else {
        // Parent process
        printf("This is the parent process.\n");
        printf("Parent PID: %d\n", getpid());
        printf("Child PID: %d\n", pid);
    }

    return 0;
}

/*To create a child process in C, you can use the fork() system call.
 The fork() function creates a new process (child process) that is an identical copy of the calling process (parent process). Both the parent and child processes continue execution from the point where the fork() function was called, but they have different process IDs. The return value of fork() is different in the parent and child processes. 
It returns the PID of the child process to the parent and 0 to the child.*/