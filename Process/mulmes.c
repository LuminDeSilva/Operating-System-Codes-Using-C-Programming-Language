#include<stdio.h>
#include<unistd.h>

int main()
{
   int B,p1[2];
   pipe(p1);
   B=fork();
   if(B==0)
   {
     int x,y;
	 close(p1[1]);
     read(p1[0],&x,sizeof(x));
	 read(p1[0],&y,sizeof(y));
     printf("I am B & first received %d ,Second received %d\n",x,y);
   
   }
   else{
	   int a=5,b=6;
	  close(p1[0]);
      write(p1[1],&a,sizeof(a));
      write(p1[1],&b,sizeof(b));
      printf("I am A & sent %d,%d\n",a,b);
   }
return 0;	
}
