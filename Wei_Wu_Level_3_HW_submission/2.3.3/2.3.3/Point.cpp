#include <stdio.h>
#include <string.h>
#include <iostream>
#include "Point.hpp"
#include <sstream>

using namespace std;

Point::Point(double xval, double yval)		//constructor
{
	m_x = xval;
	m_y = yval;
	cout << "constructor class with arguments" << endl;
}								


string Point::ToString()	//convert the double coordinates to a string
{
	std::stringstream ss;
	ss << "Point(" << m_x << "," << m_y<< ")";
	std::string s = ss.str();
	return s;
}

// Get the x-coordinate
double Point::X()			
{ 
	return m_x;
} 					

// Get the y-coordinate
double Point::Y()			
{ 
	return m_y;
} 					

//modify function
// Set the x-coordinate
void Point::X(double newX)
{
	m_x = newX;
}
// Set the y-coordinate
void Point::Y(double newY)
{
	m_y = newY;
}


double Point::Distance() // Calculate the distance to the origin (0, 0).
{
	return std::sqrt(m_x*m_x + m_y*m_y);
}

double Point::Distance(Point p) // Calculate the distance between two points.
{
	float distance_x = (m_x - p.m_x)*(m_x - p.m_x);
	float distance_y = (m_y - p.m_y)*(m_y - p.m_y);
	return std::sqrt(distance_x + distance_y);
}
