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

	// Accessing functions
	double X() const  ;			// Get the x-coordinate
	double Y() const ;			// Get the y-coordinate

	//modify function
	void SetX(double newX);	// Set the x-coordinate
	void SetY(double newY);	// Set the y-coordinate

    std::string ToString() const ;	//convert the double coordinates to a string

	double DistanceOrigin(); // Calculate the distance to the origin (0, 0).
	double Distance(const Point& p)  ; // Calculate the distance between two points.
};



#endif // Point_H
