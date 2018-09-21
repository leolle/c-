#include <iostream>
#include <math.h>
using namespace std;     

int main()
{
	float fahrenheit = 0, celsius=0;
	printf("\tF\tC\n");
	while (fahrenheit <= 300) 
	{
		celsius = (5.0/9) * (fahrenheit - 32);	//(5/9) will by default be computed as an integer division and will be zero. 
		printf("%10.1f%10.2f\n",fahrenheit,celsius);
		fahrenheit += 10;
	}
	return 0;
}
