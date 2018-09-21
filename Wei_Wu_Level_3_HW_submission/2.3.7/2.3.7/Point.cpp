#include <stdio.h>
#include <string.h>
#include <iostream>
#include "Point.hpp"
#include <sstream>

using namespace std;

Point::Point()
{
	m_x = 0;
	m_y = 0;
}

Point::Point(double xval, double yval)		//constructor
{
	m_x = xval;
	m_y = yval;
}


string Point::ToString()	//convert the double coordinates to a string
{
	std::stringstream ss;
	ss << "Point(" << m_x << "," << m_y << ")";
	std::string s = ss.str();
	return s;
}

