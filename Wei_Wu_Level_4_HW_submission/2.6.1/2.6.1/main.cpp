#include <stdio.h>
#include <string.h>
#include <iostream>
#include "Point.hpp"
#include <sstream>
#include "LineSegment.hpp"
#include "circle.hpp"
#include "array.hpp"

int main()
{
	//using namespace WEIWU::CAD;
	WEIWU::CAD::Point cP1(1, 1), cP2, cP3, cP4, cP5(10, 10);	//the full namespace for Point class
	cout << cP1.ToString() << endl;
	using WEIWU::CAD::LineSegment;			//using declaration for using a single class
	LineSegment cLine1(cP1, cP5);
	using namespace WEIWU::CONTAINER;
	Array cArray1(3), cArray3(12);			//using declaration for a complete namespace
	namespace CIR = WEIWU::CAD;				//creating a shorter alias
	CIR::Circle cCircle(2, cP1);

	return 0;
} 