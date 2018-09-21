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
	Point cP1(1,1), cP2, cP3, cP4, cP5(10,10);
	Array cArray(3);	//give a different size to test the assignment operator.

	//try...catch block
	try
	{
	cArray.GetElement(345);		//try to access an element that does not exist.
	}
	catch(int i)
	{
		if (i == -1)
		{
			cout << "out of bound." << endl;
		}
	}
	return 0;
}