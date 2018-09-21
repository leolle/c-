#include <iostream>
#include <stdio.h>
int Minus(int a, int b)	
{
	return a - b;
}
int main()
{
    using namespace std;
	int num1, num2;
	printf("Please enter two numbers seperate by enter key:\n");
	scanf_s("%d",&num1);
	scanf_s("%d",&num2);
	printf("The difference of %d and %d is %d\n", num1, num2, Minus(num1, num2));
    return 0;
}