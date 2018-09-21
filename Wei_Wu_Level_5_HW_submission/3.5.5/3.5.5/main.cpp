#include <stdio.h>
#include <string.h>
#include <iostream>
#include "Point.hpp"
#include <sstream>
#include "LineSegment.hpp"
#include "circle.hpp"
#include "Shape.hpp"

using namespace std;


int main()
{
	Point cP1(1.0, 2.0);
	LineSegment cLine(Point(2.0, 2.0), Point(3.0, 2.0));

	cP1.Print();
	cLine.Print();

	return 0;
}