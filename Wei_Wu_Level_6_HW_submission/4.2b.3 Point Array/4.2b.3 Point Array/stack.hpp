#ifndef Stack_HPP
#define Stack_HPP

#include "Array.hpp"
#include <iostream>
#include <stdio.h>

using namespace std;
template<typename T>
class Stack
{
protected:
	Array<T> cM_data;
	int m_index;
public:
	// Constructors
	Stack();
	Stack(const int& s);
	Stack(const Stack<T>& a);

	// Destructor
	~Stack() 
	{ 
		cout << "delete stack class\n";
	};

	// Modifiers
	void Push(const T& in);
	T Pop();


	Stack<T>& operator = (const Stack<T>& source); // Assignment operator.
	bool operator == (const Stack<T>& a) const; // Equally compare operator.

};

//class ArrayException
//{
//private:
//public:
//	ArrayException()
//	{
//		cout << "construct ArrayException " << endl;
//	};
//	virtual ~ArrayException()
//	{
//		cout << "destruct ArrayException " << endl;
//	};
//	//void GetMessage();
//	virtual std::string GetMessage() const
//	{
//		//std::string sssss;
//		//return sssss;
//		return "Exception in Array class.";
//	}
//	//virtual void get()=0;
//
//
//};
//
//class OutOfBoundsException: public ArrayException
//{
//private:
//	int m_index;
//public:
//	OutOfBoundsException()
//	{
//		cout << "construct outofbound " << endl;
//	};
//	//Give the OutOfBoundsException class a constructor with an int as argument that indicates the erroneous array index and store it in a data member
//	OutOfBoundsException(int i): m_index(i)		
//	{
//		cout << "erroneous array index is " << i << endl;
////		m_index = i;
//	}
//	~OutOfBoundsException()
//	{
//		cout << "destruct outofbound " << endl;
//	};
//	std::string GetMessage() const
//	{
//		std::stringstream ss;
//		ss << "The given index " << m_index << " is out of bound." ;
//		std::string s = ss.str();
//		return s;			//return the given index is out of bounds.
//	}
//
//};
//
//class ArraySizeException: public ArrayException
//{
//private:
//	int m_index;
//public:
//	ArraySizeException()
//	{
//		cout << "construct array exception " << endl;
//	};
//	//Give the OutOfBoundsException class a constructor with an int as argument that indicates the erroneous array index and store it in a data member
////	ArraySizeException(int i): m_index(i)		
////	{
////		cout << "erroneous array index is " << i << endl;
//////		m_index = i;
////	}
//	~ArraySizeException()
//	{
//		cout << "destruct array exception " << endl;
//	};
//	std::string GetMessage() const
//	{
//		std::stringstream ss;
//		ss << "two arrays have not the same size." ;
//		std::string s = ss.str();
//		return s;			//return the given index is out of bounds.
//	}
//
//};

//#ifndef Array_cpp
//#include "Array.cpp"
//#endif
#endif


