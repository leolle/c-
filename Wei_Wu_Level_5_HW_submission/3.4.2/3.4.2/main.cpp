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
	Point cP1(1,1), cP2(2, 2);
	cout << cP1.ID() << endl;

	Shape s; // Create shape.
	Point p(10, 20); // Create point.
	LineSegment l(Point(1, 2), Point(3, 4)); // Create line.


	cout << s.ToString() << endl; // Print shape.
	cout << p.ToString() << endl; // Print point.
	cout << l.ToString() << endl; // Print line


	cout << "Shape ID: " << s.ID() << endl; // ID of the shape.
	cout << "Point ID: " << p.ID() << endl; // ID of the point. Does this work?
											// 

	cout << "Line ID: " << l.ID() << endl; // ID of the line. Does this work?
											// This works because the linesegment id is derived from the shape.


	Shape* sp; // Create pointer to a shape variable.
	sp = &p; // Point in a shape variable. Possible?
			//this works because the point class is a shape.

	cout << sp->ToString() << endl; // What is printed?
									// It will print the ToString function in the shape class.
		
	// Create and copy Point p to new point.
	Point p2;
	p2 = p;
	cout << p2 << ", " << p2.ID() << endl; // Is the ID copied if you do not call
	// the base class assignment in point?
	//The ID will not be copied because it will only copy the point data.



	return 0;
}