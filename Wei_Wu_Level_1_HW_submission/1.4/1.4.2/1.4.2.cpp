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
	do
    {
		c=getchar();
		if(c != 4)		// if the enter is not ctrl+D
		{
			if (c == '\n' || (c == '\f' && last == '\r'))
				num_newlines++;
			else
				num_chars++;
			if (!isalnum(c) && isalnum(last))     // This is the end of a word
				num_words++;
			last = c;
		}
   
   //if (num_chars > 0) {               // Adjust word and line
   //   if (std::isalnum(last))     // counts for special
   //      num_words++;                 // case
   //   num_newlines++;
   //}
	}
	while ( c != 4 );
	printf("Number of characters: %d\n",num_chars);
	printf("Number of newlines: %d\n",num_newlines);
	printf("Number of words: %d\n",num_words);

	return 0;
}