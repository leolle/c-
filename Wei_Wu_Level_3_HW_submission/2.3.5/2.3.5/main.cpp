//for example, assume linesegment start point is (0,0), end point is  (1,1).
//the length of the linesegment is 1.414.

#include <stdio.h>
#include <string.h>
#include <iostream>
#include "Point.hpp"
#include <sstream>
#include "LineSegment.hpp"

using namespace std;


int main()
{
	// input two coordinates for the linesegment
	double x_value_temp, y_value_temp;
	cout << "enter the x coordinate of P1:" << endl;
	cin >> x_value_temp;

	cout << "enter the y coordinate of P1:" << endl;
	cin >> y_value_temp;

	Point cP1(x_value_temp,y_value_temp);

	cout << "enter the x coordinate of P2:" << endl;
	cin >> x_value_temp;
	cout << "enter the y coordinate of P2:" << endl;
	cin >> y_value_temp;
	Point cP2(x_value_temp,y_value_temp);

	LineSegment line(cP1,cP2);		// construct class linesegment

	cout << "coordinates for the 2 points of the linesegment, " << line.ToString() << endl;	// description of linesegment

	cout << "the length of the of linesegment is " << line.Length() << endl;	// length of linesegment


    return 0;
} 