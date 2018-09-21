#include <stdio.h>
#include <string.h>
#include <iostream>
#include "Point.hpp"
#include <sstream>
#include "LineSegment.hpp"
#include "circle.hpp"
#include "Shape.hpp"
#include "array.hpp"
#include "PointArray.hpp"

using namespace std;

int main()
{
	PointArray cNum1(5);
	Point cP1(1, 0),cP2(2, 0),cP3(3, 0),cP4(4, 0),cP5(5, 0);
	cNum1.SetElement(0, cP1);
	cNum1.SetElement(1, cP2);
	cNum1.SetElement(2, cP3);
	cNum1.SetElement(3, cP4);
	cNum1.SetElement(4, cP5);

	cout << cNum1.Length() << endl;		//length is 4
	//It's assume that the template argument can be any types, 
	//but the production of two points are not defined, 
	//so we can't use numberic array dot function with Point objects.
	return 0;
}