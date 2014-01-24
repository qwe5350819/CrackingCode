#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
using namespace std;

int main()
{
    //use mychars to store input string
    char mychars[50];
    printf("\ninput some string\n");
    fflush(stdin);
    scanf("%s",&mychars);
    bool duplicate= false;

    //start counting the time
    LARGE_INTEGER t1, t2, ts;
    QueryPerformanceFrequency(&ts);
    QueryPerformanceCounter(&t1);

    
    for(int i=0 ; i<strlen(mychars) ; i++)
    {
        for(int j=i+1 ; j<strlen(mychars) ; j++)
        {
            if(mychars[i]==mychars[j])
            {
                printf("\nString has duplicated chars.");
                duplicate = true;
                break;
            }
        }
        if(duplicate)
        {
            break;
        }
    }
    if(duplicate==false)
        printf("\nunique");



    //stop counting time
    QueryPerformanceCounter(&t2);
    printf("\nLasting Time: %lf\n",(t2.QuadPart-t1.QuadPart)/(double)(ts.QuadPart));

	system("PAUSE");
	return 0;
}
