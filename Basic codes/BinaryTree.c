#include <stdio.h>
#include <unistd.h>

int main() {
    int B, C, D, E, F, G;
    B = fork();

    if (B == 0) {
        // This block will be executed by the first child (B)
        D = fork();
        if (D == 0) {
            // This block will be executed by the second child (D)
            printf("D pid is %d ppid is %d\n", getpid(), getppid());
        } else {
            // This block will be executed by the first child (B)
            printf("B pid is %d ppid is %d\n", getpid(), getppid());
            E = fork();
            if (E == 0) {
                // This block will be executed by the third child (E)
                printf("E pid is %d ppid is %d\n", getpid(), getppid());
            }
        }
    } else {
        // This block will be executed by the parent process
        C = fork();
        if (C == 0) {
            // This block will be executed by the second child (C)
            F = fork();
            if (F == 0) {
                // This block will be executed by the fourth child (F)
                printf("F pid is %d ppid is %d\n", getpid(), getppid());
            } else {
                // This block will be executed by the second child (C)
                G = fork();
                if (G == 0) {
                    // This block will be executed by the fifth child (G)
                    printf("G pid is %d ppid is %d\n", getpid(), getppid());
                } else {
                    // This block will be executed by the second child (C)
                    printf("C pid is %d ppid is %d\n", getpid(), getppid());
                }
            }
        } else {
            // This block will be executed by the parent process
            printf("A pid is %d\n", getpid());
        }
    }
}




/*The original process (parent process) forks and creates a child process B.
Child process B continues execution from where it was forked. It then forks again and creates child process D.
Child process B (original) prints its PID and its parent's PID (PPID).
Child process B continues execution and forks again, creating child process E.
Child process D (created by B) prints its PID and its parent's PID (PPID).
Child process B (original) continues execution and exits the first if block.
The parent process (original) continues execution, forks again, and creates child process C.
Child process C continues execution from where it was forked. It then forks again and creates child process F.
Child process C (original) prints its PID and its parent's PID (PPID).
Child process F (created by C) prints its PID and its parent's PID (PPID).
Child process C (original) continues execution and forks again, creating child process G.
Child process G (created by C) prints its PID and its parent's PID (PPID).
The parent process (original) continues execution and exits the second if block.
The parent process (original) prints its PID.*/