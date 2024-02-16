//Oneway communication

//Parent wants to send a message to child
#include<unistd.h>
#include<stdio.h>
int main(){
	int p[2],rv,id;
	rv=pipe(p);
	
	if(rv==-1){
		printf("Creating pipe is failed");
		return -1;
	}
	
	id=fork();
	if(id<0){
		printf("Creating the child is failed");
		return -1;
	}

	if(id>0){	
		char sendmsg[30]="Hi my son, how are you?";
		close(p[0]);
		write(p[1],sendmsg,30);
	}

	else{	//child
		char readmsg[30];
		close(p[1]);
		read(p[0],readmsg,30);
		printf("Message received by child :\n\t%s\n",readmsg);
	}

	return 0;
}

output:
Message received by child :
	Hi my son, how are you?