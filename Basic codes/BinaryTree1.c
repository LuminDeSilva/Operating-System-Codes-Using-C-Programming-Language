#include<stdio.h>
#include<unistd.h>
int main(){
	int B,C,x=372,n=0,r=x;
	
	B=fork();
	if (B==0)
	{
		printf("B pid is %d ppid is %d\n",getpid(),getppid());
		while(r>0)
		{
			n=n+(r%10);
			r=r/10;
		}
		printf("digit sum of %d =%d\n",x,n);
	}
	else
	{
		printf(" A pid is %d ppid id is %d\n",getpid(),getppid());
		printf("Index value=%d\n",x);
		
		C=fork();
		if(C==0)
		{
			printf("C pid is %d ppid is %d\n",getpid(),getppid());
			if(x%2==0)
			{
				printf("%d is even number\n",x);
			}
				else
				{
					printf("%d is odd number\n",x);
			}
		
		P=fork();
		if(P==0)
		{
			printf(" pid is %d ppid id is %d\n",getpid(),getppid());
	    while (x>0)
		{
			printf("%d",(x%10));
			x=x/10;
		}
		}
		}
	}
	return 0;
}