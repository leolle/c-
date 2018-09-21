#ifndef SHAPE_HPP
#define SHAPE_HPP

//#include "point.hpp"
#include <iostream>
#include <stdio.h>
#include "stdlib.h"

using namespace std;

class Shape
{
protected:

	int m_id;	// radius of the circle

public:
	// Constructors
	Shape();									
	Shape(const Shape& s); 					// Copy constructor
	virtual ~Shape(){};							// Destructor

	std::string ToString() const;	//convert the double coordinates to a string

	//
	int ID();

	//operator overloading
	Shape& operator = (const Shape& source); // Assignment operator.		  

};

ostream& operator << (ostream& os, const Shape& c); // Send to ostream.

#endif




