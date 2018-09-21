/* Calculate the length of a string */
#include <stdio.h>
#include <string.h>
#define MAXLINE 30


int Length(char *str)
{
	int length =0;
	for(; *str++!='\0' ; )		//if the content of current character is not the end of a string
		length++;				//count the length of a string
	return length;
}

int main()
{
	char string[MAXLINE+1];		// Line of maxium 30 chars + \0
	int c;						// The input character
	int i=0;					// The counter
	// Print intro text
	printf("Type up to %d chars. Exit with ^D\n", MAXLINE);
	// Get the characters
	while ((c=getchar())!=4 && i<MAXLINE)
	{
		// Append entered character to string
		string[i++]=(char)c;
	}
	string[i]='\0';				// String must be closed with \0
	printf("String length is %d\n", Length(string));
	return 0;
}