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
	//double x_value_temp, y_value_temp;		//for centre point input
	//double radius;							
	//double radius_temp = 50;				//for test							

	Point cP1(0, 0),cP2(-1, 24), cP3, cP4(0, 0);
	double factor = 2;

	//test Negate the coordinates operator
	cP3 = -cP2;		//cP3 should be (1,-24)
	cout << "cP3: "<< cP3.ToString() << endl;

	//test Add coordinates operator
	cP3 = cP1 + cP2;	//cP3 should be (-1,24)
	cout << "cP3: "<< cP3.ToString() << endl;
	
	//test Scale the coordinates operator
	cP3 = cP2 * factor;		//cP3 should be (-2,48)
	cout << "cP3: "<< cP3.ToString() << endl;

	//test Equally compare operator
	cout << "cP1 = cP4 ? :" << (cP1 == cP4) << endl;	//should be 1
	cout << "cP1 = cP3 ? :" << (cP1 == cP3) << endl;	//should be 2

	//test Assignment operator 
	cP3 = cP1;	//cP3 should be (0,0)
	cout << "cP3: " << cP3.ToString() << endl;
	
	//test Scale the coordinates & assign operator
	cP2 *= factor;		//cP2 should be (-2,48)
	cout << "cP2: "<< cP2.ToString() << endl;

	//test chain operators
	cP1 = cP2 *= factor;	//cP1 should be (-4,96)
	cout << "cP1: "<< cP1.ToString() << endl;
	
    return 0;
} 