#include <stdio.h>
int main()
{
    using namespace std;
	float base, height;
	printf("Please enter base\n");
	scanf_s ("%f",&base);
	printf("Please enter height\n");
	scanf_s ("%f",&height);

	printf("The surface is %f\n", base * height /2.0 );
    return 0;
}