#ifndef POINT_HPP
#define POINT_HPP
#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;



class Point
{
private:
	double m_x;	// X coordinate
	double m_y;	// Y coordinate
public:
	// Default constructor
	Point()
	{
		m_x = 0;
		m_y = 0;
		cout << "constructor class" << endl;
	}
	// Constructors
	Point(double xval, double yval);
	
	//deconstructor
	~Point() 
	{		
		cout << "deconstructor class" << endl;
	};


	//Set and Get x,y coordinate can be overloading functions 
	//as only they have same function name along with different return type or input arguments.
	// Accessing functions
	double X() ;			// Get the x-coordinate
	double Y() ;			// Get the y-coordinate

	//modify function
	void X(double newX);	// Set the x-coordinate
	void Y(double newY);	// Set the y-coordinate

    std::string ToString();	//convert the double coordinates to a string

	double Distance(); // Calculate the distance to the origin (0, 0).
	double Distance(Point p); // Calculate the distance between two points.
};



#endif // Point_H
