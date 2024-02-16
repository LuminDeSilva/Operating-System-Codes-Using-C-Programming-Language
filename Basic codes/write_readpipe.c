//write and read a message

#include<stdio.h>
int main() {
	int p[2],rv;
	rv=pipe(p);
	if (rv<0){
		printf("creating pipe is failed");
	    return -1;
}
char sendmsg[25]="Hello! good morning";
write(p[1],sendmsg,25);  //write the message to pipe using 'write' file descriptor

char readmsg[25];
read(p[0],readmsg,25);//read the message from pipe using 'read' file descriptor

printf("message read is %s\n", readmsg);
/*read(p[0],readmsg,10);   //read remain 10 characters
printf("message read is %s\n", readmsg);
*/
return 0;
}