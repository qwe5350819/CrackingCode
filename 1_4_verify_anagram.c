#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

//ctrl+b for compile
//ctrl+shift+b for exe
int main()
{
	int charcount[256]={0};
	char chars[100]={0};
	char anagram[100]={0};
	bool result = true;

	printf("enter something\n");
	scanf("%s",&chars);
	printf("enter anagram\n");
	scanf("%s",&anagram);

	LARGE_INTEGER t1, t2, ts;
    QueryPerformanceFrequency(&ts);
    QueryPerformanceCounter(&t1);

    if(strlen(chars)==strlen(anagram))
    {
    	for(int i=0 ; i<strlen(chars) ; i++)
    	{
    		charcount[(int)chars[i]]++;
    		charcount[(int)anagram[i]]--;
    	}
	}

	for(int i=0 ; i<256 ; i++)
	{
		if(charcount[i]>0)
		{
			result = false;
			break;
		}
	}

	if(result)
		printf("This is anagram.\n");
	else
		printf("Not anagram\n");

    QueryPerformanceCounter(&t2);
    printf("Lasting Time: %lf\n",(t2.QuadPart-t1.QuadPart)/(double)(ts.QuadPart));
	system("PAUSE");
	return 0;

}