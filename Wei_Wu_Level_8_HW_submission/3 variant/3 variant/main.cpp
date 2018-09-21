#include <iostream>
#include <string>
#include "Point.hpp"
#include "LineSegment.hpp"
#include "circle.hpp"
#include "Shape.hpp"
#include "array.hpp"
#include "PointArray.hpp"
#include "visitor.hpp"
#include <boost/variant.hpp>

using namespace std;

typedef boost::variant<Point, LineSegment, Circle> ShapeType;
ShapeType CreateShape()
{
	int i;
	std::cout << "Choose which shape to create: 1 Point, 2 LineSegment, 3 Circle (it creates all the shapes with default constructor)" << std::endl;
	std::cin >> i;
	ShapeType temp;
	switch (i)
	{
		//create all the shapes with default constructor
	case 1: 
		{
		Point cP1;
		temp = cP1;
		break;
		}
	case 2: 
		{
		LineSegment cLine;
		temp = cLine;
		break;
		}
	case 3: 
		{
		Circle cCir;
		temp = cCir;
		break;
		}
	default:
		break;
	}
	return temp;
}


int main()
{
     // Using declaration, for readability purposes
     using boost::variant;
	 ShapeType variant_shape;
	 variant_shape = CreateShape();
	 cout << variant_shape << endl;

	 // Try to assign the variant to a Line variable
	 LineSegment cLine2;
	 try
	 {
		 cLine2 = boost::get<LineSegment>(variant_shape); // won't work, wrong type
	 }
	 catch (boost::bad_get& err)
	 {
		cout << "Error: " << err.what() << endl;
	 }
	 Point p1;
	 ShapeType variant_shape1 = p1;
	 cout << variant_shape1 << endl;
	 //create an instance of the visitor and use the boost::apply_visitor(visitor, variant) global function to move the shape. 
	 ShapeTypeVisitor visitor(1.1 , 1.1);
	 boost::apply_visitor( visitor, variant_shape );
	 cout << variant_shape << endl;


     return 0;
}
