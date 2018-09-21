#ifndef POINT_HPP
#define POINT_HPP
#include <stdio.h>
#include <iostream>
using namespace std;



class Point
{
private:
	double m_x;	// X coordinate
	double m_y;	// Y coordinate

public:
	// Default constructor
	Point();

	// Constructors
	Point(double xval, double yval);
	
	//deconstructor
	~Point() {};

	// Accessing functions
	double GetX() ;			// Get the x-coordinate
	double GetY() ;			// Get the y-coordinate

	//inline modify function
	void SetX(double newX) {	m_x = newX;
};	// Set the x-coordinate
	void SetY(double newY) {	m_y = newY;
};	// Set the y-coordinate
    std::string ToString();	//convert the double coordinates to a string

};

//inline getters
inline double Point::GetX()
{
	return m_x;
}

inline double Point::GetY()			
{ 
	return m_y;
} 					

#endif // Point_H
