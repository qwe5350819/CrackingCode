#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
/*Write code to reverse a C-Style String. (C-String means that “abcd” is represented as five characters, including the null character.)*/


void reverseStrSwap(char str[50]);
int main()
{
    //use mychars to store input string
    char mychars[50]="DOGANDCAT\0";
    printf("input some string\n");
    scanf("%s",&mychars);
    //strcat(mychars,0);//add an 0 so strlen can process

    //start counting the time
    LARGE_INTEGER t1, t2, ts;
    QueryPerformanceFrequency(&ts);
    QueryPerformanceCounter(&t1);

    char *start = &mychars[0];
    reverseStrSwap(mychars);
    printf("Reverse result: %s \n",mychars);


    //stop counting time
    QueryPerformanceCounter(&t2);
    printf("\nLasting Time: %lf sec\n",(t2.QuadPart-t1.QuadPart)/(double)(ts.QuadPart));

	system("PAUSE");
	return 0;
}


void reverseStrSwap(char inputStr[])
{
    int strLength = strlen(inputStr);
    char temp;
    for(int i=0 ; i<strLength/2 ; i++)
    {
        if(strLength-i<1)
            break;
        //SWAP
        temp=inputStr[i];
        inputStr[i] = inputStr[strLength-1-i];
        inputStr[strLength-1-i] = temp;
    }
}