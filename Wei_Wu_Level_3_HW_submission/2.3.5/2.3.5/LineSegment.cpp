#include "LineSegment.hpp"
#include <cmath>

//
LineSegment::LineSegment() 
{
	// because the default constructor of class point will set coordinate to 0,0, 
	// so the default constructor of class LineSegment will set 2 points to 0, 0
}

LineSegment::~LineSegment()
{
	
}

// set the coordinate of linesegment to p1 and p2
LineSegment::LineSegment(const Point& p1, const Point& p2)
{
	startPoint=p1;
	endPoint=p2;
}

// copy constructor will copy current class to l
LineSegment::LineSegment(const LineSegment& l)
{
	startPoint=l.startPoint;
	endPoint=l.endPoint;
}

// get start point
Point LineSegment::start() const
{
	return startPoint;
}

// get end point
Point LineSegment::end() const
{
	return endPoint;
}

// set start point
void LineSegment::start(const Point& pt)
{
	startPoint=pt;
}

// set end point
void LineSegment::end(const Point& pt)
{
	endPoint=pt;
}

string LineSegment::ToString()	// return the coordinates information of the 2 ends of the linesegment
{
	std::stringstream sss;
	sss << "End 1: " << startPoint.ToString() << ", " << "End 2: "<< endPoint.ToString() << ".";
	std::string s = sss.str();
	return s;
}

// Calculate the length of the linesegment using delegation
double LineSegment::Length()
{
	return startPoint.Distance(endPoint);
}