#include<stdio.h>
#include<unistd.h>
int main(){
	int B,C,D,E,F,G;
	B=fork();
	
	if(B==0){
		D=fork();
		if(D==0){
			printf("D pid is %d ppid is %d\n",getpid(),getppid());
		}
		else
		{
			printf("B pid is %d ppid is %d\n",getpid(),getppid());
			E=fork();
			if(E==0){
			printf("E pid is %d ppid is %d\n",getpid(),getppid());
			}
		}
	}
	else{
		C=fork();
		if(C==0){
			F=fork();
			if(F==0){
				printf("F pid is %d ppid is %d\n",getpid(),getppid());
			}
			else{
				G=fork();
				if(G==0){
					printf("G pid is %d ppid is %d\n",getpid(),getppid());	
				}
                else{
					printf("C pid is %d ppid is %d\n",getpid(),getppid());
				}
			}	
		}
		else{
			printf("A pid is %d\n",getpid());
		}
	}	
}