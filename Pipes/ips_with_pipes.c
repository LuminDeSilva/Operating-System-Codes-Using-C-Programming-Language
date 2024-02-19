//write 10 messages to a pipe with 1s interval
#include<stdio.h>
#include<unistd.h>

int main()
{
        int p[2];
        pipe(p);

        if(fork()==0)
        {
                for(int j=0; j<10; j++)
                {
                        char message[20];
                        read(p[0],message,20);
                        printf("%d Read message from Parent %s \n",j,message);
						//sleep(2);
                }
        }
        else
        {
                char* msgFromParent = "From Parent";
                for(int i=0; i<10; i++)
                {
                        write(p[1],msgFromParent,20);
                        printf("%d Message Sent to pipe from parent \n",i);
                        sleep(1);
                }
        }
        return 0;
}

/*
0 Message Sent to pipe from parent
0 Read message from Parent From Parent
1 Message Sent to pipe from parent
1 Read message from Parent From Parent
2 Message Sent to pipe from parent
2 Read message from Parent From Parent
3 Message Sent to pipe from parent
3 Read message from Parent From Parent
4 Message Sent to pipe from parent
4 Read message from Parent From Parent
5 Message Sent to pipe from parent
5 Read message from Parent From Parent
6 Message Sent to pipe from parent
6 Read message from Parent From Parent
7 Message Sent to pipe from parent
7 Read message from Parent From Parent
8 Message Sent to pipe from parent
8 Read message from Parent From Parent
9 Message Sent to pipe from parent
9 Read message from Parent From Parent
*/

---------------------------------------------------------
//parent read 10 int values from user
//child1 read 5 from A and find the avg
//child2 read 5 valu from A and find the avg
//*)p1 10 val from parent to child1
//*)p2 2 value child to parent