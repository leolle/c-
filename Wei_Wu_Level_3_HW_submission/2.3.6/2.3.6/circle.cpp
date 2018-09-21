#include <stdio.h>
#include <string.h>
#include <iostream>
#include "Point.hpp"
#include <sstream>
#include "circle.hpp"
#include <cmath>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

// default constructor
Circle::Circle()
{
	m_radius = 0;
	Point m_center(0, 0);
}

Circle::Circle(const double& r, const Point& p)		//constructor
{
	m_radius = r;
	m_center = p;
}	
							
// Copy constructor
Circle::Circle(const Circle& l)
{
	m_radius = l.m_radius;
	m_center = l.m_center;
} 					

// get centre point
Point Circle::CentrePoint() const
{
	return m_center;
}

// get radius
double Circle::Radius() const
{
	return m_radius;
}

// get diameter
double Circle::Diameter() const
{
	return 2*m_radius;
}

// get area
double Circle::Area() const
{
	return M_PI*m_radius*m_radius;
}

// get circumference
double Circle::Circumference() const
{
	return 2*M_PI*m_radius;
}

// Set centre point 
void Circle::CentrePoint(const Point& pt)
{
	m_center = pt;
}

// set radius
void Circle::Radius(double rVal)
{
	m_radius = rVal;
}

// return description
string Circle::ToString()	//convert the double coordinates to a string
{
	std::stringstream ss;
	ss << "Centre " << m_center.ToString() << ", " << "Radius: " << m_radius;
	std::string s = ss.str();
	return s;
}

