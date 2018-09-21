#include <stdio.h>
#include <conio.h>

using namespace std;

int main ()
{
	char ch;			//input character buffer
	char c[80];			//input string buffer, the size of array doesn't matter
	int counter = 0;	//input character counter

	printf("input a string:\n");

	ch = _getch();		
	do
	{
		do
		{
			c[counter++] = ch;				//store input to array a
			ch = _getch();
		} while (ch != '\r' && ch != 1 );	//if enter or ^A is pressed, exit

		//print the text when press enter
		for (int i = 0; i < counter; i++)
		{
			putchar(c[i]);
		}
		printf("\n");
		counter = 0;						//reset counter for the next input
	} while( ch != 1 );						//if ^A is pressed, exit 

	printf("CTRL + A is a correct ending.\n");

	return 0;
}