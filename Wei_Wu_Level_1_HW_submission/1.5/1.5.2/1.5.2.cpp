#include <stdio.h>
int Fac(int factorNum)	
{

	//int length = factorNum;
	if (factorNum == 1)
	{
		printf("1 = ");
		return 1*factorNum;
	}
	else
	{
		printf("%d * ",factorNum);
	}
	return (factorNum == 1 ? factorNum : factorNum * Fac(factorNum - 1));	
}

int Fibo(int value)
{
	if (value == 1 || value == 0)
	{
		return value;
	}
	else
	{
		return Fibo(value - 1) + Fibo(value - 2);
	}
	//return (value <= 1 ? value : Fibo(value-1)+ Fibo(value-2));	
}
int main()
{
    using namespace std;
	int num,factorial,fibo;
	printf("The factorials of 6 is ");
	Fac(6);
	printf("Please enter one number:\n");
	scanf_s("%d",&num);
	printf("The factorials of %d is ", num);
	factorial=Fac(num);
	printf("%d \n",factorial);

	printf("Please enter one number:\n");
	scanf_s("%d",&num);
	printf("The fibonanchi of %d is ", num);
	fibo=Fibo(num);
	printf("%d \n",fibo);

    return 0;
}