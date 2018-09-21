#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

using namespace std;
FILE* stream;			//file pointer

int main ()
{
	errno_t err;		//err indicator
	char ch;			//input character buffer
	char c[80];			//input string buffer, the size of array doesn't matter
	int counter = 0;	//input character counter
	char file_name[20];
	printf("Name a file to store the input, for example, d:\\\\store.txt\n");
	scanf_s("%19s", file_name, _countof(file_name));
	printf("\n");

	//if file doesn't exist, create a file, Open for write
   err  = fopen_s( &stream, file_name, "wt+" );
   if( err == 0 )
   {
      printf( "The file '%s' was opened\n",file_name );
   }
   else
   {
      printf( "The file '%s' was not opened\n",file_name );
   }
   
	printf("input a string:\n");

	ch = _getch();
	do
	{
		do
		{
			fputc(ch,stream);		//store the input into file
			ch = _getch();
		} while (ch != '\r' && ch != 1);	//if enter or ^A is pressed, exit
	} while( ch != 1 );				//if enter is pressed, exit
	fclose(stream);					//close the file
	printf("CTRL + A is a correct ending.\n");
 
	return 0;
}