#include <stdio.h>


void PrintNumber(int pNumValue)
{
	using namespace std;

    // If the number is smaller than 0, put a - sign and
    // change number to positive
    if (pNumValue < 0) {
        putchar('-');
        pNumValue = -pNumValue;
    }
 
    // If the number is 0
    if (pNumValue == 0)
        putchar('0');
 
    // Remove the last digit and recur
    if (pNumValue/10)
        PrintNumber(pNumValue/10);
 
    // Print the last digit
    putchar(pNumValue%10 + '0');
	putchar('\n');

	return;
}

int main()
{
    using namespace std;
	int num = -1501;
	PrintNumber(num);

	return 0;
}