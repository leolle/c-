#include <stdio.h>
#include <fstream>
#include <cstdlib>
#include <cctype>
using namespace std;

int main ()
{
	char c = '\0';
    int num_count = 0;

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
			break;
		case '4':
			num_count++;
			break;
		default:
			break;
		}
	}
	printf("times each of the numbers 0-4 have been typed: %d\n",num_count);

	return 0;
}