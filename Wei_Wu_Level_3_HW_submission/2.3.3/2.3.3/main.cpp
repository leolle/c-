#include <stdio.h>
#include <string.h>
#include <iostream>
#include "Point.hpp"
#include <sstream>

using namespace std;


int main()
{
	double x_value_temp, y_value_temp;
	cout << "enter the x coordinate" << endl;
	cin >> x_value_temp;
	cout << "enter the y coordinate" << endl;
	cin >> y_value_temp;
	
	//construct Point cXy;
	Point cXy;

	//set x,y coordinate for cXy
	cXy.X(x_value_temp);
	cXy.Y(y_value_temp);

	//Print the description of the point returned by the ToString() function
	cout << cXy.ToString() << endl;
	
	//Print the point coordinates using the get functions
	cout << "x: " << cXy.X() << endl;
	cout << "y: " << cXy.Y() << endl;

	////Print distance to the origin (0, 0)
	//cout << "distance to the origin (0, 0): " << cXy.DistanceOrigin() << endl;

	Point cXy2(0.0, 0.0);				//construct another point class cXy2
	cout << "distance to the point 2: " << cXy.Distance(cXy2) << endl;	//Print distance to point cXy2


    return 0;
} 