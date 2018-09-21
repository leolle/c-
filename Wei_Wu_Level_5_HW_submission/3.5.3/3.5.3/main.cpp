#include <stdio.h>
#include <string.h>
#include <iostream>
#include "Point.hpp"
#include <sstream>
#include "LineSegment.hpp"
#include "circle.hpp"
#include "array.hpp"
#include "Shape.hpp"

using namespace std;


int main()
{
	Shape* shapes[3];
	shapes[0] = new Shape;
	shapes[1] = new Point;
	shapes[2] = new LineSegment;
	for (int i = 0; i != 3; i++) delete shapes[i];	
	//there are 5 base shape classes, 1 derived linesegment class, and 3 derived point classes.
	//when the virtual is not added, there are only 3 destructors for 3 base classes are called, which coming from the shape destructor.
	//
	//when destructor is declared virtual in the base class, it will correctly call both the destructor of the base pointers and derived destructors.

	return 0;
}