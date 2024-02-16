//get the process id for the process

#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = getpid();

    printf("Process ID: %d\n", pid);

    return 0;
}


/*In this example, getpid() returns the PID of the current process, 
and it is stored in the variable pid. 
The PID is then printed using printf(). */ 