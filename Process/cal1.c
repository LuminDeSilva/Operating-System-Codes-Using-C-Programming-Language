#include<stdio.h>
#include<unistd.h>

int main()
{
	int B,C,D,E,AB[2],AC[2],AD[2],BA[2],CA[2],DA[2],AE[2],EA[2];
	pipe(AB),pipe(AC),pipe(BA),pipe(CA),pipe(AD),pipe(DA),pipe(AE),pipe(EA);
	int num1,num2;
	
	printf("Enter the first number:");
	scanf("%d",&num1);
	
	printf("Enter the second number:");
	scanf("%d",&num2);
	
	B=fork();
	if(B==0)
	{
		int num1,num2,sum;
		read(AB[0],&num1,sizeof(num1));
		read(AB[0],&num2,sizeof(num2));
		sum=num1+num2;
		//printf("Sum = %d\n",sum);
		write(BA[1],&sum,sizeof(sum));
	}
	else{
		write(AB[1],&num1,sizeof(num1));
		write(AB[1],&num2,sizeof(num2));
		write(AC[1],&num1,sizeof(num1));
		write(AC[1],&num2,sizeof(num2));
		write(AD[1],&num1,sizeof(num1));
		write(AD[1],&num2,sizeof(num2));
		write(AE[1],&num1,sizeof(num1));
		write(AE[1],&num2,sizeof(num2));
		
		C=fork();
		if(C==0)
		{
			int num1,num2,sub;
		    read(AC[0],&num1,sizeof(num1));
		    read(AC[0],&num2,sizeof(num2));
		    sub=num1-num2;
		    //printf("Sub = %d\n",sub);
			write(CA[1],&sub,sizeof(sub));
		}
		else
		{
			D=fork();
			if(D==0)
			{
				int num1,num2,mul;
				read(AD[0],&num1,sizeof(num1));
				read(AD[0],&num2,sizeof(num2));
				mul=num1*num2;
				//printf();
				write(DA[1],&mul,sizeof(mul));
			}
			else{
				E=fork();
				if(E==0)
			   {
				int num1,num2,rem;
				read(AE[0],&num1,sizeof(num1));
				read(AE[0],&num2,sizeof(num2));
				rem=num1%num2;
				//printf();
				write(EA[1],&rem,sizeof(rem));
			   }
				
		    else{
			int sum,sub,mul,rem;
			read(BA[0],&sum,sizeof(sum));
		    read(CA[0],&sub,sizeof(sub));
			read(DA[0],&mul,sizeof(mul));
			read(EA[0],&rem,sizeof(rem));
		    printf("Sum = %d\n",sum);
			printf("Sub = %d\n",sub);
			printf("Mul = %d\n",mul);
			printf("Rem = %d\n",rem);
		    }
		  }
		}
	}
	
	return 0;
}