#include "visitor.hpp"
ShapeTypeVisitor::ShapeTypeVisitor():x_offset(0),y_offset(0)
{
}

ShapeTypeVisitor::ShapeTypeVisitor(double xval, double yval):x_offset(xval),y_offset(yval)
{
}

void ShapeTypeVisitor::operator()(Point& p) const
{
	p.SetX(p.GetX()+x_offset);
	p.SetY(p.GetY()+y_offset);
}

void ShapeTypeVisitor::operator()(LineSegment& line) const
{
	Point x(line.start());		//get the start point of linesegment
	x.SetX(x.GetX()+x_offset);
	x.SetY(x.GetY()+y_offset);
	line.start(x);				//modify the start point
	Point y(line.end());		//get the end point of linesegment
	y.SetX(y.GetX()+x_offset);
	y.SetY(y.GetY()+y_offset);
	line.end(y);				//modify the end point
}

void ShapeTypeVisitor::operator()(Circle& c) const
{
	Point cc(c.CentrePoint());	//get the centre point of the circle
	cc.SetX(cc.GetX()+x_offset);
	cc.SetY(cc.GetY()+y_offset);
	c.CentrePoint(cc);			//modify the centre point of the circle
}
