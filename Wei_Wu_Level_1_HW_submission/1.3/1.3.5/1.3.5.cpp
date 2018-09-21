#include <iostream>
#include <stdio.h>

int main()
{
	int i = 2;
	int j = --i;	//--i will decrements the value of i, and then return the decremented value.
					//j is 1, i is 1.
	printf("i is %d, j is %d\n", i , j);	

	i = 2;
	j = i--;	//i-- will return the value of i, then decrements the value of i.
					//j is 2, i is 1.
	printf("i is %d, j is %d\n", i , j);	

    return 0;
}