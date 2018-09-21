#include <iostream>
#include <stdio.h>
int main()
{
    using namespace std;
	int x , y;
	printf("Please enter a number :\n");
	scanf_s("%d",&x);
	y = x >> 2;
	printf("The number %d shifts two places to the right is %d.\n", x, y);	

	if (x & 0x8000)		//to check if MSB is 1.
	{
		if ( y & 0x8000)	//if MSB of x is 1, and the MSB of shifted number is 1
		{
			printf("this is an arithmetic shift.\n");	
		}
		else
		{
			printf("this is a logical shift.\n");	
		}

	}
	else
	{
		printf("this is a logical shift.\n");	
	}

    return 0;
}