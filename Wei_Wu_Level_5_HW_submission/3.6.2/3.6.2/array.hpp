#ifndef Array_HPP
#define Array_HPP

#include "point.hpp"
#include <iostream>
#include <stdio.h>

using namespace std;

class Array
{
private:
	Point* m_data;
	int m_size;
public:
	// Constructors
	Array();
	Array(const int& s);
	Array(const Array& a);

	// Destructor
	~Array() 
	{ 
		cout << "delete array class\n";
		delete[] m_data;
	};

	// Modifiers
	int Size() const;
	void SetElement(const int& index, const Point& p);
	Point GetElement(const int& index) const; 

	Array& operator = (const Array& source); // Assignment operator.
	Point& operator [] (int index); // Assignment operator.
	const Point& operator [] (int index) const; // Assignment operator.
	bool operator == (const Array& a) const; // Equally compare operator.

};

class ArrayException
{
private:
public:
	ArrayException()
	{
		cout << "construct ArrayException " << endl;
	};
	virtual ~ArrayException()
	{
		cout << "destruct ArrayException " << endl;
	};
	//void GetMessage();
	virtual std::string GetMessage() const
	{
		//std::string sssss;
		//return sssss;
		return "Exception in Array class.";
	}
	//virtual void get()=0;


};

class OutOfBoundsException: public ArrayException
{
private:
	int m_index;
public:
	OutOfBoundsException()
	{
		cout << "construct outofbound " << endl;
	};
	//Give the OutOfBoundsException class a constructor with an int as argument that indicates the erroneous array index and store it in a data member
	OutOfBoundsException(int i): m_index(i)		
	{
		cout << "erroneous array index is " << i << endl;
//		m_index = i;
	}
	~OutOfBoundsException()
	{
		cout << "destruct outofbound " << endl;
	};
	std::string GetMessage() const
	{
		std::stringstream ss;
		ss << "The given index " << m_index << " is out of bound." ;
		std::string s = ss.str();
		return s;			//return the given index is out of bounds.
	}

};

#endif


