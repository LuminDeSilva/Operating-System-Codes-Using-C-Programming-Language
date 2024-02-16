#include<stdio.h>
#include<unistd.h>

int main()
{
   int B,C,p1[2],p2[2];
   pipe(p1);
   pipe(p2);
   B=fork();
   if(B==0)
   {
     int x,y;
     read(p1[0],&x,sizeof(x));
	 read(p1[0],&y,sizeof(y));
     
	 int sum=x+y;
	 write(p2[1],&sum,sizeof(sum));
	 
	 printf("I am B & first received %d ,Second received %d & sent %d\n",x,y,sum);
   
   }
   else{
	   int a=5,b=6,sum;
      write(p1[1],&a,sizeof(a));
      write(p1[1],&b,sizeof(b));
	  
	  read(p2[0],&sum,sizeof(sum));
      printf("I am A & sent %d,%d & received %d\n",a,b,sum);
   }
return 0;	
}
