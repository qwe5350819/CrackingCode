#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
/*
Assume you have a method isSubstring which checks if one word is a substring of another. Given two strings, s1 and s2, write code to check if s2 is a rotation of s1 using only one call to isSubstring (i.e., “waterbottle” is a rotation of “erbottlewat”).
*/

bool isSubstring(char str1[20], char str2[20]);
int main()
{
    char s1[20]="hello\0";
    char s2[20]="olleh\0";
    int chose=1;

	printf("String 1 , String 2 \n");
    gets(s1);
    gets(s2);
    fflush(stdin);
    printf("1). Rotation\n2). Substring\n");
    scanf(" %[^\n]",chose);
	LARGE_INTEGER t1, t2, ts;
    QueryPerformanceFrequency(&ts);
    QueryPerformanceCounter(&t1);


    switch(chose)
    {
        case 1://rotation
            char temp;
            for(int i = 0 , j = strlen(s2)-1 ; i < j;i++,j--)
            {
                temp=s2[i];
                s2[i]=s2[j];
                s2[j]=temp;
            }
            if(isSubstring(s1,s2))
                printf("This is rotation.\n");
            else
                printf("This is not rotation.\n");
            break;
        case 2://substring
            if(isSubstring(s1,s2))
                printf("This is substring.\n");
            else
                printf("This is not substring.\n");        
            break;
        default:
            ;
    }


    QueryPerformanceCounter(&t2);
    printf("Lasting Time: %lf\n",(t2.QuadPart-t1.QuadPart)/(double)(ts.QuadPart));
	system("PAUSE");
	return 0;

}

//compare the char one by one
bool isSubstring(char str1[20], char sub[20])
{
    bool find = false;
    for(int i=0 ; i<strlen(str1)-strlen(sub)+2 ; i++)
    {
        for(int j = 0 ; j < strlen(sub) ; j++)
        {
            if(str1[i]==sub[j])
            {
                for(int k=0;k<strlen(sub);k++)
                {
                    if(str1[i+k]!=sub[k])
                        break;
                    if(k=strlen(sub)-1)
                        find=true;
                }
            }else
                break;
        }
        if(find)
            break;
    }
    return find;
}