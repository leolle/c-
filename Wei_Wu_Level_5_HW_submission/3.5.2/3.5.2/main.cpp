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
	Shape s; // Create shape.
	Point p(10, 20); // Create point.
	LineSegment l(Point(1, 2), Point(3, 4)); // Create line.
	Circle cCir(20, p);

	cout << s.ToString() << endl; // Print shape.
	cout << p.ToString() << endl; // Print point.
	cout << l.ToString() << endl; // Print line


	cout << "Shape ID: " << s.ID() << endl; // ID of the shape.
	cout << "Point ID: " << p.ID() << endl; // ID of the point. 
											// 

	cout << "Line ID: " << l.ID() << endl; // ID of the line. Does this work?


	Shape* sp; // Create pointer to a shape variable.
	sp = &p; // Point in a shape variable.
	
	cout << sp->ToString() << endl; 

	sp = &l; // Point to a linesegment l

	cout << sp->ToString() << endl; // print linesegment l

	sp = &cCir; // Point to a circle cCir

	cout << sp->ToString() << endl; // print circle cCir




	return 0;
}