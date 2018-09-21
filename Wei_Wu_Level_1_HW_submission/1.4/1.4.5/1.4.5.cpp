#include <iostream>
#include <math.h>
using namespace std;     

int main()
{
	float fahrenheit = 0;
	printf("\tC\tF\n");
	for (float celsius = 0; celsius <= 19; celsius++)
	{
		fahrenheit = celsius*1.8 + 32;	//(5/9) will by default be computed as an integer division and will be zero. 
		printf("%10.1f,%10.2f\n",celsius,fahrenheit);

	}
	return 0;
}
