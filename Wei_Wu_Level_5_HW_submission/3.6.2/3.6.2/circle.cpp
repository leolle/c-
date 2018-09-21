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
	cout << "constructor circle class" << endl;

}

Circle::Circle(const double& r, const Point& p)	: m_radius(r), m_center(p)	//constructor
{
	//m_radius = r;
	//m_center = p;
}	
							
// Copy constructor
Circle::Circle(const Circle& l) : Shape(l), m_radius(l.m_radius), m_center(l.m_center)
{
	//m_radius = l.m_radius;
	//m_center = l.m_center;
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
string Circle::ToString() const	//convert the double coordinates to a string
{
	std::stringstream ss;
	ss << "Centre " << m_center.ToString() << ", " << "Radius: " << m_radius;
	std::string sss = Shape::ToString();
	std::string s = ss.str();
	return sss + s;			//return the ID from the shape and center coordinate&radius.
}

// Assignment operator.
Circle& Circle::operator = (const Circle& source)
{
	// Avoid doing assign to myself
	if (this == &source)
		return *this;
	Shape::operator=(source);		//need to use the shape assignment operator

	m_radius = source.m_radius;
	m_center = source.m_center;

	return *this;
}


ostream& operator << (ostream& os, const Circle& c) // Send to ostream.
{
	Point p = c.CentrePoint();
	
	os << "Centre: Point(" << p.GetX() << "," << p.GetY() << "), Radius: " << c.Radius();
	return os;

}

//
void Circle::Draw() const 
{
	cout << "----draw circle function----" << endl;
}