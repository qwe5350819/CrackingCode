#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
//ctrl+b for compile
//ctrl+shift+b for exe

void removechar(char removethischar[1]);
int main()
{
	char chars[100]="qweeeeeeeeeeeeerrrrrrtewqerqwraegdbrx";
	bool bresult = true;
	char cduplicated;

	printf("enter something\n");
	scanf("%s",&chars);

	LARGE_INTEGER t1, t2, ts;
    QueryPerformanceFrequency(&ts);
    QueryPerformanceCounter(&t1);

    for(int i=0 ; i<strlen(chars) ; i++)
    {
    	cduplicated = chars[i];
    	//check whether there's duplicated char in the rest of the string
    	for(int j=i+1 ; j<strlen(chars)-1 ; j++)
    	{
    		if(chars[j]==chars[i])
    		{
    			removechar(&chars[j]);
    			i--;
    		}
    	}
    }

    printf("Result:%s\n", chars);
    QueryPerformanceCounter(&t2);
    printf("Lasting Time: %lf\n",(t2.QuadPart-t1.QuadPart)/(double)(ts.QuadPart));
	system("PAUSE");
	return 0;

}

void removechar(char *start)
{
	//overwrite the duplicated char with next chars
	for(start ; *start!='\0' ; start++)
		*start = *(start+1);
}