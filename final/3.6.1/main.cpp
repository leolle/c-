#include <stdio.h>
#include <string.h>
#include <iostream>
#include "Point.hpp"
#include <sstream>
#include "LineSegment.hpp"
#include "circle.hpp"
#include "Shape.hpp"
#include "array.hpp"

using namespace std;


int main()
{
	int a;
	int b[3] ={4,2,1};
	double c =0.78;
	int *d=&a;
	a=++*b*5%3;
	*(b+1)=c;
	*d=(*b)++%2+*(b+1);
	printf("%d",*d);

	return 0;
}