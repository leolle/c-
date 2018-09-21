#ifndef Pt_HPP
#define Pt_HPP
#include <iostream>


class Point
{
private:
	double m_x;
	double m_y;

public:
	Point();
	~Point();
	
	double GetX();
	double GetY();

	void SetX(double newX);
	void SetY(double newY);

	std::string ToString();
};