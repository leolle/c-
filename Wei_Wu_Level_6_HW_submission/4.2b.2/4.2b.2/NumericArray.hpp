#ifndef NumericArray_HPP
#define NumericArray_HPP

#include <iostream>
#include <stdio.h>
#include "Array.hpp"

using namespace std;

//template class<T> class NumericArray : public Array	//derived from shape, access specifier public
template<typename T> 
class NumericArray : public Array<T>	//derived from shape, access specifier public
{
private:

public:

	// Constructors
	NumericArray();									// default constructor
	NumericArray(const int& nSize);	// 
	NumericArray(const NumericArray& l); 					// Copy constructor
	virtual ~NumericArray()
	{
		//cout << "destructor circle class" << endl;
	};							// Destructor

	// Accesssing functions
	// dot function
	T DotProduct(const NumericArray<T>& source) ;
	// Modifiers

	//operator overloading
	NumericArray<T> operator + (const NumericArray<T>& source) const; // add operator.
	NumericArray<T> operator += (const NumericArray<T>& source) const; // add operator.
	NumericArray<T> operator * (T factor) const; // multiply operator.
	NumericArray<T>& operator = (const NumericArray<T>& source); // Assignment operator.

};

template<typename T>
ostream& operator << (ostream& os, const NumericArray<T>& c); // Send to ostream.
#ifndef NumericArray_cpp
#include "NumericArray.cpp"
#endif

#endif




