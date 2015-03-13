#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
/*Write a method to replace all spaces in a string with ‘%20’.*/

void shiftstringright(char chars[1]);
int main()
{
	char chars[100]="a b c d e f g";
	bool bresult = true;

	printf("enter something\n");
	gets(chars);

	LARGE_INTEGER t1, t2, ts;
    QueryPerformanceFrequency(&ts);
    QueryPerformanceCounter(&t1);

    for(int i=0 ; i<strlen(chars) ; i++)
    {

        if(chars[i]==' ')
        {
            shiftstringright(&chars[i]);
            shiftstringright(&chars[i+1]);
            chars[i]='%';
            chars[i+1]='2';
            chars[i+2]='0';   
        }
    }

    printf("Result:%s\n", chars);
    QueryPerformanceCounter(&t2);
    printf("Lasting Time: %lf\n",(t2.QuadPart-t1.QuadPart)/(double)(ts.QuadPart));
	system("PAUSE");
	return 0;

}

void shiftstringright(char *start)
{
    char out ;
    char in = *start;;
    //To gain some space for new string
    for(start ; *start!='\0' ; start++)
    {
        out = *(start+1);
        *(start+1) = in;
        in = out;
    }

}