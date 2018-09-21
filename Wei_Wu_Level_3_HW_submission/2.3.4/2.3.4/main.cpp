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
	const Point cXy3(123,456);
	//cXy3.SetX( 23 );		// It gives a compiler error because of trying to change a const object.
	cout << cXy3.X() << endl;

	//set x,y coordinate for cXy
	cXy.SetX(x_value_temp);
	cXy.SetY(y_value_temp);

	//Print the description of the point returned by the ToString() function
	cout << cXy.ToString() << endl;
	
	//Print the point coordinates using the get functions
	cout << "x: " << cXy.X() << endl;
	cout << "y: " << cXy.Y() << endl;

	////Print distance to the origin (0, 0)
	//cout << "distance to the origin (0, 0): " << cXy.DistanceOrigin() << endl;

	Point cXy2(0.0, 0.0);				//construct another point class cXy2
	cout << "distance to the point 2: " << cXy.Distance(cXy2) << endl;	//Print distance to point cXy2

	//it will show 2 constructor messages and 3 deconstructor messages because when calling Distance function, 
	//it will construct temporary objects via the Point parameter using the default copy constructor,
	//this temperary object will be destroyed after calling so we have 3 deconstructor messages.

    return 0;
} 