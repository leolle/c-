#include <stdio.h>
#include <string.h>

void DayName(int day_value)		
{
	char day_name[7][20] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};	
	printf("%s",day_name[day_value - 1]);
	printf("\n");

	return;
}
int main()
{
	//use a string array to store the day name
	int day_number;		//variable to store input day number
	printf("Please enter a day number between 1 to 7:\n");
	scanf_s("%d",&day_number);
	printf("%d gives: Day %d is a ",day_number, day_number);
	DayName(day_number);			//put day_number and the array name as arguments
	return 0;
}