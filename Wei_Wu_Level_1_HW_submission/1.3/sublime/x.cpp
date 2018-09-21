#include "x.hpp"
#include <stdio.h>
#include "string.h"
#include <sstring>

using namespace std;

Point::Point()
{
	m_x = 0;
	m_y = 0;
}

double Point::GetX()
{
	return m_x;
}

double Point::GetY()
{
	return m_y;
}

void Point::SetX(double newX)
{
	m_x = newX;
}
void Point::SetY(double newY)
{
	m_y = newY;
}

std::string Point::ToString()
{
	std::stringstream ss;
	ss << "Point(" << m_x << "," << m_y << ")";
	std::string s = ss.str();
	return s;
}

