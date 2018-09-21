// MP Implementation of the Line segment .cpp

#include "LineSegment.hpp"
#include <cmath>

/*	LineSegment();																// Line with both end Points at the origin
	LineSegment(const Point& p1, const Point& p2);	// Line with end Points [p1, p2]
	LineSegment(const LineSegment& l); 							// Copy constructor
	virtual ~LineSegment();													// Destructor

	// Accesssing functions
	Point start() const;														// Synonym for startPoint
	Point end() const;															// Synonym for endPoint

	// Modifiers
	void start(const Point& pt);										// Set Point pt1
	void end(const Point& pt);											// Set Point pt2

	// Arithemetic
	double length() const;													// Length of line

	// Interaction with Points
	Point midPoint() const;	

	*/

LineSegment::LineSegment() 
{
	//!!!
}

LineSegment::~LineSegment()
{
//	cout << "destructor linesegment class." << endl;

}

LineSegment::LineSegment(const Point& p1, const Point& p2) 
{
	startPoint=p1;
	endPoint=p2;
//	cout << "constructor linesegment class with arguments, colon syntax." << endl;
}

LineSegment::LineSegment(const LineSegment& l) : startPoint(l.startPoint), endPoint(l.endPoint)
{
	//startPoint=l.startPoint;
	//endPoint=l.endPoint;
//	cout << "copy constructor linesegment class, colon syntax." << endl;
}

Point LineSegment::start() const
{
	return startPoint;
}

Point LineSegment::end() const
{
	return endPoint;
}

void LineSegment::start(const Point& pt)
{
	startPoint=pt;
}

void LineSegment::end(const Point& pt)
{
	endPoint=pt;
}

string LineSegment::ToString() const	//convert the double coordinates to a string
{
	std::stringstream ss;
	ss << "End 1: " << startPoint.ToString() << ", " << "End 2: "<< endPoint.ToString() << ".";
	std::string sss = Shape::ToString();
	std::string s = ss.str();
	return sss + s;			//return the ID from the shape and linesegment points.
}

double LineSegment::Length()  const
{
	return startPoint.Distance(endPoint);
}

// Assignment operator.
LineSegment& LineSegment::operator = (const LineSegment& source)
{
	// Avoid doing assign to myself
	if (this == &source)
		return *this;
	Shape::operator=(source);		//need to use the shape assignment operator

	startPoint = source.startPoint;
	endPoint = source.endPoint;

	return *this;
}


ostream& operator << (ostream& os, const LineSegment& l) // Send to ostream.
{
	Point start_temp = l.start(), end_temp=l.end();

	os << "End 1: Point(" << start_temp.GetX() << "," << start_temp.GetY() << ") , End 2: Point(" << end_temp.GetX() << "," << end_temp.GetY() << ").";
	return os;
}

