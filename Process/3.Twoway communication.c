//method2 - function calling

#include<stdio.h>
int add(int,int);
int main(){
	int tochild[2], fromchild[2], pid;
	pipe(tochild);
	pipe(fromchild);
	
	pid=fork();
	if(pid==0){	
		sleep(1);
		int ca, cb, cs;
		close(tochild[1]);
		close(fromchild[0]);

		read(tochild[0], &ca, sizeof(ca));
		read(tochild[0], &cb, sizeof(cb));

		cs=add(ca,cb);
	
		write(fromchild[1],&cs,sizeof(cs));
	}

	else{	
		int pa, pb, ps;
		close(tochild[0]);
		close(fromchild[1]);

		printf("Enter the first number :");
		scanf("%d", &pa);

		printf("Enter the second number :");
		scanf("%d", &pb);

		write(tochild[1], &pa, sizeof(pa));
		write(tochild[1], &pb, sizeof(pb));

		sleep(1);

		read(fromchild[0],&ps,sizeof(ps));
		printf("sum= %d",ps);
	}

	return 0;
}
int add(int x, int y){
	int ans;
	ans=x+y;
	return ans;
}

output:
Enter the first number : 5
Enter the second number : 4
sum= 9