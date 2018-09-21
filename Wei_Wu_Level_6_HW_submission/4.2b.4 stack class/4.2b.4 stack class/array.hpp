#ifndef Array_HPP
#define Array_HPP

#include "point.hpp"
#include <iostream>
#include <stdio.h>

using namespace std;
template<typename T>
class Array
{
protected:
	T* m_data;
	static int m_size;
	//int m_size;
public:
	// Constructors
	Array();
	Array(const int& s);
	Array(const Array<T>& a);

	// Destructor
	~Array() 
	{ 
		cout << "delete array class\n";
		delete[] m_data;
	};

	// Modifiers
	static void SetSize(int size);
	static int GetSize();
	//int Size() const;
	void SetElement(const int& index, const T& p);
	T GetElement(const int& index) const; 

	Array<T>& operator = (const Array<T>& source); // Assignment operator.
	T& operator [] (int index); //  operator.
	const T& operator [] (int index) const; //  operator.
	bool operator == (const Array<T>& a) const; // Equally compare operator.

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
		if (i<0)
		{
			i=0;
		}
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

class ArraySizeException: public ArrayException
{
private:
	int m_index;
public:
	ArraySizeException()
	{
		cout << "construct array exception " << endl;
	};
	//Give the OutOfBoundsException class a constructor with an int as argument that indicates the erroneous array index and store it in a data member
//	ArraySizeException(int i): m_index(i)		
//	{
//		cout << "erroneous array index is " << i << endl;
////		m_index = i;
//	}
	~ArraySizeException()
	{
		cout << "destruct array exception " << endl;
	};
	std::string GetMessage() const
	{
		std::stringstream ss;
		ss << "two arrays have not the same size." ;
		std::string s = ss.str();
		return s;			//return the given index is out of bounds.
	}

};

#ifndef Array_cpp
#include "Array.cpp"
#endif
#endif


