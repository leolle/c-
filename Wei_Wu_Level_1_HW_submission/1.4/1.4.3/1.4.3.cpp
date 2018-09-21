#include <stdio.h>
#include <fstream>
#include <cstdlib>
#include <cctype>
using namespace std;

int main ()
{
	char c = '\0';
	char last = '\0';
    int num_words=0, num_chars=0, num_newlines=0;

	while ( (c=getchar()) != 4 )
    {
		switch (c)
		{
		case '\n':
			num_newlines++;
			break;
		default:
			num_chars++;
			break;
		}

		if (!isalnum(c) && isalnum(last))     // This is the end of a word
			num_words++;
		last = c;
   
	}
	printf("Number of characters: %d\n",num_chars);
	printf("Number of newlines: %d\n",num_newlines);
	printf("Number of words: %d\n",num_words);

	return 0;
}