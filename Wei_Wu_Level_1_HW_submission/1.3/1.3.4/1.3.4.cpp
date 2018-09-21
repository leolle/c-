#include <iostream>
#include <stdio.h>
int main()
{
    using namespace std;
	int married;
	printf("Please enter a number:\n");
	scanf_s ("%d",&married);
	printf("Married is %s.\n", (married > 0 ? "TRUE" : "FALSE"));	//married > 0, TRUE, married = 0, FALSE
    return 0;
}