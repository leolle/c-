#include <stdio.h>
int main()
{
    using namespace std;
	int number, n_power, multiple;
	printf("Please enter a number:\n");
	scanf_s("%d",&number);
	printf("Please enter a power:\n");
	scanf_s("%d",&n_power);
	multiple = number << n_power;
	printf("%d multiples by a factor 2 to the power %d is %d:\n",number, n_power, multiple);
    return 0;
}