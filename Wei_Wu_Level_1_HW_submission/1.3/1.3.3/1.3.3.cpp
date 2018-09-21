/* Operators */
#include <stdio.h>
int main()
{
int x;
x=-3+4*5-6;				//x is -3 added by the multiple of 4 and 5, then subtracted by 6.
printf("x=%d\n", x);
x=3+4%5-6;				//x is 3 added by the remainder of 4 devided by 5, then subtracted by 6.
printf("x=%d\n", x);
x=-3*4%-6/5;			//-3 multiples 4 is devided by -6, then remainder 0 is devided by 5.
printf("x=%d\n", x);
x=(7+6)%5/2;			//7 plus 6, the sum 13 is devided by 5, 
						//the reminder 3 then is devided by 2, the result is 1.
						
						
printf("x=%d\n", x);
return 0;
}