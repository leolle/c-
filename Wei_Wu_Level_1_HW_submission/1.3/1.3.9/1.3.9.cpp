/* Conditional expressions */
#include <stdio.h>
int main()
{
	int x=1;
	int y=1;
	int z=1;
	x+=y+=x;			//from right to left, first of all, calculate y = x + y = 1 + 1 = 2
						//then calculate x = x + y = 1 + 2 = 3						

	printf("%d\n\n", (x<y)?y:x); 
	// Number 1, if x < y, print y, or print x.
	//because (x = 3) > (y = 2), so x < y is false, print x

	printf("%d\n", (x<y)?x++:y++); 
	// Number 2, if x < y, print y and then incrementing value of y, 
	//or print x and then incrementing value of x.
	//because (x = 3) > (y = 2), so x < y is false, print 2, then incrementing value of y, y = 3

	printf("%d\n", x); 
	// Number 3, print value of x, x = 3
	
	printf("%d\n", y); 
	// Number 4, print value of y, y = 3 because of number 2
	
	return 0;
}