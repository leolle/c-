#ifndef PointArray_HPP
#define PointArray_HPP

#include <iostream>
#include <stdio.h>
#include "array.hpp"

using namespace std;
//template< Point>
class PointArray : public Array<Point>	//derived from shape, access specifier public
{
private:

public:

	// Constructors
	PointArray();									// default constructor
	PointArray(const int& nSize);	// 
	// Copy constructor
	PointArray(const PointArray& l); 					
	//PointArray();
	//PointArray(const int& nSize);
	virtual ~PointArray()
	{
		//cout << "destructor circle class" << endl;
	};							// Destructor

	// Accesssing functions
	double Length() const;
	// Modifiers

	//operator overloading
	//PointArray operator + (const PointArray& source) const; // add operator.
	//PointArray operator += (const PointArray& source) const; // add operator.
	//PointArray operator * (T factor) const; // multiply operator.
	//PointArray& operator = (const PointArray& source); // Assignment operator.

};

//ostream& operator << (ostream& os, const PointArray<Point>& c); // Send to ostream.

#endif




