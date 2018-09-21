#ifndef VISITOR_HPP
#define VISITOR_HPP
#include <iostream>
#include <string>
#include "Point.hpp"
#include "LineSegment.hpp"
#include "circle.hpp"
#include "Shape.hpp"
#include "array.hpp"
#include "PointArray.hpp"
#include <boost/variant.hpp>

using namespace std;

class ShapeTypeVisitor : public boost::static_visitor<void>
{
private:
	double x_offset, y_offset;
public:
	ShapeTypeVisitor();
	ShapeTypeVisitor(double xval, double yval);
	// Visit a point.
	void operator()(Point& p) const;
	//~ShapeTypeVisitor();
	// Visit a linesegment.
	void operator () (LineSegment& line) const;

	// Visit a Circle.
	void operator () (Circle& c) const;

};

#endif // Point_H
