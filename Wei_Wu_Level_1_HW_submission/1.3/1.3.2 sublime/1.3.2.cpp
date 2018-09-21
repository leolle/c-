#include <stdio.h>
#include <iostream>
    using namespace std;
int main()
{
	float base, height;
	printf("Please enter base\n");
	scanf_l ("%f",&base);
	printf("Please enter height\n");
	scanf_l ("%f",&height);

	printf("The surface is %f\n", base * height /2.0 );
    return 0;
}