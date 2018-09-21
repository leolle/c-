/* Assignment operators */
#include <stdio.h>
int main()
{
	int x=2;
	int y;
	int z;
	x*=3+2;					//x = x * (3 + 2) = 10				
	printf("x=%d\n", x);
	x*=y=z=4;				//z = 4, y = z, y = 4, x = x * y = 10*4 = 40
	printf("x=%d\n", x);
	x=y==z;					//x is the logical value of if y equals to z, which is true, thus x  = TRUE, x = 1.
	printf("x=%d\n", x);
	return 0;
}