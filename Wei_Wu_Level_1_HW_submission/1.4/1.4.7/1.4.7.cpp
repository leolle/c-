#include <stdio.h>
#include <fstream>
#include <cstdlib>
#include <cctype>
using namespace std;

int main ()
{
	char c = '\0';
    int num_count = 0, three_freq = 0;

	while ( (c=getchar()) != EOF )
    {
		switch (c)
		{
		case '0':
			num_count++;
			break;
		case '1':
			num_count++;
			break;
		case '2':
			num_count++;
			break;
		case '3':
			num_count++;
			three_freq++;
			break;
		case '4':
			num_count++;
			break;
		default:
			break;
		}
	}
	printf("times each of the numbers 0-4 have been typed: %d\n",num_count);
	switch (three_freq)
	{
	case 0:
		printf("No number three .\n");
		break;
	case 1:
		printf("Number three appears once.\n");
		break;
	case 2:
		printf("Number three appears two times.\n");
		break;

	default:
		printf("The number three appears more than two times.\n");
		break;
	}
	return 0;
}