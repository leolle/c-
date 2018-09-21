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

	//test Ostream << operators for piont
	cout << "Ostream << Operator: " << cP1 << endl;

 	//test Ostream << operators for linesegment
	LineSegment cLineseg(cP1, cP2);
	cout << "Ostream << Operator: " << cLineseg << endl;

 	//test Ostream << operators for circle
	Circle cC(10, cP2);
	cout << "Ostream << Operator: " << cC << endl;


	return 0;
} 