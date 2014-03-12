#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

using namespace std;
//ctrl+b for compile
//ctrl+shift+b for exe
int main()
{
	int i = 19,j;
	int *addi;
	addi = &i;

	printf("%d,%d,%d,%d\n",i,&i,addi,*addi );

	return 0;
}