#ifndef POINT_HPP
#define POINT_HPP
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

class Point
{
private:
	double m_x;	// X coordinate
	double m_y;	// Y coordinate
public:
	// Default constructor
	Point();
	//{
	//	m_x = 0;
	//	m_y = 0;
	//	//cout << "constructor class" << endl;
	//}
	// Constructors
	Point(double xval, double yval);
	
	//deconstructor
	~Point() 
	{		
		//cout << "deconstructor class" << endl;
	};
	
	Point(const Point& p);

	// Accessing functions
	double GetX() const;			// Get the x-coordinate
	double GetY() const;			// Get the y-coordinate

	//modify function
	void SetX(double newX);	// Set the x-coordinate
	void SetY(double newY);	// Set the y-coordinate

    std::string ToString() const;	//convert the double coordinates to a string

	double DistanceOrigin(); // Calculate the distance to the origin (0, 0).
	double Distance(Point p) const; // Calculate the distance between two points.

	//operator overloading
	Point operator - () const; // Negate the coordinates.
	Point operator * (double factor) const; // Scale the coordinates.
	Point operator + (const Point& p) const; // Add coordinates.
	bool operator == (const Point& p) const; // Equally compare operator.
	Point& operator = (const Point& source); // Assignment operator.
	Point& operator *= (double factor); // Scale the coordinates & assign.

};



#endif // Point_H