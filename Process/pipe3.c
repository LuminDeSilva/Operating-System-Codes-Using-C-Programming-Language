#include<stdio.h>
#include<unistd.h>

int main()
{
 int B,p1[2],p2[2],rs1,rs2;
 rs1=pipe(p1);
 rs2=pipe(p2);

 B=fork();
 if(B==0)
 {
   int a=5;
   close(p1[0]);
   write(p1[1],&a,sizeof(a));
   printf("I am Child B & I send %d\n",a);

   int rmsg;
   close(p2[1]);
   read(p2[0],&rmsg,sizeof(rmsg));
   printf("I am Child B & I receive from A %d\n",rmsg);
 }
 else
{
   int readmsg;
   close(p1[1]);
   read(p1[0],&readmsg,sizeof(readmsg));
   printf("I am Parent A & I receive %d\n",readmsg);

   close(p2[0]);
   write(p2[1],&readmsg,sizeof(readmsg));
   printf("I am Parent A & I send msg to B %d\n",readmsg);
 }
return 0;
}
