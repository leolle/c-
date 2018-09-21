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
	Point cP1(0, 0),cP2(-1, 24);

	Point p(1.0, 1.0);
	//if (p==1.0) cout<<"Equal!"<<endl;
	//Point constructor with the single double argument is implicitly used to
	//convert the number in the if statement to a Point object. Thus constructors are used as
	//implicit conversion operators
	
	if (p==(Point)1.0) cout<<"Equal!"<<endl;
	else cout<<"Not equal"<<endl;
	//To prevent the usage of constructors are implicit conversion operators, declare the constructor as explicit.
	//use explicit constructor conversion in if to convert 1.0 to point(1).


	return 0;
} 