#ifndef Stack_CPP
#define Stack_CPP

#include <stdio.h>
#include <string.h>
#include <iostream>
#include "Point.hpp"
#include "Stack.hpp"
#include <sstream>
#include <cmath>
#define _USE_MATH_DEFINES
#include <math.h>


using namespace std;

template<typename T>
Stack<T>::Stack():cM_data(Array<T>),m_index(0)
{

}

template<typename T>
Stack<T>::Stack(const int& s):cM_data(Array<T>(size)),m_index(0)        
{

}
//copy constructor
template<typename T>
Stack<T>::Stack(const Stack<T>& a)
{
	cM_data = a.cM_data;
	m_index = a.m_index;
}

template<typename T>
void Stack<T>::Push(const T& in)
{
	cM_data.SetElement(m_index, in);
	m_index++;
}

template<typename T>
T Stack<T>::Pop()
{
	m_index--;
	return cM_data.GetElement(m_index);
}
//assignment constructor
template<typename T>
Stack<T>& Stack<T>::operator = (const Stack<T>& source)
{
	// Avoid doing assign to myself
	if (this == &source)
		return *this;

	cM_data = source.cM_data;	// allocate new memory before copying the elements
	m_index = source.m_index;

	return *this;
}


template<typename T>
bool Stack<T>::operator == (const Stack<T>& a) const // Equally compare operator.
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



#endif