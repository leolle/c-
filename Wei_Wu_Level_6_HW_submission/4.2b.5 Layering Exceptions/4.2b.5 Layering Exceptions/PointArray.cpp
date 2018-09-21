#include <stdio.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <cmath>
#define _USE_MATH_DEFINES
#include <math.h>
#include "PointArray.hpp"


using namespace std;

//default constructor
PointArray::PointArray():Array<Point>() 
{
	;
}

PointArray::PointArray(const int& nSize) : Array<Point>(nSize)
{
	;
	//m_size = nSize;
	//m_data = new T[m_size];
	////Point* array[size];
	//cout << "construct array class\n";
}

//copy constructor
PointArray::PointArray(const PointArray& a) : Array<Point>(a)
{
	for (int i = 0; i < m_size; i++)
	{
		m_data[i] = a.m_data[i];
	}
}


////
////
////assignment constructor
//PointArray& PointArray::operator = (const PointArray& source)
//{
//	// Avoid doing assign to myself
//	if (this == &source)
//		return *this;
//
//	delete[] m_data;					//delete the old C PointArray 
//	m_data = new Point[source.m_size];	// allocate new memory before copying the elements
//	m_size = source.m_size;
//	for (int i = 0; i < m_size; i++)
//	{
//		m_data[i] = source.m_data[i];
//	}
//
//	return *this;
//}
//
//calculate the length of the point array
double PointArray::Length()
{
	double length = 0;
	for (int i = 0; i < m_size-1; i++)
	{
		length += m_data[i].Distance(m_data[i+1]);
	}
	return length;
}

// multiply operator.
//PointArray PointArray::operator * (T factor) const 
//{
//	for (int i = 0; i < m_size; i++)
//	{
//		m_data[i] = m_data[i]*factor;
//	}
//	return *this;
//}
//
//
////add constructor
//PointArray PointArray::operator + (const PointArray& source) const // add operator.
//{
//	if(m_size != source.m_size)
//	{
//		throw ArraySizeException();
//	} 
//	else
//	{
//		for (int i = 0; i < m_size; i++)
//		{
//			m_data[i] = m_data[i] + source.m_data[i];
//		}
//	return *this;
//	}
//}
//
////add constructor
//template<typename T>
//PointArray PointArray::operator += (const PointArray& source) const // add operator.
//{
//	if(m_size != source.m_size)
//	{
//		throw ArraySizeException();
//	} 
//	else
//	{
//		for (int i = 0; i < m_size; i++)
//		{
//			m_data[i] = m_data[i] + source.m_data[i];
//		}
//	return *this;
//	}
//}
//
//template<typename T>
//T  PointArray::DotProduct(const PointArray& source) 
//{
//	T temp = 0;
//	for (int i = 0; i < m_size; i++)
//	{
//		temp = temp + (m_data[i] * source.m_data[i]);
//	}
//	return temp;
//}
