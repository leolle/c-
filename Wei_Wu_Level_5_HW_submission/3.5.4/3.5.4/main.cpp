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
	Shape* shapes[10];
	//Shape cSha;	//can't instantiate abstract class.

	shapes[0] = new LineSegment;
	shapes[1] = new Point;
	shapes[2] = new Point;
	shapes[3] = new Point;
	shapes[4] = new Point;
	shapes[5] = new Point;
	shapes[6] = new Point;
	shapes[7] = new Point;
	shapes[8] = new Point;
	shapes[9] = new LineSegment(Point(1.0, 2.5), Point(3.4, 5.2));
	for (int i = 0; i != 10; i++) shapes[i]->Draw();
	for (int i = 0; i != 10; i++) delete shapes[i];
	return 0;
}