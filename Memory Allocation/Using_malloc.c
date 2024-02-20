#include<stdio.h>
#include<stdlib.h>

int main()
{
    int* num=(int*)malloc(5*sizeof(int));   //Allocate memory for 5 integers

    if(num==NULL)
    {
        printf("Memory allocation failed");
        return 1;
    }

    for(int i=0;i<5;i++)
    {
        num[i]=i+1; //Assign values
    }

    for(int i=0;i<5;i++)
    {
        printf("%i ",num[i]);   //Print values
    }

    printf("\n");

    free(num);  //Deallocate memory

    return 0;
}
/*
1 2 3 4 5

Process returned 0 (0x0)   execution time : 0.030 s
Press any key to continue.
*/
