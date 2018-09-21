#include <stdio.h>
#include <string.h>
#include <iostream>
#include "Point.hpp"
#include <sstream>
#include "LineSegment.hpp"
#include "circle.hpp"
#include "Shape.hpp"
#include "array.hpp"

using namespace std;

//implement both exception classes in the array header file for simplicity
int main()
{
	Array cArray(3);	//index starts from 0, size is 3
	Point cP1(1.1, 1.1);
	Point cP2(cP1);
	cout << cP1.ID() << endl;
    cout << cP2.ID() << endl;

	//try...catch block
	try
	{
		cArray.GetElement(3);		//try to access an element that does not exist.
	}
	catch(ArrayException &cException)	//catching the ArrayException base class.
	{ 
        cout << "In catch handler." << endl;
        cout << "Caught cArray exception type: ";
        cout << cException.GetMessage() << endl; //to display an error message.
	}
	return 0;
}