#include <stdio.h>
#include <string.h>
#include <iostream>
#include "Point.hpp"
#include <sstream>
#include "LineSegment.hpp"
#include "circle.hpp"
#include "array.hpp"

using namespace std;


int main()
{
	Point cP1(1,1), cP2(2, 2);

	//print 2 point constructors msg, 2 default point constructor msg and 4 destructor msg.
	//print 1 linesegment constructor msg and 1 linesegment destructor msg.
	//LineSegment cL1(cP1, cP2);	//print 2 constructors msg and 2 destructor msg.
	
	//after changing the constructors in the Line class to use the colon syntax,
	//print 2 point constructors msg , 2 point copy constructor msg and 4 destructor msg.
	//print 1 linesegment constructor msg and 1 linesegment destructor msg
	LineSegment cL2(cP1, cP2);	


	//Point cP1(1,1), cP2, cP3, cP4, cP5(10,10);
	//Array cArray1(3), cArray3(12);	//give a different size to test the assignment operator.
	//Array cArray4;					//test for member function size();

	//set element for cArray 1
	//cArray1.SetElement(1,cP5);		//try to get 12th element from cArray3 will return the first element.
	//cArray1.SetElement(2,cP1);
	//cArray1.SetElement(3,cP1);
	//
	//cP2 = cArray1.GetElement(2);	//get element 1 from cArray1.
	//cout << cP2.ToString() << endl;

	//Array cArray2(cArray1);			//copy cArray1 to cArray2, cArray2 doesn't exist before copying.
	//cP3 = cArray2.GetElement(2);	//get element 2 from cArray2, should be the same as cP1.
	//cout << cP3.ToString() << endl;

	//cArray3 = cArray1;				//assign cArray1 to cArray2
	//cP4 = cArray3.GetElement(12);	//get element 1 from cArray3, should be the same as cP5.
	//cout << cP4.ToString() << endl;

	//cout << "cArray3 size: " << cArray3.Size() << endl;	//should be 3
	//cout << "cArray4 size: " << cArray4.Size() << endl;	//should be 10

	//cout << "first element of cArray1: " << cArray1[0] << endl;	//should be (10, 10)

	return 0;
} 