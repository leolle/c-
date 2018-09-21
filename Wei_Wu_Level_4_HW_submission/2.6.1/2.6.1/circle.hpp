// LineSegment.hpp
//
// (Finite) line segments in 2 dimensions. This class represents an undirected
// line segment.
// The functionality is basic. If you wish to get more functions then convert the
// line segment to a vector or to a line and use their respective member functions.
//
// This is a good example of Composition (a line segment consists of two points() 
// the Delegation principle. For example, the member fucntion that calculates the 
// length of a line is implemented as the distance function between the line's end
// points.
//
// Stripped version.
//
// (C) Datasim BV 1995-2011
//

#ifndef Circle_HPP
#define Circle_HPP

#include "point.hpp"
#include <iostream>
#include <stdio.h>

using namespace std;
namespace WEIWU
{
	namespace CAD
	{

		class Circle
		{
		private:

			double m_radius;	// radius of the circle
			Point m_center;		// center point of the circle

		public:

			// Constructors
			Circle();									// circle with centre Point at the origin, radius equals to zero
			Circle(const double& r, const Point& p);	// circle with centre Point at the p, radius equals to r
			Circle(const Circle& l); 					// Copy constructor
			virtual ~Circle(){};							// Destructor

			// Accesssing functions
			Point CentrePoint() const;			// get centre point				
			double Radius() const;				// get radius				
			double Diameter() const;			// get diameter				
			double Area() const;				// get area				
			double Circumference() const;		// get circumference						

			// Modifiers
			void CentrePoint(const Point& pt);					// Set centre point 
			void Radius(double rVal);						// Set Radius

			std::string ToString() const;	//convert the double coordinates to a string

			//operator overloading
			Circle& operator = (const Circle& source); // Assignment operator.		  

		};

		ostream& operator << (ostream& os, const Circle& c); // Send to ostream.
	}
}
#endif




