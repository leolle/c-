#include <iostream>
#include <stdio.h>
#include <math.h>


int ReadNumber();
int ReadNumber()
{
	using namespace std;
	int x;
	cin >> x;
	return x;
}
//int max_digits = 6;

int NumDigits(int numVal) 
{
	int digits = 0, temp = abs(numVal);
	for(digits = 0; temp > 0; digits++) temp /= 10;
	return digits;
}
void PrintNumber(int pNumValue)
{
	using namespace std;

    // If number is smaller than 0, put a - sign and
    // change number to positive
    if (pNumValue < 0) {
        putchar('-');
        pNumValue = -pNumValue;
    }
 
    // If number is 0
    if (pNumValue == 0)
        putchar('0');
 
    // Remove the last digit and recur
    if (pNumValue/10)
        PrintNumber(pNumValue/10);
 
    // Print the last digit
    putchar(pNumValue%10 + '0');

	//int digits = 0, temp1 = abs(pNumValue), temp2 = pNumValue;
	//char c;

	//for(digits = 0; temp1 > 0; digits++) 
	//{	
	//	c = temp1 % 10;
	//	//printf("%c",c);
	//	putchar('\n');
	//	putchar(c);
	//	temp1 /= 10;
	//}
	return;
}
int main()
{
    using namespace std;
	int num = -152;
	PrintNumber(num);

	return 0;
}