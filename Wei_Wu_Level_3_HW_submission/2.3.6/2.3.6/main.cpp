#include <stdio.h>
#include <string.h>
#include <iostream>
#include "Point.hpp"
#include <sstream>
#include "LineSegment.hpp"
#include "circle.hpp"

using namespace std;


int main()
{
	double x_value_temp, y_value_temp;		//for centre point input
	double radius;							
	double radius_temp = 50;				//for test							

	cout << "enter the x coordinate of centre point:" << endl;
	cin >> x_value_temp;
	cout << "enter the y coordinate of centre point:" << endl;
	cin >> y_value_temp;

	cout << "enter the radius of the circle:" << endl;
	cin >> radius;
	Point cP1(x_value_temp,y_value_temp);	// construct class centre point
	Point cP2( 5, 5 );						// for test
	Circle cCircle(radius, cP1);			// construct class circle

	//get description of the circle
	cout << "Circle " << cCircle.ToString() << endl;
	cout << "Circle Radius: " << cCircle.Radius() << endl;
	cout << "Circle Diameter: " << cCircle.Diameter() << endl;
	cout << "Circle Area: " << cCircle.Area() << endl;
	cout << "Circle Circumference: " << cCircle.Circumference() << endl;

	
	//for test, changing centrepoint coordinate to cp2(5,5), changing radius to 50
	cout << '\n' << endl;
	cout << "for test, changing centrepoint coordinate to cp2(5,5), changing radius to 50" <<endl;
	cCircle.CentrePoint(cP2);
	cCircle.Radius(radius_temp);
	cout << "Circle " << cCircle.ToString() << endl;
	cout << "Circle Radius: " << cCircle.Radius() << endl;
	cout << "Circle Diameter: " << cCircle.Diameter() << endl;
	cout << "Circle Area: " << cCircle.Area() << endl;
	cout << "Circle Circumference: " << cCircle.Circumference() << endl;

    return 0;
} 