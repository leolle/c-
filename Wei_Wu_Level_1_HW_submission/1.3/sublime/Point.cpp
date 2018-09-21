#include <stdio.h>
#include <string.h>
#include <iostream>
#include "Point.hpp"
#include <sstream>

using namespace std;

//default constructor
Point::Point()
{
	m_x = 0;
	m_y = 0;
}

//Point::Point(double xval, double yval)		//constructor
//{
//	m_x = xval;
//	m_y = yval;
//}								

// Get the x-coordinate
double Point::GetX()			
{ 
	return m_x;
} 					

// Get the y-coordinate
double Point::GetY()			
{ 
	return m_y;
} 					

//modify function
// Set the x-coordinate
void Point::SetX(double newX)
{
	m_x = newX;
}
// Set the y-coordinate
void Point::SetY(double newY)
{
	m_y = newY;
}

string Point::ToString()	//convert the double coordinates to a string
{
	std::stringstream ss;
	ss << "Point(" << m_x << "," << m_y << ")";
	std::string s = ss.str();
	return s;
}


