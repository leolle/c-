#include <stdio.h>
#include <string.h>
#include <iostream>
#include "Point.cpp"
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
	cXy.SetX(x_value_temp);
	cXy.SetY(y_value_temp);

	//Print the description of the point returned by the ToString() function
	cout << cXy.ToString() << endl;
	
	//Print the point coordinates using the get functions
	cout << "x: " << cXy.GetX() << endl;
	cout << "y: " << cXy.GetY() << endl;

	//Print distance to the origin (0, 0)
	cout << "distance to the origin (0, 0) is " << cXy.DistanceOrigin() << endl;

	Point cXy2(0.1, 0.0);				//construct another point class cXy2
	cout << "distance to the point 2 is " << cXy.Distance(cXy2) << endl;	//Print distance to point cXy2

	//for example, set x,y coordinate for cXy (1,1), the distance to the origin should be 1.414.
	//because point cXy2 is set at (0,0), the distance between cXy and cXy2 should be 1.414 as well.

    return 0;
} 