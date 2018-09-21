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
	Point* p1 = new Point();	//create Point objects on the heap with new using the default constructor
	cout << "Ostream << Operator: " << *p1 << endl;

	Point* p2 = new Point(1, 1);	//create Point objects on the heap with coordinates
	cout << "Ostream << Operator: " << *p2 << endl;

	Point* p3 = new Point(*p2);		//create Point objects on the heap with new using the copy constructor
	cout << "Ostream << Operator: " << *p3 << endl;

	cout << p1->Distance(*p2) << endl;	//call the Distance() function on the pointers and send the Point pointers to cout

	int pointer_array_size, N = 30;
	cin >> pointer_array_size;
	//Point p_array[pointer_array_size];	//Arrays on the stack must have the size set at compile time
	Point* p_array = new Point[pointer_array_size];		//Cannot call other than default constructor
	Point* p2_array = new Point[N];	

	delete p1;
	delete p2;
	delete p3;
	delete [] p_array;
	delete [] p2_array;

	return 0;
} 