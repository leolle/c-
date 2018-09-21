#include <stdio.h>

void Swap(int* a, int* b)
{
	int temp;		//use the variable temp to store one value.
	temp = (*b);	//temp equals to content of pointer b
	(*b) = (*a);	//pointer b equals to content of pointer a
	(*a) = temp;	//content of pointer a equals to temp

}
int main()
{
	int i = 123, j = 456;
	int* x = &i;	//x points to i
	int* y = &j;	//y points to j
	printf("Before swapping: i = %d, j = %d\n",i , j);

	Swap( x, y);
	printf("After swapping: i = %d, j = %d\n",i , j);


return 0;
}