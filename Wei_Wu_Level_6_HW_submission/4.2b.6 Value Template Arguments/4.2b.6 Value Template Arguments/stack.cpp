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

template<typename T, int size>
Stack<T,size>::Stack():m_current(0),cM_data(size)
{
	//cM_data(size);
	//cM_data.SetSize(size);
}

//copy constructor
template<typename T, int size>
Stack<T,size>::Stack(const Stack<T,size>& a):cM_data(a.cM_data),m_current(a.m_current)
{
	//cM_data = a.cM_data;
	//m_current = a.m_current;
}

template<typename T, int size>
void Stack<T,size>::Push(const T& in)
{
	try
	{
		cM_data.SetElement(m_current, in);
		m_current++;	//current index is not changed when the Array class threw an
						//exception 
	}
	catch(ArrayException &cException)	//catching the ArrayException base class.
	{
		throw StackFullException();		//the array exception is translated to a stack exception
        cout << "In catch handler." << endl;
        cout << "Caught cArray exception type: ";
        cout << cException.GetMessage() << endl; //to display an error message.
	}
}

template<typename T, int size>
T Stack<T,size>::Pop()
{
	try
	{
		m_current--;
		return cM_data.GetElement(m_current);
	}
	catch(ArrayException &cException)	//catching the ArrayException base class.
	{
		throw StackEmptyException();	//the array exception is translated to a stack exception
        cout << "In catch handler." << endl;
        cout << "Caught cArray exception type: ";
        cout << cException.GetMessage() << endl; //to display an error message.
	}
}
//assignment constructor
template<typename T, int size>
Stack<T,size>& Stack<T,size>::operator = (const Stack<T,size>& source)
{
	// Avoid doing assign to myself
	if (this == &source)
		return *this;

	cM_data = source.cM_data;	// allocate new memory before copying the elements
	m_current = source.m_current;

	return *this;
}


//template<typename T>
//bool Stack<T>::operator == (const Stack<T>& a) const // Equally compare operator.
//{
//	if (a.m_size == m_size)
//	{
//		for (int i = 0; i < m_size; i++)
//		{
//			if (m_data[i] != a.m_data[i])
//			{
//				return 0;
//			}
//		}
//		return 1;
//	}
//	else return 0;
//}



#endif