#include <iostream>
#include <stdlib.h>
#include <stdio.h>
//ctrl+b for compile
//ctrl+shift+b for exe
// Describe how you could use a single array to implement three stacks.

int ** createArray(int m , int n)
{
    int i;
    int **Array, *pData;

    //make space for array
    Array = (int **)malloc(m*sizeof(int *)+m*n*sizeof(int));
    for (i = 0, pData = (int *)(Array+m); i < m; i++, pData += n)
    Array[i]=pData;

    //set every element 0
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
            Array[i][j]= 0 ;
    }

    return Array;
}

void assignIntArray(int **Arr,int m , int n)
{
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
            Arr[i][j]= i + j ;
    }
}


void print2DDyArray(int **Arr,int m , int n)
{
    printf("=================\n");
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
            printf("%-3d", Arr[i][j]);
        printf("\n");
    }
}

void pushStack(int** myStacks , int stackSize ,int stacknum, int content)
{
    int lastIn=0;
    for (int i = 0; i < stackSize; i++)
    {
        if (myStacks[stacknum-1][i]==0)
        {
            lastIn=i;
            break;
        }
    }
    myStacks[stacknum-1][lastIn]=content;
}


void popStack(int** myStacks , int stackSize , int stacknum )
{
    int lastIn;
    for (int i = 0; i < stackSize; ++i)
    {
        if (myStacks[stacknum-1][i]==0)
            lastIn=i-1;
    }
    myStacks[stacknum-1][lastIn]=0;
}

int main() {
    int ** testArray;
    testArray = createArray(3,4);
    print2DDyArray(testArray,3,4);

    pushStack(testArray,4,3,2);
    print2DDyArray(testArray,3,4);
    pushStack(testArray,4,3,2);
    print2DDyArray(testArray,3,4);
    pushStack(testArray,4,3,2);
    print2DDyArray(testArray,3,4);
    popStack(testArray,4,3);
    print2DDyArray(testArray,3,4);


    free(testArray);
    system("PAUSE");
    return 0;
}