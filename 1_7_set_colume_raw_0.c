#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
//ctrl+b for compile
//ctrl+shift+b for exe

void set_row_colume_1(int **Matrix , int ix, int iy , int iCoordinateX, int iCooredinateY);
int** dynamicINTMatrixMN(int M,int N);
void assignMatrixRand(int range,int** Matrix ,int x ,int y);
void printMatrix(int** Matrix,int iM ,int iN);
void freeDynamicMatrix(int** Matrix , int iM , int iN);
void assignMatrix0(int** Matrix, int x ,int y);
int main()
{
    int iM=5,iN=10;
	int **Matrix , **recordTable;
    bool bresult = true;
    long temp;

	printf("M x N matrix ,enter M , N\n");
    scanf("%d",&iM);
    scanf("%d",&iN);

    Matrix = dynamicINTMatrixMN(iM,iN);
    recordTable = dynamicINTMatrixMN(iM,iN);
    assignMatrixRand(20,Matrix,iM ,iN);
    assignMatrix0(recordTable,iM ,iN);
    printMatrix(Matrix,iM ,iN);    

	LARGE_INTEGER t1, t2, ts;
    QueryPerformanceFrequency(&ts);
    QueryPerformanceCounter(&t1);


    //recording 0 position
    for(int x = 0 ; x < iM ; x++)
    {
        for(int y = 0 ; y < iN ; y++)
        {
            if(Matrix[x][y]==0)
            {
                set_row_colume_1(recordTable,iM,iN,x,y);
                break;
            }
        }
    }

    //set 0
    for(int x = 0 ; x < iM ; x++)
    {
        for(int y = 0 ; y < iN ; y++)
        {
            if(recordTable[x][y]!=0)
                Matrix[x][y]=0;
        }
    }

    //print Matrix
    printf("------------------------------------\nResult:\n");
    printMatrix(Matrix,iM ,iN);
    freeDynamicMatrix(Matrix , iM , iN);

    QueryPerformanceCounter(&t2);
    printf("Lasting Time: %lf\n",(t2.QuadPart-t1.QuadPart)/(double)(ts.QuadPart));
	system("PAUSE");
	return 0;

}

void set_row_colume_1(int **Matrix ,int iXMax , int iYMax ,int iCoordinateX, int iCooredinateY)
{
    for(int i=0;i<iXMax;i++)
        Matrix[i][iCooredinateY]=1;
    for(int j=0;j<iYMax;j++)
        Matrix[iCoordinateX][j]=1;
}

int** dynamicINTMatrixMN(int m,int n){
    //memory location for NxN matrix
    int **memoryMatrix;
    memoryMatrix = (int **)malloc(n*sizeof(int *));//4 byte for long
    for(int i=0;i<m;i++)
        memoryMatrix[i] = (int *)malloc(n*sizeof(int *));
    return memoryMatrix;
}

void assignMatrixRand(int range,int** Matrix, int x ,int y)
{
    //assign value to NxN matrix
    range++;
    int lvalue ;
    for(int i = 0 ; i<x ; i++)
    {
        for(int j=0 ; j<y ; j++)
        {
            lvalue = rand()%range;//0~20
            Matrix[i][j]=lvalue;
        }
    }
}

void assignMatrix0(int** Matrix, int x ,int y)
{
    //assign value to NxN matrix
    for(int i = 0 ; i<x ; i++)
    {
        for(int j=0 ; j<y ; j++)
            Matrix[i][j]=0;
    }
}


void printMatrix(int** Matrix,int iM ,int iN)
{
    for(int i = 0; i < iM ; i++)
    {
        for(int j = 0 ; j < iN ; j++)
            printf("%-5ld",Matrix[i][j] );
        printf("\n");
    }
}

void freeDynamicMatrix(int** Matrix , int iM , int iN)
{
    free(Matrix);
    for(int i = 0 ; i < iM ; i++)
        free(Matrix[i]);
}
