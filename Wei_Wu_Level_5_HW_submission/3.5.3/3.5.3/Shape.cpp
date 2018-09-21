#include <stdio.h>
#include <string.h>
#include <iostream>
#include "Shape.hpp"
#include "point.hpp"
#include <sstream>

using namespace std;
Shape::Shape()
: m_id(rand())			//initiate m_id with a random number
{
	cout << "default shape constructor " << endl;
}

//copy constructor
Shape::Shape(const Shape& s) 
: m_id(s.m_id)
{
	cout << "copy shape constructor." << endl;
}


// Assignment operator.
Shape& Shape::operator = (const Shape& source)
{
	// Avoid doing assign to myself
	if (this == &source)
		return *this;

	m_id = source.m_id;

	return *this;
}


string Shape::ToString() const	//convert the double coordinates to a string
{
	std::stringstream ss;
	ss << "ID: " << m_id << ".";
	std::string s = ss.str();
	return s;
}

// Access function
int Shape::ID()					
{
	return m_id;
}


//
void Shape::Draw()
{
	cout << "----draw shape function----" << endl;
}