#include<stdio.h>
#include<stdlib.h>

int main()
{
    int* num=(int*)calloc(5,sizeof(int));   //Allocate memory for 5 integers and initialize them to zero

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
        printf("%d ",num[i]);    //Print values
    }

    printf("\n");

    int* resized_num=(int*)realloc(num,10*sizeof(int)); //Resize the allocated memory to hold 10 memory

    if(resized_num==NULL)
    {
        printf("Memory reallocation failed");
        free(num);  //Deallocate original memory
        return 1;
    }

    for(int i=5;i<10;i++)
    {
        resized_num[i]=i+1; //Assign values to the new elements
    }

    for(int i=0;i<10;i++)
    {
        printf("%i ",resized_num[i]);   //Print all values
    }

    printf("\n");

    free(resized_num);  //Deallocate memory

    return 0;
}
/*
1 2 3 4 5
1 2 3 4 5 6 7 8 9 10

Process returned 0 (0x0)   execution time : 0.037 s
Press any key to continue.
*/
