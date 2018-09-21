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

Point::Point(double xval, double yval)		//constructor
{
	m_x = xval;
	m_y = yval;
}								


string Point::ToString()	//convert the double coordinates to a string
{
	std::stringstream ss;
	ss << "Point(" << m_x << "," << m_y<< ")";
	std::string s = ss.str();
	return s;
}

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


double Point::DistanceOrigin() // Calculate the distance to the origin (0, 0).
{
	return std::sqrt(m_x*m_x + m_y*m_y);
}

double Point::Distance(Point p) // Calculate the distance between two points.
{
	double distance_x = (m_x - p.m_x)*(m_x - p.m_x);
	double distance_y = (m_y - p.m_y)*(m_y - p.m_y);
	return std::sqrt(distance_x + distance_y);
}
