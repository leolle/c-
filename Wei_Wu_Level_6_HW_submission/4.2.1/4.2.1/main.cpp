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

int main()
{

	Array<Point> cArray(10), cArray3;	//index starts from 0, size is 10
	Array<LineSegment> cArray2(10);
	Point cP1(1.1, 1.1);
	Point cP2(cP1);
	LineSegment cLine(cP1, cP2);
	cArray.SetElement(3, cP1);	//set element
	cArray2.SetElement(0, cLine);	//set element
	cArray[0] = cArray[3];		//assign element 3 to element 0
	cArray3 = cArray;
	////try...catch block
	try
	{
		cout << cArray.GetElement(0) << endl;		//try to access an element.
		cout << cArray.GetElement(3) << endl;		//try to access an element.
		cout << cArray2.GetElement(0) << endl;		//try to access an element.
		cout << cArray3.GetElement(0) << endl;		//try to access an element.
	}
	catch(ArrayException &cException)	//catching the ArrayException base class.
	{
        cout << "In catch handler." << endl;
        cout << "Caught cArray exception type: ";
        cout << cException.GetMessage() << endl; //to display an error message.
	}
	return 0;
}