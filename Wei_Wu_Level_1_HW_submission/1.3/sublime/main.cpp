/*input
2
foo
bar
*/

#include <stdio.h>
#include <string.h>
#include <iostream>
#include "./Point.hpp"
#include "./Point.cpp"
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

	//Set X, Y for class cXy.
	cXy.SetX(x_value_temp);
	cXy.SetY(y_value_temp);


	//Print the description of the point returned by the ToString() function
	cout << cXy.ToString() << endl;
	
	//Print the point coordinates using the get functions
	cout << "x: " << cXy.GetX() << endl;
	cout << "y: " << cXy.GetY() << endl;

    return 0;
} 