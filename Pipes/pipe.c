#include<stdio.h>
#include<unistd.h>

int main()
{
        char* message = "hello";

        int pipe1[2];

        pipe(pipe1);

        write(pipe1[1],message,10);

        char receiver[10];

        read(pipe1[0],receiver,10);

        printf("Received the message '%s' from pipe1\n",receiver);

        return 0;
}

//Received the message 'hello' from pipe1

---------------------------------------------------

#include<stdio.h>
#include<unistd.h>

int main()
{
        char* message = "hello";

        int pipe1[2];

        pipe(pipe1);

        write(pipe1[1],message,10);

        char receiver1[10];
        char receiver2[10];

        read(pipe1[0],receiver1,10);
        printf("Received the message '%s' from pipe1\n",receiver1);

        read(pipe1[0],receiver2,10);
        printf("Received the message '%s' from pipe1\n",receiver2);

        return 0;
}

/*
[2019ict37@fedora ~]$ ./pipe
Received the message 'hello' from pipe1

^C
*/