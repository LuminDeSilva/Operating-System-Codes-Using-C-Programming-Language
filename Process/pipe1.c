#include<stdio.h>
#include<unistd.h>

int main()
{
 int B,p[2],rs;
 rs=pipe(p);

 B=fork();
 if(B==0)
 {
   int a=5;
   close(p[0]);
   write(p[1],&a,sizeof(a));
   printf("I am Child B & I send %d\n",a);
 }
 else
 {
   int readmsg;
   close(p[1]);
   read(p[0],&readmsg,sizeof(readmsg));
   printf("I am Parent A & I receive %d\n",readmsg);
 }
retrun 0;
} 
