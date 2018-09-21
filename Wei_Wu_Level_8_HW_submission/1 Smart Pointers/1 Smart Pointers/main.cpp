#include <stdio.h>
#include <string.h>
#include <iostream>
#include "Point.hpp"
#include <sstream>
#include "LineSegment.hpp"
#include "circle.hpp"
#include "Shape.hpp"
#include "array.hpp"
#include "PointArray.hpp"
#include "Stack.hpp"
#include "boost/shared_ptr.hpp"
#include <numeric>

// Simple creator (FACTORY) function
boost::shared_ptr<Shape> createBase()
{

	// In later versions return other derived types
	//boost::shared_ptr<Shape> result(new Point(rand(),rand()));
	boost::shared_ptr<Shape> result(new LineSegment(Point(rand(),rand()),Point(rand(),rand())));

	return result;
}

using namespace std;
int main()
{
	// Use in STL containers
	// Typedef for a shared pointer to shape and
	// a typedef for an array with shapes stored as shared pointers.
	typedef boost::shared_ptr<Shape> ShapePtr;
	typedef Array<ShapePtr> ShapeArray;

	// Create a vector of objects 
	ShapeArray con;
	//const int N = 4;
	//for (int j = 0; j < N; ++j)
	//{
	//	con.SetElement(j,createBase());
	//}
	boost::shared_ptr<Shape> result1(new Point(rand(),rand()));
	boost::shared_ptr<Shape> result2(new LineSegment(Point(rand(),rand()),Point(rand(),rand())));
	boost::shared_ptr<Shape> result3(new Circle(rand(),Point(rand(),rand())));
	con.SetElement(0,result1);
	con.SetElement(1,result2);
	con.SetElement(2,result3);

	for (int j = 0; j < 3; ++j)
	{
		//cout << con.GetElement(j)-> ToString() << endl;
		con.GetElement(j)-> Print();
	}

	return 0;
}