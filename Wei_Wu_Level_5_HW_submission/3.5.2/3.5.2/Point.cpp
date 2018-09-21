#include <stdio.h>
#include <string.h>
#include <iostream>
#include "Point.hpp"
#include <sstream>

using namespace std;
Point::Point() : m_x(0), m_y(0)
{
	//m_x = 0;
	//m_y = 0;
//	cout << "default point constructor " << endl;
}

Point::Point(double xval, double yval) 
: m_x(xval), m_y(yval)		//constructor
{
	//m_x = xval;
	//m_y = yval;
//	cout << "constructor point class with arguments, colon syntax." << endl;
}								

//copy constructor
Point::Point(const Point& p) : m_x(p.m_x), m_y(p.m_y)
{
	//m_x = p.m_x;
	//m_y = p.m_y;
//	cout << "copy point constructor , colon syntax." << endl;
}

string Point::ToString() const	//convert the double coordinates to a string
{
	std::stringstream ss;
	ss << " Point(" << m_x << "," << m_y<< ")";
	std::string sss = Shape::ToString();
	std::string s = ss.str();
	return sss + s;			//return the ID from the shape and Point coordinate.
}

// Get the x-coordinate
double Point::GetX() const			
{ 
	return m_x;
} 					

// Get the y-coordinate
double Point::GetY() const			
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

double Point::Distance(Point p) const // Calculate the distance between two points.
{
	double distance_x = (m_x - p.m_x)*(m_x - p.m_x);
	double distance_y = (m_y - p.m_y)*(m_y - p.m_y);
	return std::sqrt(distance_x + distance_y);
}


Point Point::operator * (double factor) const // Negate the coordinates.
{
	return Point( m_x*factor, m_y*factor);
}

Point Point::operator - () const // Negate the coordinates.
{
	return Point(-m_x, -m_y);
}

Point Point::operator + (const Point& p) const // Add coordinates.
{
	return Point(m_x+p.m_x, m_y+p.m_y);
}


bool Point::operator == (const Point& p) const // Equally compare operator.
{
	return ( m_x == p.m_x ) && ( m_y == p.m_y );
}

bool Point::operator != (const Point& p) const // Equally compare operator.
{
	return ( m_x != p.m_x ) || ( m_y != p.m_y );
}

// Assignment operator.
Point& Point::operator = (const Point& source) 
{
	// Avoid doing assign to myself
	if (this == &source)
		return *this;
	Shape::operator=(source);		//need to use the shape assignment operator
	m_x = source.m_x;
	m_y = source.m_y;

	return *this;
}


Point& Point::operator *= (double factor)
{

	Point tmp = (*this) * factor;
	*this = tmp;

	return *this;

}


ostream& operator << (ostream& os, const Point& p) // Send to ostream.
{
	os << "Point(" << p.GetX() << "," << p.GetY() << ")";
	return os;
}
