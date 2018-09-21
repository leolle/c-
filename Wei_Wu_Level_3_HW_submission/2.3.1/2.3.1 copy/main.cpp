#include <stdio.h>
#include <string.h>
#include <iostream>
#include "Point.cpp"
#include <sstream>

using namespace std;


int main()
{
	// Part 1
	double x_value_temp, y_value_temp;
	
	//construct Point cXy;
	Point cXy1, cXy2;

	cout << "enter the x coordinate for point 1" << endl;
	cin >> x_value_temp;
	cout << "enter the y coordinate for point 1" << endl;
	cin >> y_value_temp;

	//set x,y coordinate for cXy1
	cXy1.SetX(x_value_temp);
	cXy1.SetY(y_value_temp);

	cout << "enter the x coordinate for point 2" << endl;
	cin >> x_value_temp;
	cout << "enter the y coordinate for point 2" << endl;
	cin >> y_value_temp;

	//set x,y coordinate for cXy2
	cXy2.SetX(x_value_temp);
	cXy2.SetY(y_value_temp);
	
	//Print distance from cxy1 to point cXy2
	cout << "distance to the point 2: " << cXy1.Distance(cXy2) << endl;	
	//it will show 2 constructor messages and 3 deconstructor messages because when calling Distance function, 
	//it will construct temporary objects via the Point parameter using the default copy constructor,
	//this temperary object will be destroyed after calling so we have 3 deconstructor messages.

	//Part 2
	cout << "enter the x coordinate for point 1" << endl;
	cin >> x_value_temp;
	cout << "enter the y coordinate for point 1" << endl;
	cin >> y_value_temp;
	
	
	//construct Point cXy1 with arguments;
	Point cXy3(x_value_temp, y_value_temp);
	//Print distance from cxy1 to point cXy2
	cout << "distance to the point 2: " << cXy3.Distance(cXy2) << endl;	
	//it will show 2 constructor messages and 2 deconstructor messages because when calling Distance function, 
	//it will construct temporary objects via the Point parameter using the default copy constructor, which will dispay some text,
	//this temperary object will be destroyed after calling so we have 3 deconstructor messages.

    return 0;
} 