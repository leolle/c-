
#ifndef LineSegment_HPP
#define LineSegment_HPP

#include "point.hpp"
#include <iostream>
#include <stdio.h>

using namespace std;

class LineSegment
{
private:
		
		Point startPoint;	// end of linesegment
		Point endPoint;		// 

public:

	// Constructors
	LineSegment();									// Line with both end Points at the origin
	LineSegment(const Point& p1, const Point& p2);	// Line with end Points [p1, p2]
	LineSegment(const LineSegment& l); 				// Copy constructor
	virtual ~LineSegment();							// Destructor

	// Accesssing functions
	Point start() const;							// Get start point							
	Point end() const;								// Get end point

	// Modifiers
	void start(const Point& pt);					// Set start point pt1
	void end(const Point& pt);						// Set end point pt2
    std::string ToString();							// return the coordinates information of the 2 ends of the linesegment
	double Length();								// Calculate the length of the linesegment

};

#endif




