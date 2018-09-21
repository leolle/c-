#ifndef NumericArray_CPP
#define NumericArray_CPP

#include <stdio.h>
#include <string.h>
#include <iostream>
#include "NumericArray.hpp"
#include <sstream>
#include <cmath>
#define _USE_MATH_DEFINES
#include <math.h>


using namespace std;


//template<typename T>
//int Array<T>::m_size = 10;

template<typename T>
NumericArray<T>::NumericArray() :Array<T>()
{
	;
}

template<typename T>
NumericArray<T>::NumericArray(const int& nSize) : Array<T>(nSize)
{
	;
	//m_size = nSize;
	//m_data = new T[m_size];
	////Point* array[size];
	//cout << "construct array class\n";
}
//
//copy constructor
template<typename T>
NumericArray<T>::NumericArray(const NumericArray& a) : Array<T>(a)
{
	for (int i = 0; i < m_size; i++)
	{
		m_data[i] = a.m_data[i];
	}
}
//
//
//assignment constructor
template<typename T>
NumericArray<T>& NumericArray<T>::operator = (const NumericArray<T>& source)
{
	// Avoid doing assign to myself
	if (this == &source)
		return *this;

	Array<T>::operator=(source);		//need to use the shape assignment operator

	return *this;
}



// multiply operator.
template<typename T>
NumericArray<T> NumericArray<T>::operator * (T factor) const 
{
	for (int i = 0; i < m_size; i++)
	{
		m_data[i] = m_data[i]*factor;
	}
	return *this;
}


//add constructor
template<typename T>
NumericArray<T> NumericArray<T>::operator + (const NumericArray<T>& source) const // add operator.
{
	if(m_size != source.m_size)
	{
		throw ArraySizeException();
	} 
	else
	{
		for (int i = 0; i < m_size; i++)
		{
			m_data[i] = m_data[i] + source.m_data[i];
		}
	return *this;
	}
}

//add constructor
template<typename T>
NumericArray<T> NumericArray<T>::operator += (const NumericArray<T>& source) const // add operator.
{
	if(m_size != source.m_size)
	{
		throw ArraySizeException();
	} 
	else
	{
		for (int i = 0; i < m_size; i++)
		{
			m_data[i] = m_data[i] + source.m_data[i];
		}
	return *this;
	}
}

template<typename T>
T  NumericArray<T>::DotProduct(const NumericArray<T>& source) 
{
	T temp = 0;
	if(m_size != source.m_size)
	{
		throw ArraySizeException();
	} 
	else
	{
		for (int i = 0; i < m_size; i++)
		{
			temp = temp + (m_data[i] * source.m_data[i]);
		}
	}
	return temp;
}
//
////return size of NumericArray class
//template<typename T>
//int NumericArray<T>::Size() const
//{
//	return m_size;
//}
//
//
//template<typename T>
//void NumericArray<T>::SetElement(const int& index, const T& p)	//index starts from 0
//{
//	if (index < 0 || index >= m_size)
//	{
//		throw OutOfBoundsException(index);
//	}
//	else
//		m_data[index] = p;
//}
//
//template<typename T>
//T NumericArray<T>::GetElement(const int& index) const
//{
//	if (index < 0 || index >= m_size)
//	{
//		throw OutOfBoundsException(index);
//	}
//	else
//		return m_data[index];		//return by reference.
//}

//template<typename T>
//bool NumericArray<T>::operator == (const NumericArray& a) const // Equally compare operator.
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


//template<typename T>
//T& NumericArray<T>::operator [] (int index) // Assignment operator.
//{
//	if (index < 0 || index >= m_size)
//	{
//		throw OutOfBoundsException(index);
//	}
//	else
//		return m_data[index];
//}
//
////If the Point type is known to be a built-in type, the const variant should return by value.
//template<typename T>
//const T& NumericArray<T>::operator [] (int index) const// Assignment operator.
//{
//	if (index < 0 || index >= Size())
//	{
//		throw OutOfBoundsException(index);
//	}
//	else
//		return m_data[index];
//}
//
//
#endif