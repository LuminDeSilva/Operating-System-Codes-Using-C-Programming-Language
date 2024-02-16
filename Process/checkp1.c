#include<stdio.h>
#include<unistd.h>

int main()
{
   int B,C,p1[2],p2[2];
   int rs1=pipe(p1);
   int rs2=pipe(p2);
   if(rs1<0)
	   printf("Unable to create the pipe1!!");
   if(rs2<0)
	   printf("Unable to create the pipe2!!");
   B=fork();
   if(B==0)
   {
     int a;
     read(p1[0],&a,sizeof(a));
     printf("I am B & received %d\n",a);
   
   }
   else{
	  int b=5;
      write(p1[1],&b,sizeof(b));
      write(p2[1],&b,sizeof(b));
      printf("I am A & sent %d\n",b);
     
      C=fork();
      if(C==0)
      {
        int c;
	    read(p2[0],&c,sizeof(c));
	    printf("I am C & received %d\n",c);
      }
   }
return 0;	
}
