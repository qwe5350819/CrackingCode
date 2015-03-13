#include <iostream>
#include <stdlib.h>
#include <stdio.h>
/*How would you design a stack which, in addition to push and pop, also has a function min which returns the minimum element? Push, pop and min should all operate in O(1) time.*/

int * createArray(int iSize)
{
    int *Array;

    //make space for array
    Array = (int *)malloc(iSize*sizeof(int *));

    //initialize every element 0
    for (int j = 0; j < iSize; ++j)
        Array[j]= rand()%10+1;
    return Array;
}

void print1DArray(int *Arr,int iSize)
{
    printf("=================\n");
    for (int i = 0; i < iSize; ++i)
        printf("->%d", Arr[i]);
    printf("\n");
}

//push the content value to the top of stacks
void push(int* myStacks ,int iSize , int content)
{
    int i=0;
    for (i = 0; i < iSize; i++)
    {
        if (myStacks[i]==0)
                break;
    }
    myStacks[i]=content;
}

//return the min value of mystack
int min(int * myStacks,int iSize)
{
    int iMin=myStacks[0];
    for (int i = 1; i < iSize; ++i)
    {
        if (myStacks[i]<iMin)
            iMin=myStacks[i];
    }
    return iMin;
}

//pop the element on the top of stack 
void pop(int* myStacks , int iSize )
{
    int i;
    for (i = 0; i < iSize; ++i)
    {
        if (myStacks[i]==0)
            break;
    }
    myStacks[i-1]=0;
}

int main() {
    int * testArray;
    int stackSize=10;
    testArray = createArray(stackSize);
    print1DArray(testArray,stackSize);
    pop(testArray,stackSize);
    print1DArray(testArray,stackSize);
    push(testArray,stackSize,77);
    print1DArray(testArray,stackSize);
    printf("Min:%d",min(testArray,stackSize));
    print1DArray(testArray,stackSize);

    free(testArray);
    system("PAUSE");
    return 0;
}