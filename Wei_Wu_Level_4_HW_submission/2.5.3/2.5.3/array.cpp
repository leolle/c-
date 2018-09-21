#include <stdio.h>
#include <string.h>
#include <iostream>
#include "Point.hpp"
#include "array.hpp"
#include <sstream>
#include "circle.hpp"
#include <cmath>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

Array::Array()
{
	m_data = new Point[10];
	m_size = 10;
}

Array::Array(const int& nSize)
{
	m_size = nSize;
	m_data = new Point[m_size];
	//Point* array[size];
	cout << "construct array class\n";
}

//copy constructor
Array::Array(const Array& a)
{
	m_data = new Point[a.m_size];
	m_size = a.m_size;
	for (int i = 0; i < m_size; i++)
	{
		m_data[i] = a.m_data[i];
	}
}


//assignment constructor
Array& Array::operator = (const Array& source)
{
	// Avoid doing assign to myself
	if (this == &source)
		return *this;

	delete[] m_data;					//delete the old C array 
	m_data = new Point[source.m_size];	// allocate new memory before copying the elements
	m_size = source.m_size;
	for (int i = 0; i < m_size; i++)
	{
		m_data[i] = source.m_data[i];
	}

	return *this;
}

//return size of array class
int Array::Size() const
{
	//if (m_size == 0)
	//{
	//	return 10;
	//} 
	return m_size;
}

void Array::SetElement(const int& index, const Point& p)	//index starts from 0
{
	if ((index + 1) <= m_size)
	{
		m_data[index] = p;
	}
	else
	{
		cout << "out of boundary.\n";
	}
}

Point Array::GetElement(const int& index)
{
	if ((index + 1) <= m_size)
	{
		return m_data[index];		//return by reference.
	} 
	else
	{
		cout << "out of boundary, return the first element.\n";
		return m_data[0];
	}
}

bool Array::operator == (const Array& a) const // Equally compare operator.
{
	if (a.m_size == m_size)
	{
		for (int i = 0; i < m_size; i++)
		{
			if (m_data[i] != a.m_data[i])
			{
				return 0;
			}
		}
		return 1;
	}
	else return 0;
}


Point& Array::operator [] (int index) // Assignment operator.
{
	if ((index + 1) > m_size)
	{
		cout << "Index out of bounds" <<endl; 
		// return first element.
		return m_data[0];
	}
	return m_data[index];
}

//If the Point type is known to be a built-in type, the const variant should return by value.
const Point& Array::operator [] (int index) const// Assignment operator.
{
	if ((index + 1) > m_size)
	{
		cout << "Index out of bounds" <<endl; 
		// return first element.
		return m_data[0];
	}
	return m_data[index];
}
