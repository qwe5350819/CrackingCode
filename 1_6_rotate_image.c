#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
//ctrl+b for compile
//ctrl+shift+b for exe

int main()
{
    int iN=10;
	long **Matrix;
    bool bresult = true;
    long temp;

	printf("N x N matrix ,enter N\n");
	scanf("%d",&iN);

    //memory location for NxN matrix
    Matrix = (long **)malloc(iN*sizeof(long *));//4 byte for long
    for(int i=0;i<iN;i++)
    {
        Matrix[i] = (long *)malloc(iN*sizeof(long *));
    }

    //assign value to NxN matrix
    long value = 0;
    for(int i = 0 ; i<iN ; i++)
    {
        for(int j=0 ; j<iN ; j++)
        {
            Matrix[i][j]=value;
            value++;
            printf("%ld,",Matrix[i][j] );
        }
        printf("\n");
    }

	LARGE_INTEGER t1, t2, ts;
    QueryPerformanceFrequency(&ts);
    QueryPerformanceCounter(&t1);

    //rotate
    for(int x = 0 ; x < iN-x ; x++)
    {
        for(int y = x ; y < iN-1-x ; y++)
        {
            // printf("========\ni = %d\n", y );
            temp = Matrix[x][y];
            // printf("Matrix[%d][%d] = %ld \n",x,y, Matrix[y][iN-1-x]);
            Matrix[x][y] = Matrix[y][iN-1-x];
            // printf("Matrix[%d][%d] = %ld \n",y,iN-1-x, Matrix[iN-1-x][iN-1-y]);
            Matrix[y][iN-1-x] = Matrix[iN-1-x][iN-1-y];
            // printf("Matrix[%d][%d] = %ld \n",iN-1-x,iN-1-y, Matrix[iN-1-y][x]);
            Matrix[iN-1-x][iN-1-y] = Matrix[iN-y-1][x];
            // printf("Matrix[%d][%d] = %ld \n",iN-1-y,x, temp);
            Matrix[iN-y-1][x] = temp;
        }
    }

    //print Matrix
    printf("------------------------------------\nResult:\n");
    for(int i = 0; i < iN ; i++)
    {
        for(int j = 0 ; j < iN ; j++)
            printf("%ld,",Matrix[i][j] );
        printf("\n");
    }


    free(Matrix);
    for(int i = 0 ; i < iN ; i++)
        free(Matrix[i]);
    QueryPerformanceCounter(&t2);
    printf("Lasting Time: %lf\n",(t2.QuadPart-t1.QuadPart)/(double)(ts.QuadPart));
	system("PAUSE");
	return 0;

}


